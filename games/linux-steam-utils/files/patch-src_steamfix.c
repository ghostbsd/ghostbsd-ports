--- src/steamfix.c.orig	2026-09-23 21:58:08 UTC
+++ src/steamfix.c
@@ -439,3 +439,178 @@ int pipe2(int pipefd[2], int flags) {
 
   return libc_pipe2(pipefd, flags & ~O_DIRECT);
 }
+
+/*
+  FreeBSD returns EAGAIN instead of 0 when reading an empty FIFO that no writer has opened yet.
+  Steam then stops reading steam.pipe and ignores URLs (steam://rungameid/N) from a second instance.
+*/
+
+#include <stdarg.h>
+
+static int steam_pipe_fd = -1;
+
+static bool is_steam_pipe(const char* path) {
+  const char* name = strrchr(path, '/');
+  return strcmp(name ? name + 1 : path, "steam.pipe") == 0;
+}
+
+static mode_t open_mode(int flags, va_list ap) {
+  return (flags & O_CREAT) ? va_arg(ap, mode_t) : 0;
+}
+
+static int (*libc_open  )(const char*, int, ...) = NULL;
+static int (*libc_open64)(const char*, int, ...) = NULL;
+
+int open(const char* path, int flags, ...) {
+
+  if (!libc_open) {
+    libc_open = dlsym(RTLD_NEXT, "open");
+  }
+
+  va_list ap;
+  va_start(ap, flags);
+  mode_t mode = open_mode(flags, ap);
+  va_end(ap);
+
+  int fd = libc_open(path, flags, mode);
+  if (fd >= 0 && is_steam_pipe(path)) {
+    steam_pipe_fd = fd;
+  }
+  return fd;
+}
+
+int open64(const char* path, int flags, ...) {
+
+  if (!libc_open64) {
+    libc_open64 = dlsym(RTLD_NEXT, "open64");
+  }
+
+  va_list ap;
+  va_start(ap, flags);
+  mode_t mode = open_mode(flags, ap);
+  va_end(ap);
+
+  int fd = libc_open64(path, flags, mode);
+  if (fd >= 0 && is_steam_pipe(path)) {
+    steam_pipe_fd = fd;
+  }
+  return fd;
+}
+
+static ssize_t (*libc_read)(int, void*, size_t) = NULL;
+
+ssize_t read(int fd, void* buf, size_t count) {
+
+  if (!libc_read) {
+    libc_read = dlsym(RTLD_NEXT, "read");
+  }
+
+  ssize_t n = libc_read(fd, buf, count);
+  if (n == -1 && errno == EAGAIN && fd == steam_pipe_fd) {
+    return 0;
+  }
+  return n;
+}
+
+static int (*libc_close)(int) = NULL;
+
+int close(int fd) {
+
+  if (!libc_close) {
+    libc_close = dlsym(RTLD_NEXT, "close");
+  }
+
+  if (fd == steam_pipe_fd) {
+    steam_pipe_fd = -1;
+  }
+  return libc_close(fd);
+}
+
+/*
+  Linux records the caller as a semaphore's sempid on SETVAL and SETALL, FreeBSD only on semop.
+  Steam takes a sempid of 0 for a semaphore left by a dead instance and recreates it,
+  leaving its other threads and processes with a removed ID (EINVAL).
+*/
+
+#include <sys/sem.h>
+
+union lsu_semun {
+  int                 val;
+  struct semid_ds*    buf;
+  unsigned short*     array;
+};
+
+static int (*libc_semctl)(int, int, int, ...) = NULL;
+
+static void set_sempid(int semid, int semnum) {
+  struct sembuf ops[2] = {
+    { .sem_num = semnum, .sem_op =  1, .sem_flg = IPC_NOWAIT },
+    { .sem_num = semnum, .sem_op = -1, .sem_flg = IPC_NOWAIT }
+  };
+  int saved_errno = errno;
+  semop(semid, ops, 2);
+  errno = saved_errno;
+}
+
+int semctl(int semid, int semnum, int cmd, ...) {
+
+  if (!libc_semctl) {
+    libc_semctl = dlsym(RTLD_NEXT, "semctl");
+  }
+
+  union lsu_semun arg = { 0 };
+  switch (cmd & 0xff) {
+    case SETVAL: case SETALL: case GETALL: case IPC_STAT: case IPC_SET:
+    case IPC_INFO: case SEM_INFO: case SEM_STAT: {
+      va_list ap;
+      va_start(ap, cmd);
+      arg = va_arg(ap, union lsu_semun);
+      va_end(ap);
+    }
+  }
+
+  int ret = libc_semctl(semid, semnum, cmd, arg);
+  if (ret == -1) {
+    return ret;
+  }
+
+  if ((cmd & 0xff) == SETVAL) {
+    set_sempid(semid, semnum);
+  } else if ((cmd & 0xff) == SETALL) {
+    struct semid_ds ds;
+    if (libc_semctl(semid, 0, IPC_STAT, &ds) == 0) {
+      for (unsigned long i = 0; i < ds.sem_nsems; i++) {
+        set_sempid(semid, i);
+      }
+    }
+  }
+
+  return ret;
+}
+
+/*
+  With /home nullfs-mounted under compat.linux.emul_path, getcwd() returns that prefix,
+  which does not exist in the runtime chroot, so steamwebhelper can't find steamui.
+*/
+
+#include <sys/stat.h>
+
+static char* (*libc_getcwd)(char*, size_t) = NULL;
+
+char* getcwd(char* buf, size_t size) {
+
+  if (!libc_getcwd) {
+    libc_getcwd = dlsym(RTLD_NEXT, "getcwd");
+  }
+
+  char* cwd = libc_getcwd(buf, size);
+  if (cwd && strncmp(cwd, "/compat/", sizeof("/compat/") - 1) == 0) {
+    char* rest = strchr(cwd + sizeof("/compat/") - 1, '/');
+    struct stat64 a, b;
+    if (rest && stat64(cwd, &a) == 0 && stat64(rest, &b) == 0 && a.st_dev == b.st_dev && a.st_ino == b.st_ino) {
+      memmove(cwd, rest, strlen(rest) + 1);
+    }
+  }
+
+  return cwd;
+}

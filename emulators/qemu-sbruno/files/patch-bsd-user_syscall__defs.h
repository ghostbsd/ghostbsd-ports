--- bsd-user/syscall_defs.h.orig	2019-03-18 23:38:22 UTC
+++ bsd-user/syscall_defs.h
@@ -411,14 +411,17 @@ struct target_freebsd__wrusage {
 #define CMSG_ALIGN(len) (((len)+sizeof(long)-1) & ~(sizeof(long)-1))
 #endif
 
+/*
+ * sys/socket.h
+ */
 struct target_msghdr {
-    abi_long    msg_name;       /* So cket name */
+    abi_long    msg_name;       /* Socket name */
     int32_t     msg_namelen;    /* Length of name */
     abi_long    msg_iov;        /* Data blocks */
-    abi_long    msg_iovlen;     /* Number of blocks */
+    int32_t     msg_iovlen;     /* Number of blocks */
     abi_long    msg_control;    /* Per protocol magic
                                    (eg BSD file descriptor passing) */
-    abi_long    msg_controllen; /* Length of cmsg list */
+    uint32_t     msg_controllen; /* Length of cmsg list */
     int32_t     msg_flags;      /* flags on received message */
 };
 
@@ -433,7 +436,7 @@ struct target_in_addr {
 };
 
 struct target_cmsghdr {
-    abi_long    cmsg_len;
+    uint32_t    cmsg_len;
     int32_t     cmsg_level;
     int32_t     cmsg_type;
 };
@@ -454,10 +457,10 @@ static inline struct target_cmsghdr *__target_cmsg_nxt
     struct target_cmsghdr *__ptr;
 
     __ptr = (struct target_cmsghdr *)((unsigned char *) __cmsg +
-        TARGET_CMSG_ALIGN(tswapal(__cmsg->cmsg_len)));
+        TARGET_CMSG_ALIGN(tswap32(__cmsg->cmsg_len)));
     if ((unsigned long)((char *)(__ptr+1) -
         (char *)(size_t)tswapal(__mhdr->msg_control)) >
-        tswapal(__mhdr->msg_controllen)) {
+        tswap32(__mhdr->msg_controllen)) {
         /* No more entries.  */
         return (struct target_cmsghdr *)0;
     }

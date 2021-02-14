--- src/nvidia-modeset/nvidia-modeset-freebsd.c.orig	2020-10-22 03:03:42.000000000 -0300
+++ src/nvidia-modeset/nvidia-modeset-freebsd.c	2020-12-02 22:07:55.849789000 -0400
@@ -26,6 +26,7 @@
 #include <sys/file.h>
 #include <sys/proc.h>
 #include <sys/stack.h>
+#include <sys/sysproto.h>
 
 #include "nvkms-ioctl.h"
 #include "nvidia-modeset-os-interface.h"
@@ -51,6 +52,7 @@
     #include "machine/../linux32/linux32_proto.h"
   #endif
   #include <compat/linux/linux_ioctl.h>
+  #include <compat/linux/linux_util.h>
 #endif
 
 
@@ -252,7 +254,12 @@ struct nvkms_ref_ptr {
 
 struct nvkms_ref_ptr* NVKMS_API_CALL nvkms_alloc_ref_ptr(void *ptr)
 {
-    struct nvkms_ref_ptr *ref_ptr = nvkms_alloc(sizeof(*ref_ptr), NV_FALSE);
+    /*
+     * Initialize memory to avoid spurious "lock re-initialization" errors.
+     * A little more detail can be found in the PR 201340 starting around
+     * comment #50.
+     */
+    struct nvkms_ref_ptr *ref_ptr = nvkms_alloc(sizeof(*ref_ptr), NV_TRUE);
     if (ref_ptr) {
         mtx_init(&ref_ptr->lock, "nvkms-ref-ptr-lock", NULL, MTX_SPIN);
         // The ref_ptr owner counts as a reference on the ref_ptr itself.
@@ -584,7 +586,7 @@
 #if __FreeBSD_version >= 1100012
   #include <sys/capsicum.h>
 #else
-  #include <sys/capability.h>
+  #include <sys/capsicum.h>
 #endif
 
 /*
@@ -890,29 +892,31 @@
  *************************************************************************/
 
 #if defined(NVKMS_SUPPORT_LINUX_COMPAT)
-
+static struct linux_device_handler nvkms_linux_device_handler = {
+    .bsd_driver_name = "nvidia-modeset",
+    .linux_driver_name = "nvidia-modeset",
+    .bsd_device_name = "nvidia-modeset",
+    .linux_device_name = "nvidia-modeset",
+    .linux_major = 195,
+    .linux_minor = 254,
+    .linux_char_device = 1
+};
 static int nvkms_linux_ioctl_function(
     struct thread *td,
     struct linux_ioctl_args *args
 )
 {
-    struct file *fp;
-    int status;
-    u_long cmd;
+    static const uint32_t dir[4] = { IOC_VOID, IOC_IN, IOC_OUT, IOC_INOUT };
 
-    cap_rights_t rights;
-    status = fget(td, args->fd, cap_rights_init(&rights, CAP_IOCTL), &fp);
+    if ((args->cmd & (1<<29)) != 0) {
+        /* FreeBSD has only 13 bits to encode the size. */
+        printf("nvidia: pid %d (%s): ioctl cmd=0x%x size too large\n",
+            (int)td->td_proc->p_pid, td->td_proc->p_comm, args->cmd);
+        return (EINVAL);
+     }
 
-    if (status != 0) {
-        return status;
-    }
-
-    cmd = args->cmd;
-
-    status = fo_ioctl(fp, cmd, (caddr_t)args->arg, td->td_ucred, td);
-    fdrop(fp, td);
-
-    return status;
+    args->cmd = (args->cmd & ~IOC_DIRMASK) | dir[args->cmd >> 30];
+    return (sys_ioctl(td, (struct ioctl_args *)args));
 }
 
 #define NVKMS_LINUX_IOCTL_MIN _IOC(0, NVKMS_IOCTL_MAGIC, NVKMS_IOCTL_CMD, 0)
@@ -928,6 +932,7 @@
 static void nvkms_linux_compat_load(void)
 {
 #if defined(NVKMS_SUPPORT_LINUX_COMPAT)
+    linux_device_register_handler(&nvkms_linux_device_handler);
     linux_ioctl_register_handler(&nvkms_linux_ioctl_handler);
 #endif
 }
@@ -936,6 +941,7 @@
 {
 #if defined(NVKMS_SUPPORT_LINUX_COMPAT)
     linux_ioctl_unregister_handler(&nvkms_linux_ioctl_handler);
+    linux_device_unregister_handler(&nvkms_linux_device_handler);
 #endif
 }
 
@@ -1119,4 +1125,10 @@
 MODULE_DEPEND(nvidia_modeset,               /* module name */
               linux,                        /* prerequisite module */
               1, 1, 1);                     /* vmin, vpref, vmax */
+#if defined(NVCPU_X86_64)
+MODULE_DEPEND(nvidia_modeset,               /* module name */
+              linux_common,                 /* prerequisite module */
+              1, 1, 1);                     /* vmin, vpref, vmax */
 #endif
+#endif
+

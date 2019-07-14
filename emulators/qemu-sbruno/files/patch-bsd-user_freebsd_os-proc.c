--- bsd-user/freebsd/os-proc.c.orig	2019-07-14 00:48:12 UTC
+++ bsd-user/freebsd/os-proc.c
@@ -82,7 +82,7 @@ out:
     return ret;
 }
 
-#if defined(__FreeBSD_version) && __FreeBSD_version < 1100000
+#if defined(__FreeBSD_version)
 static int
 is_target_shell_script(int fd, char *interp, size_t size, char **interp_args)
 {

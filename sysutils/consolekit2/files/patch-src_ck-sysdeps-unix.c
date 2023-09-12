--- src/ck-sysdeps-unix.c.orig	2022-08-26 23:08:43 UTC
+++ src/ck-sysdeps-unix.c
@@ -328,7 +328,7 @@ ck_get_a_console_fd (void)
         }
 #endif
 
-
+#if 0
 #ifdef _PATH_TTY
         fd = ck_open_a_console (_PATH_TTY);
         if (fd >= 0) {
@@ -345,7 +345,7 @@ ck_get_a_console_fd (void)
 	if (fd >= 0) {
 		goto done;
 	}
-
+#endif
 #ifdef _PATH_CONSOLE
         fd = ck_open_a_console (_PATH_CONSOLE);
         if (fd >= 0) {

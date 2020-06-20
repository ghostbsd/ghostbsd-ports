--- gio/gunixmount.c.orig	2020-05-20 10:46:43 UTC
+++ gio/gunixmount.c
@@ -356,12 +356,22 @@ g_unix_mount_eject (GMount             *mount,
                     gpointer             user_data)
 {
   GUnixMount *unix_mount = G_UNIX_MOUNT (mount);
+#ifdef __FreeBSD__
+  char *argv[] = {"cdcontrol", "-f", NULL, "eject", NULL};
+
+  if (unix_mount->mount_path != NULL)
+    argv[2] = unix_mount->mount_path;
+  else
+    argv[2] = unix_mount->device_path;
+#else
+
   char *argv[] = {"eject", NULL, NULL};
 
   if (unix_mount->mount_path != NULL)
     argv[1] = unix_mount->mount_path;
   else
     argv[1] = unix_mount->device_path;
+#endif
 
   eject_unmount_do (mount, cancellable, callback, user_data, argv);
 }

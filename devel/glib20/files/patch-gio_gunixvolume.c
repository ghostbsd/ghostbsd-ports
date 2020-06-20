--- gio/gunixvolume.c.orig	2020-06-15 12:26:27 UTC
+++ gio/gunixvolume.c
@@ -365,9 +365,15 @@ g_unix_volume_eject (GVolume             *volume,
                      gpointer             user_data)
 {
   GUnixVolume *unix_volume = G_UNIX_VOLUME (volume);
+#ifdef __FreeBSD__
+  const gchar *argv[] = { "cdcontrol", "-f", NULL, NULL };
+
+  argv[2] = unix_volume->device_path;
+#else
   const gchar *argv[] = { "eject", NULL, NULL };
 
   argv[1] = unix_volume->device_path;
+#endif
 
   eject_mount_do (volume, cancellable, callback, user_data, argv);
 }

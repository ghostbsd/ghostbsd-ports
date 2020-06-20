--- gio/tests/desktop-app-info.c.orig	2020-05-20 10:46:43 UTC
+++ gio/tests/desktop-app-info.c
@@ -80,9 +80,9 @@ test_delete (void)
 
   g_object_unref (info);
 
-  if (g_file_test ("/usr/share/applications/gedit.desktop", G_FILE_TEST_EXISTS))
+  if (g_file_test ("%%LOCALBASE%%/applications/gedit.desktop", G_FILE_TEST_EXISTS))
     {
-      info = (GAppInfo*)g_desktop_app_info_new_from_filename ("/usr/share/applications/gedit.desktop");
+      info = (GAppInfo*)g_desktop_app_info_new_from_filename ("%%LOCALBASE%%/share/applications/gedit.desktop");
       g_assert_nonnull (info);
      
       res = g_app_info_can_delete (info);

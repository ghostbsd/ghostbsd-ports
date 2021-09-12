--- modules/stream_filter/prefetch.c
+++ modules/stream_filter/prefetch.c
@@ -534,7 +534,7 @@ vlc_module_begin()
     add_integer("prefetch-buffer-size", 1 << 14, N_("Buffer size"),
                 N_("Prefetch buffer size (KiB)"), false)
         change_integer_range(4, 1 << 20)
-    add_integer("prefetch-read-size", 1 << 24, N_("Read size"),
+    add_integer("prefetch-read-size", 1 << 23, N_("Read size"),
                 N_("Prefetch background read size (bytes)"), true)
         change_integer_range(1, 1 << 29)
     add_integer("prefetch-seek-threshold", 1 << 14, N_("Seek threshold"),

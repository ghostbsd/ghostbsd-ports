--- libs/mysql/gtid/tag_plain.h.orig	2026-06-03 12:21:17 UTC
+++ libs/mysql/gtid/tag_plain.h
@@ -28,6 +28,7 @@
 #include <cstring>
 #include <memory>
 #include <string>
+#include <type_traits>
 
 #include "mysql/gtid/gtid_constants.h"  // tag_max_length
 

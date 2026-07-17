--- src/base64.h.orig	2026-07-12 06:06:01 UTC
+++ src/base64.h
@@ -18,6 +18,7 @@
 #ifndef BASE64_H
 #define BASE64_H
 
+#include <stdbool.h>
 #include <stddef.h>
 typedef size_t idx_t;
 

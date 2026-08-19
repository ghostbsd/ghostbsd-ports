--- include/renderdoc_app.h.orig	2026-07-01 14:16:13 UTC
+++ include/renderdoc_app.h
@@ -35,7 +35,7 @@
 
 #if defined(WIN32) || defined(__WIN32__) || defined(_WIN32) || defined(_MSC_VER)
 #define RENDERDOC_CC __cdecl
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #define RENDERDOC_CC
 #elif defined(__APPLE__)
 #define RENDERDOC_CC

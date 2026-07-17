* Skip the detection of root rights requirement, the assumption that presence
* of KMS drivers removes the root requirement is only valid for Linux
*
--- hw/xfree86/xorg-wrapper.c.orig	2026-07-08 01:35:09 UTC
+++ hw/xfree86/xorg-wrapper.c
@@ -191,7 +191,7 @@ int main(int argc, char *argv[])
 
 int main(int argc, char *argv[])
 {
-#ifdef WITH_LIBDRM
+#if defined(WITH_LIBDRM) && defined(__linux__)
     struct drm_mode_card_res res;
 #endif
     char buf[PATH_MAX];
@@ -230,7 +230,7 @@ int main(int argc, char *argv[])
         }
     }
 
-#ifdef WITH_LIBDRM
+#if defined(WITH_LIBDRM) && defined(__linux__)
     /* Detect if we need root rights, except when overridden by the config */
     if (needs_root_rights == -1) {
         for (i = 0; i < 16; i++) {

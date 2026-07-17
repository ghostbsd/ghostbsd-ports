--- src/include/platform.h.orig	2026-07-07 11:14:06 UTC
+++ src/include/platform.h
@@ -183,8 +183,12 @@
 
 /* FreeBSD_kernel is not defined on the now discontinued kFreeBSD  */
 #if defined(BSD) && defined(__FreeBSD__) && defined(__FreeBSD_kernel__)
+#ifndef __BYTE_ORDER
 #define __BYTE_ORDER BYTE_ORDER
+#endif
+#ifndef __BIG_ENDIAN
 #define __BIG_ENDIAN BIG_ENDIAN
+#endif
 #endif
 
 #ifdef DARWIN

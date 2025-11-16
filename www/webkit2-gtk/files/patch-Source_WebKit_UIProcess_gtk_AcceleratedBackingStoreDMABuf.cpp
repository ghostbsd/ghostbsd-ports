--- Source/WebKit/UIProcess/gtk/AcceleratedBackingStoreDMABuf.cpp.orig	2025-01-11 00:00:00 UTC
+++ Source/WebKit/UIProcess/gtk/AcceleratedBackingStoreDMABuf.cpp
@@ -72,6 +72,11 @@ OptionSet<DMABufRendererBufferMode> AcceleratedBackin
     static OptionSet<DMABufRendererBufferMode> mode;
     static std::once_flag onceFlag;
     std::call_once(onceFlag, [] {
+#ifdef __FreeBSD__
+        // DMA-BUF support is incomplete on FreeBSD, especially with NVIDIA drivers
+        // Disable DMA-BUF renderer unconditionally on FreeBSD
+        return;
+#endif
         const char* disableDMABuf = getenv("WEBKIT_DISABLE_DMABUF_RENDERER");
         if (disableDMABuf && strcmp(disableDMABuf, "0"))
             return;
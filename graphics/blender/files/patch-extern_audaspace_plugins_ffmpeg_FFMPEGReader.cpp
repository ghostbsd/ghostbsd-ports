--- extern/audaspace/plugins/ffmpeg/FFMPEGReader.cpp.orig	2025-07-15 00:00:00 UTC
+++ extern/audaspace/plugins/ffmpeg/FFMPEGReader.cpp
@@ -35,6 +35,12 @@ AUD_NAMESPACE_BEGIN
 #if LIBAVCODEC_VERSION_MAJOR < 59
 #define FFMPEG_OLD_CH_LAYOUT
 #endif
+/* FFmpeg >= 7.0 removed AV_INPUT_BUFFER_MIN_SIZE */
+#if LIBAVCODEC_VERSION_MAJOR >= 61
+#ifndef AV_INPUT_BUFFER_MIN_SIZE
+#define AV_INPUT_BUFFER_MIN_SIZE 16384
+#endif
+#endif

 SampleFormat FFMPEGReader::convertSampleFormat(AVSampleFormat format)
 {

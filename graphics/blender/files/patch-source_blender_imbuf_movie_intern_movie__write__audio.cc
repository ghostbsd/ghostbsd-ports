--- source/blender/imbuf/movie/intern/movie_write_audio.cc.orig	2025-07-15 00:00:00 UTC
+++ source/blender/imbuf/movie/intern/movie_write_audio.cc
@@ -28,6 +28,13 @@
 #  include "BKE_report.hh"
 #  include "BKE_sound.h"

+/* FFmpeg >= 7.0 removed AV_INPUT_BUFFER_MIN_SIZE */
+#if LIBAVCODEC_VERSION_MAJOR >= 61
+#ifndef AV_INPUT_BUFFER_MIN_SIZE
+#define AV_INPUT_BUFFER_MIN_SIZE 16384
+#endif
+#endif
+
 /* If any of these codecs, we prefer the float sample format (if supported) */
 static bool request_float_audio_buffer(int codec_id)
 {

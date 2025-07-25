--- src/3rdparty/chromium/third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/modules/peerconnection/rtc_data_channel.cc
@@ -557,6 +557,7 @@ void RTCDataChannel::send(Blob* data, ExceptionState& 
   pending_messages_.push_back(message);
 }
 
+#undef close
 void RTCDataChannel::close() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   if (state_ == webrtc::DataChannelInterface::kClosing ||

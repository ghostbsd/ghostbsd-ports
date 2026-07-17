--- crates/gpui_linux/src/linux/platform.rs.orig	2026-07-09 20:22:36 UTC
+++ crates/gpui_linux/src/linux/platform.rs
@@ -124,7 +124,7 @@ pub(crate) struct LinuxCommon {
     pub(crate) signal: LoopSignal,
     pub(crate) menus: Vec<OwnedMenu>,
     #[cfg_attr(
-        not(all(target_os = "linux", any(feature = "wayland", feature = "x11"))),
+        not(all(any(target_os = "linux", target_os = "freebsd"), any(feature = "wayland", feature = "x11"))),
         allow(dead_code)
     )]
     wake_sender: Sender<()>,
@@ -172,7 +172,7 @@ impl LinuxCommon {
 
     pub(crate) fn start_wake_listener(&mut self) {
         if !self.wake_listener_started {
-            #[cfg(all(target_os = "linux", any(feature = "wayland", feature = "x11")))]
+            #[cfg(all(any(target_os = "linux", target_os = "freebsd"), any(feature = "wayland", feature = "x11")))]
             smol::spawn({
                 let wake_sender = self.wake_sender.clone();
                 async move {
@@ -195,7 +195,7 @@ impl LinuxCommon {
     }
 }
 
-#[cfg(all(target_os = "linux", any(feature = "wayland", feature = "x11")))]
+#[cfg(all(any(target_os = "linux", target_os = "freebsd"), any(feature = "wayland", feature = "x11")))]
 async fn listen_for_system_wake(wake_sender: Sender<()>) -> anyhow::Result<()> {
     use futures::StreamExt as _;
 

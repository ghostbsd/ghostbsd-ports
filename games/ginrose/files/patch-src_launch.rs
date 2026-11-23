--- src/launch.rs.orig	2026-11-23 18:12:21 UTC
+++ src/launch.rs
@@ -76,7 +76,7 @@ fn unsafe_kill(pid: i32, signal: i32) {
 }
 
 fn unsafe_kill(pid: i32, signal: i32) {
-    let _ = Command::new("kill")
+    let _ = crate::process::command("kill")
         .arg(format!("-{signal}"))
         .arg(pid.to_string())
         .stderr(Stdio::null())

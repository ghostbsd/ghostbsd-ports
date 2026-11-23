--- src/desktop.rs.orig	2026-11-23 18:12:21 UTC
+++ src/desktop.rs
@@ -2,8 +2,6 @@
 //! `roblox-studio:` and `roblox-studio-auth:` links (Ginrose Studio) from the
 //! browser.
 
-use std::process::Command;
-
 use crate::flavor::{self, Flavor};
 use crate::paths;
 
@@ -54,7 +52,7 @@ fn install_icons() -> Result<(), String> {
         std::fs::create_dir_all(&dir).map_err(|e| e.to_string())?;
         std::fs::write(dir.join(format!("{id}.png")), bytes).map_err(|e| e.to_string())?;
     }
-    let _ = Command::new("gtk-update-icon-cache")
+    let _ = crate::process::command("gtk-update-icon-cache")
         .args(["-f", "-t"])
         .arg(&theme)
         .status();
@@ -168,10 +166,12 @@ pub fn install(default: bool) -> Result<(), String> {
         for (name, text) in entries(flavor, &exe) {
             std::fs::write(dir.join(name), text).map_err(|e| e.to_string())?;
         }
-        let _ = Command::new("update-desktop-database").arg(&dir).status();
+        let _ = crate::process::command("update-desktop-database")
+            .arg(&dir)
+            .status();
     }
     if default {
-        let status = Command::new("xdg-mime")
+        let status = crate::process::command("xdg-mime")
             .arg("default")
             .arg(format!("{}.desktop", flavor.client_id()))
             .args(flavor.schemes())
@@ -192,7 +192,9 @@ pub fn uninstall() {
     for (name, _) in entries(flavor::current(), "") {
         let _ = std::fs::remove_file(dir.join(name));
     }
-    let _ = Command::new("update-desktop-database").arg(&dir).status();
+    let _ = crate::process::command("update-desktop-database")
+        .arg(&dir)
+        .status();
     for (size, _) in icons() {
         let _ =
             std::fs::remove_file(icon_theme().join(format!("{size}x{size}/apps/{}.png", app_id())));
@@ -202,7 +204,7 @@ pub fn is_default() -> bool {
 /// Whether this app opens its links now.
 pub fn is_default() -> bool {
     let flavor = flavor::current();
-    Command::new("xdg-mime")
+    crate::process::command("xdg-mime")
         .args(["query", "default", flavor.schemes()[0]])
         .output()
         .is_ok_and(|out| {

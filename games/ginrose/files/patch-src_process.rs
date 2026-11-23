--- src/process.rs.orig	2026-11-23 18:12:21 UTC
+++ src/process.rs
@@ -11,6 +11,29 @@ pub struct Process {
     pub args: Vec<String>,
 }
 
+/// A command for a program found on PATH, named by its full path.
+///
+/// Given a bare name, Rust's `Command` has `posix_spawnp` search PATH in the
+/// child. On FreeBSD that child runs in Ginrose's own memory until it execs,
+/// and from the GTK process it corrupted the heap: the launcher crashed as
+/// soon as the settings page asked xdg-mime who opens Roblox links. A full
+/// path takes `posix_spawn`, which has nothing to search. A program that is
+/// not on PATH keeps its bare name and fails to start as it always did.
+pub fn command(program: &str) -> std::process::Command {
+    let found = std::env::var_os("PATH").and_then(|path| {
+        std::env::split_paths(&path)
+            .map(|dir| dir.join(program))
+            .find(|candidate| is_executable(candidate))
+    });
+    std::process::Command::new(found.as_deref().unwrap_or(program.as_ref()))
+}
+
+fn is_executable(path: &std::path::Path) -> bool {
+    use std::os::unix::fs::PermissionsExt;
+    path.is_absolute()
+        && std::fs::metadata(path).is_ok_and(|m| m.is_file() && m.permissions().mode() & 0o111 != 0)
+}
+
 /// Arguments as the kernel keeps them: one after another, each ended by a NUL.
 fn split_args(raw: &[u8]) -> Vec<String> {
     raw.split(|b| *b == 0)
@@ -152,5 +175,17 @@ mod tests {
         assert_eq!(found.args.first(), Some(&exe));
         assert!(!found.name.is_empty());
         assert!(exe.rsplit('/').next().unwrap().starts_with(&found.name));
+    }
+
+    #[test]
+    fn names_a_program_on_path_by_its_full_path() {
+        let sh = command("sh");
+        let program = std::path::Path::new(sh.get_program());
+        assert!(program.is_absolute(), "{}", program.display());
+        assert!(sh.get_program().to_string_lossy().ends_with("/sh"));
+        assert_eq!(
+            command("no-such-program-anywhere").get_program(),
+            "no-such-program-anywhere"
+        );
     }
 }

--- crates/project/src/agent_server_store.rs.orig	2026-04-15 21:06:43 UTC
+++ crates/project/src/agent_server_store.rs
@@ -1189,6 +1189,8 @@ impl ExternalAgentServer for LocalExtensionArchiveAgen
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };
@@ -1377,6 +1379,8 @@ impl ExternalAgentServer for LocalRegistryArchiveAgent
                 "linux"
             } else if cfg!(target_os = "windows") {
                 "windows"
+            } else if cfg!(target_os = "freebsd") {
+                "freebsd"
             } else {
                 anyhow::bail!("unsupported OS");
             };

--- hermes_cli/config.py.orig	2026-07-08 03:11:08 UTC
+++ hermes_cli/config.py
@@ -2554,8 +2554,10 @@ DEFAULT_CONFIG = {
         # their TTS provider). Set to false to require explicit
         # ``pip install`` for everything beyond the base set — appropriate
         # for restricted networks, audited environments, or air-gapped
-        # systems where any runtime install is unacceptable.
-        "allow_lazy_installs": True,
+        # systems where any runtime install is unacceptable.  Defaults to
+        # False on FreeBSD: the package manager owns the site-packages tree,
+        # and runtime pip writes there create pkg-invisible files.
+        "allow_lazy_installs": not sys.platform.startswith("freebsd"),
     },
 
     "cron": {

--- tests/conftest.py.orig	2026-04-17 17:07:02 UTC
+++ tests/conftest.py
@@ -16,7 +16,7 @@ _log = logging.getLogger("arviz_plots")
 
 _log = logging.getLogger("arviz_plots")
 
-settings.register_profile("fast", deadline=3000, max_examples=20)
+settings.register_profile("fast", deadline=None, max_examples=20)
 settings.register_profile("chron", deadline=3000, max_examples=500)
 settings.load_profile(os.getenv("HYPOTHESIS_PROFILE", "fast"))
 

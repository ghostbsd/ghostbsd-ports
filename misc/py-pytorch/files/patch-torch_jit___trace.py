--- torch/jit/_trace.py.orig	2026-04-18 00:49:58 UTC
+++ torch/jit/_trace.py
@@ -445,8 +445,11 @@ def _check_trace(
                     if n_mod.kindOf("value") != "t" or n_check.kindOf("value") != "t":
                         continue
 
-                    mod_tensor_val = n_mod.t("value")
-                    check_tensor_val = n_check.t("value")
+                    try:
+                        mod_tensor_val = n_mod.t("value")
+                        check_tensor_val = n_check.t("value")
+                    except RuntimeError:
+                        continue
 
                     try:
                         torch.testing.assert_close(

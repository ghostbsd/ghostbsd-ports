--- test/run_test.py.orig	2026-04-17 23:39:17 UTC
+++ test/run_test.py
@@ -1244,21 +1244,10 @@ def get_pytest_args(options, is_cpp_test=False, is_dis
 
 
 def get_pytest_args(options, is_cpp_test=False, is_distributed_test=False):
-    if is_distributed_test:
-        # Distributed tests do not support rerun, see https://github.com/pytorch/pytorch/issues/162978
-        rerun_options = ["-x", "--reruns=0"]
-    elif RERUN_DISABLED_TESTS:
-        # ASAN tests are too slow, so running them x50 will cause the jobs to timeout after
-        # 3+ hours. So, let's opt for less number of reruns. We need at least 150 instances of the
-        # test every 2 weeks to satisfy the SQL query (15 x 14 = 210).
-        count = 15 if TEST_WITH_ASAN else 50
-        # When under rerun-disabled-tests mode, run the same tests multiple times to determine their
-        # flakiness status. Default to 50 re-runs
-        rerun_options = ["--flake-finder", f"--flake-runs={count}"]
+    if is_distributed_test or RERUN_DISABLED_TESTS:
+        rerun_options = ["-x"]
     else:
-        # When under the normal mode, retry a failed test 2 more times. -x means stop at the first
-        # failure
-        rerun_options = ["-x", "--reruns=2"]
+        rerun_options = ["-x"]
 
     pytest_args = [
         "-vv",
@@ -1277,7 +1266,7 @@ def get_pytest_args(options, is_cpp_test=False, is_dis
             # Add the option to generate XML test report here as C++ tests
             # won't go into common_utils
             test_report_path = get_report_path(pytest=True)
-            pytest_args.extend(["--junit-xml-reruns", test_report_path])
+            pytest_args.extend(["--junit-xml", test_report_path])
 
     if options.pytest_k_expr:
         pytest_args.extend(["-k", options.pytest_k_expr])
@@ -1812,6 +1801,13 @@ def get_selected_tests(options) -> list[str]:
             "Skip distributed tests on s390x",
         )
 
+    if sys.platform.startswith("freebsd"):
+        selected_tests = exclude_tests(
+            DISTRIBUTED_TESTS,
+            selected_tests,
+            "Skip distributed tests on FreeBSD (gloo unsupported)",
+        )
+
     # skip all distributed tests if distributed package is not available.
     if not dist.is_available():
         selected_tests = exclude_tests(
@@ -2100,8 +2096,6 @@ def main():
 
 
 def main():
-    check_pip_packages()
-
     options = parse_args()
     tests_to_include_env = os.environ.get("TESTS_TO_INCLUDE", "").strip()
     if tests_to_include_env:

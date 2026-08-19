-- Avoid dependency on the setuptools.command.bdist_wheel module if wheel is not installed.
-- This ensures setup.py runs correctly during build when wheel is not present.
--- setup.py.orig	2026-07-08 17:44:27 UTC
+++ setup.py
@@ -282,7 +282,7 @@ from typing import Any, ClassVar, IO
 from pathlib import Path
 from typing import Any, ClassVar, IO
 
-import setuptools.command.bdist_wheel
+# import setuptools.command.bdist_wheel
 import setuptools.command.build_ext
 import setuptools.errors
 from setuptools import Command, Extension, find_packages, setup
@@ -980,25 +980,30 @@ class build_ext(setuptools.command.build_ext.build_ext
         return outputs
 
 
-class bdist_wheel(setuptools.command.bdist_wheel.bdist_wheel):
-    def write_wheelfile(self, *args: Any, **kwargs: Any) -> None:
-        super().write_wheelfile(*args, **kwargs)
+try:
+    from wheel.bdist_wheel import bdist_wheel as _bdist_wheel
+except ImportError:
+    bdist_wheel = None
+else:
+    class bdist_wheel(_bdist_wheel):
+        def write_wheelfile(self, *args: Any, **kwargs: Any) -> None:
+            super().write_wheelfile(*args, **kwargs)
 
-        if BUILD_LIBTORCH_WHL:
-            if self.bdist_dir is None:
-                raise AssertionError("self.bdist_dir must not be None")
-            bdist_dir = Path(self.bdist_dir)
-            # Remove extraneneous files in the libtorch wheel
-            for file in itertools.chain(
-                bdist_dir.rglob("*.a"),
-                bdist_dir.rglob("*.so"),
-            ):
-                if (bdist_dir / file.name).is_file():
+            if BUILD_LIBTORCH_WHL:
+                if self.bdist_dir is None:
+                    raise AssertionError("self.bdist_dir must not be None")
+                bdist_dir = Path(self.bdist_dir)
+                # Remove extraneneous files in the libtorch wheel
+                for file in itertools.chain(
+                    bdist_dir.rglob("*.a"),
+                    bdist_dir.rglob("*.so"),
+                ):
+                    if (bdist_dir / file.name).is_file():
+                        file.unlink()
+                for file in bdist_dir.rglob("*.py"):
                     file.unlink()
-            for file in bdist_dir.rglob("*.py"):
-                file.unlink()
-            # need an __init__.py file otherwise we wouldn't have a package
-            (bdist_dir / "torch" / "__init__.py").touch()
+                # need an __init__.py file otherwise we wouldn't have a package
+                (bdist_dir / "torch" / "__init__.py").touch()
 
 
 class clean(Command):
@@ -1082,10 +1087,11 @@ def configure_extension_build() -> tuple[
     packages = find_packages(include=includes, exclude=excludes)
 
     cmdclass = {
-        "bdist_wheel": bdist_wheel,
         "build_ext": build_ext,
         "clean": clean,
     }
+    if bdist_wheel is not None:
+        cmdclass["bdist_wheel"] = bdist_wheel
 
     entry_points = {
         "console_scripts": [
@@ -1137,7 +1143,7 @@ def main() -> None:
     install_requires = [
         "filelock",
         "typing-extensions>=4.10.0",
-        "setuptools>=77.0.3",
+        "setuptools",
         "sympy>=1.13.3",
         "networkx>=2.5.1",
         "jinja2",

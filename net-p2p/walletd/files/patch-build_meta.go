--- build/meta.go.orig	2025-03-11 16:49:37 UTC
+++ build/meta.go
@@ -1,7 +1,9 @@
+// Code generated by go generate; DO NOT EDIT.
+// This file was generated by go generate at 2025-03-11T17:25:25+01:00.
 package build
 
 const (
-	commit    = "?"
-	version   = "?"
-	buildTime = 0
+	commit = "42659f7"
+	version = "v2.0.0"
+	buildTime = %%BUILDTIME%%
 )

--- src/sysinfo.cpp
+++ src/sysinfo.cpp
@@ -413,7 +413,7 @@ namespace {
 #elif defined(__sun) && defined(__SVR4)
             this->kernel = string(uname().sysname) + ' ' + uname().release + ' ' + uname().version + ' ' + uname().machine;
 #else
-            this->kernel = string(uname().version) + ' ' + uname().machine;
+            this->kernel = string(uname().sysname) + ' ' + uname().release + ' ' + uname().machine;
 #endif
         }
 

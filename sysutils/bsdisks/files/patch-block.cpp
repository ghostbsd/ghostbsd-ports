--- block.cpp.orig
+++ block.cpp
@@ -150,6 +150,16 @@
     }
 
     return false;
+}
+
+bool Block::hintAuto() const
+{
+    if(!parentDrive)
+        return false;
+
+    return parentDrive->connectionBus() == "usb"
+        || parentDrive->removable()
+        || parentDrive->optical();
 }
 
 QString Block::hintName() const

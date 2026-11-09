--- objectmanager.cpp.orig
+++ objectmanager.cpp
@@ -232,6 +232,9 @@
     if (dev.contains('/'))
         return;
 
+    if(auto* d = m_driveObjects.value(dev, nullptr))
+        d->mediaChanged();
+
     auto* b = m_blockObjects.value(dev, nullptr);
     // the device gone somewhere between receiving a notification and this call
     if(!b)

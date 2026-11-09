--- block.h.orig
+++ block.h
@@ -104,6 +104,9 @@
     Q_PROPERTY(bool HintIgnore READ hintIgnore)
     bool hintIgnore() const;
 
+    Q_PROPERTY(bool HintAuto READ hintAuto)
+    bool hintAuto() const;
+
     Q_PROPERTY(QString HintName READ hintName)
     QString hintName() const;
 

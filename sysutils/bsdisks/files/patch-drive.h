--- drive.h.orig
+++ drive.h
@@ -52,6 +52,12 @@
     bool camcontrolProbeDone;
     bool geomProbeDone;
 
+    qulonglong timeDetected;
+    Q_PROPERTY(qulonglong TimeDetected MEMBER timeDetected)
+
+    // gvfs only automounts volumes that appear within 5 seconds of this.
+    Q_PROPERTY(qulonglong TimeMediaDetected MEMBER timeDetected)
+
     Q_PROPERTY(Configuration Configuration READ configuration)
     Configuration configuration() const;
 

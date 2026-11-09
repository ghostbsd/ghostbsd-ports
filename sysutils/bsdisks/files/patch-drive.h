--- drive.h.orig
+++ drive.h
@@ -52,6 +52,17 @@
     bool camcontrolProbeDone;
     bool geomProbeDone;
 
+    qulonglong timeDetectedUsec;
+    qulonglong timeMediaDetectedUsec;
+    void mediaChanged();
+
+    Q_PROPERTY(qulonglong TimeDetected READ timeDetected)
+    qulonglong timeDetected() const;
+
+    // gvfs only automounts volumes that appear within 5 seconds of this.
+    Q_PROPERTY(qulonglong TimeMediaDetected READ timeMediaDetected)
+    qulonglong timeMediaDetected() const;
+
     Q_PROPERTY(Configuration Configuration READ configuration)
     Configuration configuration() const;
 

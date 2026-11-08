--- drive.cpp.orig
+++ drive.cpp
@@ -32,6 +32,7 @@
 
 #include <QDBusConnection>
 #include <QDBusConnectionInterface>
+#include <QDateTime>
 #include <QProcess>
 
 #include "drive.h"
@@ -177,6 +178,7 @@
 }
 
 Drive::Drive::Drive()
-    : camcontrolProbeDone(false), geomProbeDone(false)
+    : camcontrolProbeDone(false), geomProbeDone(false),
+      timeDetected(QDateTime::currentMSecsSinceEpoch() * 1000)
 {
 }

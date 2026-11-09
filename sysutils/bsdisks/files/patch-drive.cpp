--- drive.cpp.orig
+++ drive.cpp
@@ -32,6 +32,8 @@
 
 #include <QDBusConnection>
 #include <QDBusConnectionInterface>
+#include <QDBusMessage>
+#include <QDateTime>
 #include <QProcess>
 
 #include "drive.h"
@@ -176,7 +178,37 @@
     return ataSata;
 }
 
+qulonglong Drive::timeDetected() const
+{
+    return timeDetectedUsec;
+}
+
+qulonglong Drive::timeMediaDetected() const
+{
+    return timeMediaDetectedUsec;
+}
+
+void Drive::mediaChanged()
+{
+    timeMediaDetectedUsec = QDateTime::currentMSecsSinceEpoch() * 1000;
+
+    QVariantMap props;
+    props.insert(QStringLiteral("TimeMediaDetected"), timeMediaDetectedUsec);
+
+    QDBusMessage signal = QDBusMessage::createSignal(
+                                dbusPath.path(),
+                                QStringLiteral("org.freedesktop.DBus.Properties"),
+                                QStringLiteral("PropertiesChanged"));
+
+    signal << QStringLiteral("org.freedesktop.UDisks2.Drive")
+           << props
+           << QStringList();
+    QDBusConnection::systemBus().send(signal);
+}
+
 Drive::Drive::Drive()
-    : camcontrolProbeDone(false), geomProbeDone(false)
+    : camcontrolProbeDone(false), geomProbeDone(false),
+      timeDetectedUsec(QDateTime::currentMSecsSinceEpoch() * 1000),
+      timeMediaDetectedUsec(timeDetectedUsec)
 {
 }

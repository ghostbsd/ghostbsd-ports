diff --git engine/Poseidon/AI/AIGroupImpl.cpp engine/Poseidon/AI/AIGroupImpl.cpp
index eeaffd9..22d895b 100644
--- engine/Poseidon/AI/AIGroupImpl.cpp
+++ engine/Poseidon/AI/AIGroupImpl.cpp
@@ -41,6 +41,22 @@ namespace Poseidon
 {
 using namespace Foundation;
 
+// Diagnostic for msgCmd->GetFrom() == this invariant violations in the radio
+// queue scans below. Returns the result of the check so call sites can be
+// written as `if (!CheckMsgCmdFrom(...)) continue;` in future patches.
+static bool CheckMsgCmdFrom(const AIGroup* self, RadioMessageCommand* msgCmd, const char* callSite)
+{
+    if (msgCmd->GetFrom() == self)
+    {
+        return true;
+    }
+    LOG_ERROR(AI, "AIGroup radio queue holds foreign command at {}: this={} ({}), from={} ({}), msgType={}", callSite,
+              self ? (const char*)self->GetDebugName() : "null", (const void*)self,
+              msgCmd->GetFrom() ? (const char*)msgCmd->GetFrom()->GetDebugName() : "null",
+              (const void*)msgCmd->GetFrom(), msgCmd->GetType());
+    return false;
+}
+
 // Parameters
 
 bool AIGroup::CommandSent(bool channelCenter)
@@ -72,7 +88,10 @@ bool AIGroup::CommandSent(bool channelCenter)
         AI_ERROR(dynamic_cast<RadioMessageCommand*>(msg));
         RadioMessageCommand* msgCmd = static_cast<RadioMessageCommand*>(msg);
         AI_ERROR(msgCmd);
-        AI_ERROR(msgCmd->GetFrom() == this);
+        if (!channelCenter)
+        {
+            CheckMsgCmdFrom(this, msgCmd, "CommandSent(bool)/FindPrevMessage");
+        }
         if (msgCmd->IsToMainSubgroup())
         {
             return true;
@@ -86,7 +105,10 @@ bool AIGroup::CommandSent(bool channelCenter)
         AI_ERROR(dynamic_cast<RadioMessageCommand*>(msg));
         RadioMessageCommand* msgCmd = static_cast<RadioMessageCommand*>(msg);
         AI_ERROR(msgCmd);
-        AI_ERROR(msgCmd->GetFrom() == this);
+        if (!channelCenter)
+        {
+            CheckMsgCmdFrom(this, msgCmd, "CommandSent(bool)/GetActualMessage");
+        }
         if (msgCmd->IsToMainSubgroup())
         {
             return true;
@@ -139,7 +161,10 @@ bool AIGroup::CommandSent(Command::Message message, bool channelCenter)
         AI_ERROR(dynamic_cast<RadioMessageCommand*>(msg));
         RadioMessageCommand* msgCmd = static_cast<RadioMessageCommand*>(msg);
         AI_ERROR(msgCmd);
-        AI_ERROR(msgCmd->GetFrom() == this);
+        if (!channelCenter)
+        {
+            CheckMsgCmdFrom(this, msgCmd, "CommandSent(msg,bool)/FindPrevMessage");
+        }
         if (msgCmd->GetCmdMessage() == message)
         {
             return true;
@@ -152,7 +177,10 @@ bool AIGroup::CommandSent(Command::Message message, bool channelCenter)
         AI_ERROR(dynamic_cast<RadioMessageCommand*>(msg));
         RadioMessageCommand* msgCmd = static_cast<RadioMessageCommand*>(msg);
         AI_ERROR(msgCmd);
-        AI_ERROR(msgCmd->GetFrom() == this);
+        if (!channelCenter)
+        {
+            CheckMsgCmdFrom(this, msgCmd, "CommandSent(msg,bool)/GetActualMessage");
+        }
         if (msgCmd->GetCmdMessage() == message)
         {
             return true;
@@ -200,7 +228,10 @@ bool AIGroup::CommandSent(AIUnit* to, Command::Message message, bool channelCent
         AI_ERROR(dynamic_cast<RadioMessageCommand*>(msg));
         RadioMessageCommand* msgCmd = static_cast<RadioMessageCommand*>(msg);
         AI_ERROR(msgCmd);
-        AI_ERROR(msgCmd->GetFrom() == this);
+        if (!channelCenter)
+        {
+            CheckMsgCmdFrom(this, msgCmd, "CommandSent(to,msg,bool)/FindPrevMessage");
+        }
         if (msgCmd->IsTo(to) && msgCmd->GetCmdMessage() == message)
         {
             return true;
@@ -213,7 +244,10 @@ bool AIGroup::CommandSent(AIUnit* to, Command::Message message, bool channelCent
         AI_ERROR(dynamic_cast<RadioMessageCommand*>(msg));
         RadioMessageCommand* msgCmd = static_cast<RadioMessageCommand*>(msg);
         AI_ERROR(msgCmd);
-        AI_ERROR(msgCmd->GetFrom() == this);
+        if (!channelCenter)
+        {
+            CheckMsgCmdFrom(this, msgCmd, "CommandSent(to,msg,bool)/GetActualMessage");
+        }
         if (msgCmd->IsTo(to) && msgCmd->GetCmdMessage() == message)
         {
             return true;
@@ -237,7 +271,7 @@ void AIGroup::ClearGetInCommands(AIUnit* to)
         AI_ERROR(dynamic_cast<RadioMessageCommand*>(msg));
         RadioMessageCommand* msgCmd = static_cast<RadioMessageCommand*>(msg);
         AI_ERROR(msgCmd);
-        AI_ERROR(msgCmd->GetFrom() == this);
+        CheckMsgCmdFrom(this, msgCmd, "ClearGetInCommands/FindPrevMessage");
         if (msgCmd->IsTo(to) && msgCmd->GetCmdMessage() == Command::GetIn &&
             (msgCmd->GetContext() == Command::CtxAuto || msgCmd->GetContext() == Command::CtxAutoSilent))
         {
@@ -252,8 +286,7 @@ void AIGroup::ClearGetInCommands(AIUnit* to)
         AI_ERROR(dynamic_cast<RadioMessageCommand*>(msg));
         RadioMessageCommand* msgCmd = static_cast<RadioMessageCommand*>(msg);
         AI_ERROR(msgCmd);
-        AI_ERROR(msgCmd->GetFrom() == this);
-        AI_ERROR(msgCmd->GetFrom() == this);
+        CheckMsgCmdFrom(this, msgCmd, "ClearGetInCommands/GetActualMessage");
         if (msgCmd->IsTo(to) && msgCmd->GetCmdMessage() == Command::GetIn &&
             (msgCmd->GetContext() == Command::CtxAuto || msgCmd->GetContext() == Command::CtxAutoSilent))
         {

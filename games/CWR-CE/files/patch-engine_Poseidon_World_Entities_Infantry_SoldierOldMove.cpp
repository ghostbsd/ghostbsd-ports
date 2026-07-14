diff --git engine/Poseidon/World/Entities/Infantry/SoldierOldMove.cpp engine/Poseidon/World/Entities/Infantry/SoldierOldMove.cpp
index 87c660d..7ac63e8 100644
--- engine/Poseidon/World/Entities/Infantry/SoldierOldMove.cpp
+++ engine/Poseidon/World/Entities/Infantry/SoldierOldMove.cpp
@@ -1006,7 +1006,9 @@ namespace Poseidon
 
 void Man::KilledBy(EntityAI* owner)
 {
-    PoseidonAssert(_brain);
+    // _brain is null on respawn transfer (NetworkClient.cpp moves the brain
+    // to the new Soldier and nulls the old body's brain). A brainless
+    // corpse taking damage lands here; nothing to do.
     if (!_brain)
     {
         return;

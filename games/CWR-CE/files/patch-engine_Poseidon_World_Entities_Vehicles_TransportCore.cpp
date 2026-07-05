diff --git engine/Poseidon/World/Entities/Vehicles/TransportCore.cpp engine/Poseidon/World/Entities/Vehicles/TransportCore.cpp
index df48f09..c6fb37b 100644
--- engine/Poseidon/World/Entities/Vehicles/TransportCore.cpp
+++ engine/Poseidon/World/Entities/Vehicles/TransportCore.cpp
@@ -350,7 +350,8 @@ void Transport::DammageCrew(EntityAI* killer, float howMuch, RString ammo)
         }
         if (CrewDammage(this, man, killer, howMuch, ammo))
         {
-            if (man)
+            // Skip brainless corpses (post-respawn bodies still riding as cargo).
+            if (man && man->Brain())
             {
                 man->KilledBy(killer);
             }
@@ -358,21 +359,21 @@ void Transport::DammageCrew(EntityAI* killer, float howMuch, RString ammo)
     }
     if (CrewDammage(this, _driver, killer, howMuch, ammo))
     {
-        if (_driver)
+        if (_driver && _driver->Brain())
         {
             _driver->KilledBy(killer);
         }
     }
     if (CrewDammage(this, _gunner, killer, howMuch, ammo))
     {
-        if (_gunner)
+        if (_gunner && _gunner->Brain())
         {
             _gunner->KilledBy(killer);
         }
     }
     if (CrewDammage(this, _commander, killer, howMuch, ammo))
     {
-        if (_commander)
+        if (_commander && _commander->Brain())
         {
             _commander->KilledBy(killer);
         }

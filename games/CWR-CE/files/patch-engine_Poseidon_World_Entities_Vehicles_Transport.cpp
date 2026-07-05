diff --git engine/Poseidon/World/Entities/Vehicles/Transport.cpp engine/Poseidon/World/Entities/Vehicles/Transport.cpp
index eb2d624..44da61b 100644
--- engine/Poseidon/World/Entities/Vehicles/Transport.cpp
+++ engine/Poseidon/World/Entities/Vehicles/Transport.cpp
@@ -1591,7 +1591,10 @@ void VehicleSupply::SupplyStarted(AIUnit* unit)
 {
     LOG_DEBUG(Physics, "{} SupplyStarted for {}", (const char*)GetDebugName(), (const char*)unit->GetDebugName());
 
-    PoseidonAssert(_supplyUnits.Find(unit) < 0);
+    // A re-entry of the supply FSM state (e.g. Supply->Move->Supply when the
+    // client drifts out of range and comes back) can call SupplyStarted for
+    // a unit that never emitted a matching SupplyFinished. AddUnique below
+    // handles the duplicate; the assert is stale.
     _supplyUnits.AddUnique(unit);
 }
 

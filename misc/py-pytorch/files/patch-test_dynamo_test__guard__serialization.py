--- test/dynamo/test_guard_serialization.py.orig	2026-07-08 17:44:27 UTC
+++ test/dynamo/test_guard_serialization.py
@@ -1526,6 +1526,7 @@ class TestGuardSerialization(TestGuardSerializationBas
         )
 
     @torch._dynamo.config.patch(nested_graph_breaks=False)
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Gloo does not support FreeBSD")
     def test_ddp_module(self):
         import torch.distributed as dist
 
@@ -1578,6 +1579,7 @@ class TestGuardSerialization(TestGuardSerializationBas
             True,
         )
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Gloo does not support FreeBSD")
     def test_unserializable_sharded_tensor(self):
         import torch.distributed as dist
 
@@ -1693,6 +1695,7 @@ class TestGuardSerialization(TestGuardSerializationBas
         )
         self._test_check_fn(ref, loaded, {"inputs": Inputs(x, torch.Stream())}, True)
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Gloo does not support FreeBSD")
     def test_unused_process_group(self):
         import torch.distributed as dist
 

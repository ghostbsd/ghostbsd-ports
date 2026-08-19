--- test/dynamo/test_repros.py.orig	2026-07-08 17:44:27 UTC
+++ test/dynamo/test_repros.py
@@ -6272,6 +6272,7 @@ def forward(self, s77 : torch.SymInt, s27 : torch.SymI
         graph_code = backend.graphs[0].print_readable(print_output=False)
         self.assertIn("torch._C._nn.linear", graph_code)
 
+    @unittest.skipIf(sys.platform.startswith("freebsd"), "Kineto causes SIGABRT on FreeBSD")
     def test_aot_autograd_runtime_wrapper_prologue_profiled(self):
         # Names for prologue profiling event
         prologue_name = "AOTDispatcher Runtime Wrapper Prologue"

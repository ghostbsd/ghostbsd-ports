--- base/trace_event/memory_dump_manager.cc.orig	2025-03-09 21:38:10 UTC
+++ base/trace_event/memory_dump_manager.cc
@@ -78,7 +78,7 @@ const char* const MemoryDumpManager::kSystemAllocatorP
 #if defined(MALLOC_MEMORY_TRACING_SUPPORTED)
     MallocDumpProvider::kAllocatedObjects;
 #else
-    nullptr;
+    "";
 #endif
 
 // static

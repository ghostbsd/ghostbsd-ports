--- gpu/command_buffer/service/shared_context_state.cc.orig	2025-06-30 07:04:30 UTC
+++ gpu/command_buffer/service/shared_context_state.cc
@@ -64,7 +64,7 @@
 #include "gpu/vulkan/vulkan_implementation.h"
 #include "gpu/vulkan/vulkan_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/external_semaphore_pool.h"
 #endif
 
@@ -348,7 +348,7 @@ SharedContextState::SharedContextState(
   if (gr_context_type_ == GrContextType::kVulkan) {
     if (vk_context_provider_) {
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
       external_semaphore_pool_ = std::make_unique<ExternalSemaphorePool>(this);
 #endif
       use_virtualized_gl_contexts_ = false;
@@ -385,7 +385,7 @@ SharedContextState::~SharedContextState() {
   }
 
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   external_semaphore_pool_.reset();
 #endif
 

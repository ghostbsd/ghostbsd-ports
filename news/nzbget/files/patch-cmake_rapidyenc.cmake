--- cmake/rapidyenc.cmake.orig	2026-07-12 07:42:50 UTC
+++ cmake/rapidyenc.cmake
@@ -51,12 +51,6 @@ ExternalProject_add(
 ExternalProject_add(
	rapidyenc
	PREFIX			rapidyenc
-	GIT_REPOSITORY	https://github.com/nzbgetcom/rapidyenc.git
-	GIT_TAG			v1.1.1-20260217
-	TLS_VERIFY		TRUE
-	GIT_SHALLOW		TRUE
-	GIT_PROGRESS	TRUE
-	DOWNLOAD_EXTRACT_TIMESTAMP	TRUE
	BUILD_BYPRODUCTS ${RAPIDYENC_LIBS}
	CMAKE_ARGS		 ${CMAKE_ARGS}
	INSTALL_COMMAND	""

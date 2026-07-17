--- src/utils/os_config_init.c.orig	2026-07-17 10:26:27 UTC
+++ src/utils/os_config_init.c
@@ -334,6 +334,12 @@ static Bool get_default_install_path(char file_path[GF
 /*Linux, OSX, iOS*/
 #else
 
+#include <errno.h>
+
+#if defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
+
 //dlinfo
 #if defined(__DARWIN__) || defined(__APPLE__) || defined(__FreeBSD__)
 #include <dlfcn.h>
@@ -357,7 +363,7 @@ static Bool get_default_install_path(char file_path[GF
 {
 	char app_path[GF_MAX_PATH];
 	char *sep;
-#if (defined(__DARWIN__) || defined(__APPLE__) || defined(GPAC_CONFIG_LINUX) || defined(__FreeBSD__))
+#if (defined(__DARWIN__) || defined(__APPLE__))
 	u32 size;
 #endif
 
@@ -419,13 +425,30 @@ static Bool get_default_install_path(char file_path[GF
 			return 1;
 		}
 
-#elif defined(GPAC_CONFIG_LINUX) || defined(__FreeBSD__)
-		size = readlink("/proc/self/exe", file_path, GF_MAX_PATH-1);
-		if (size>0) {
-			file_path[size] = 0;
-			sep = strrchr(file_path, '/');
-			if (sep) sep[0] = 0;
-			return 1;
+#elif defined(__FreeBSD__)
+		{
+			int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1 };
+			size_t sz = GF_MAX_PATH;
+			if (sysctl(mib, 4, file_path, &sz, NULL, 0) == 0) {
+				sep = strrchr(file_path, '/');
+				if (sep) sep[0] = 0;
+				return 1;
+			}
+			GF_LOG(GF_LOG_ERROR, GF_LOG_CORE, ("sysctl(KERN_PROC_PATHNAME) failed: %s\n", strerror(errno)));
+			return 0;
+		}
+
+#elif defined(GPAC_CONFIG_LINUX)
+		{
+			ssize_t ssize = readlink("/proc/self/exe", file_path, GF_MAX_PATH-1);
+			if (ssize > 0) {
+				file_path[ssize] = 0;
+				sep = strrchr(file_path, '/');
+				if (sep) sep[0] = 0;
+				return 1;
+			}
+			GF_LOG(GF_LOG_ERROR, GF_LOG_CORE, ("Cannot read /proc/self/exe: %s - is procfs mounted?\n", strerror(errno)));
+			return 0;
 		}
 
 #elif defined(GPAC_CONFIG_WIN32)

--- src/wcmConfig.c.orig	2018-02-12 16:43:12 UTC
+++ src/wcmConfig.c
@@ -298,7 +298,7 @@ out:
  */
 static void wcmSplitName(char* devicename, char *basename, char *subdevice, char *tool, size_t len)
 {
-	char *name = strdupa(devicename);
+	char *name = strdup(devicename);
 	char *a, *b;
 
 	*basename = *subdevice = *tool = '\0';
@@ -325,6 +325,7 @@ static void wcmSplitName(char* devicename, char *basen
 		strncat(tool, a+1, len-1);
 	}
 	strncat(basename, name, len-1);
+	free(name);
 }
 
 /**

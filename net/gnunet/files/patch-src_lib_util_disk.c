--- src/lib/util/disk.c.orig	2026-07-07 11:15:07 UTC
+++ src/lib/util/disk.c
@@ -380,7 +380,7 @@ GNUNET_DISK_file_backup (const char *fil)
   target = GNUNET_malloc (slen);
   num = 0;
 
-#if HAVE_RENAMEAT2
+#if HAVE_RENAMEAT2 && defined(RENAME_EXCHANGE)
   {
     int fd;
 

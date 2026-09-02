--- baobab/src/baobab-utils.c.orig	2026-08-25 01:17:32 UTC
+++ baobab/src/baobab-utils.c
@@ -40,15 +40,34 @@
 #include "baobab-utils.h"
 #include "callbacks.h"
 
+/* Returns the pool a mount entry belongs to, or NULL when the mount is not
+ * part of a pool of filesystems sharing their free space.
+ */
+static gchar *
+baobab_get_pool_name (const glibtop_mountentry *entry)
+{
+	const gchar *sep;
+
+	if (g_strcmp0 (entry->type, "zfs") != 0)
+		return NULL;
+
+	sep = strchr (entry->devname, '/');
+
+	return sep ? g_strndup (entry->devname, sep - entry->devname)
+	           : g_strdup (entry->devname);
+}
+
 void
 baobab_get_filesystem (BaobabFS *fs)
 {
 	size_t i;
 	glibtop_mountlist mountlist;
 	glibtop_mountentry *mountentries;
+	GHashTable *pools;
 
 	memset (fs, 0, sizeof *fs);
 
+	pools = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, NULL);
 	mountentries = glibtop_get_mountlist (&mountlist, FALSE);
 
 	for (i = 0; i < mountlist.number; ++i) {
@@ -58,18 +77,40 @@ baobab_get_filesystem (BaobabFS *fs)
 		file = g_file_new_for_path (mountentries[i].mountdir);
 
 		if (!baobab_is_excluded_location (file)) {
+			guint64 used, avail;
+			gchar *pool;
 
 			glibtop_get_fsusage (&fsusage, mountentries[i].mountdir);
 
-			fs->total += fsusage.blocks * fsusage.block_size;
-			fs->avail += fsusage.bfree * fsusage.block_size;
-			fs->used += (fsusage.blocks - fsusage.bfree) * fsusage.block_size;
+			used = (fsusage.blocks - fsusage.bfree) * fsusage.block_size;
+			avail = fsusage.bfree * fsusage.block_size;
+
+			/* Every dataset of a ZFS pool reports the free space of
+			 * the whole pool, so counting it once per mount point
+			 * multiplies the capacity by the number of datasets.
+			 * Used space is real per dataset and stays additive.
+			 */
+			pool = baobab_get_pool_name (&mountentries[i]);
+
+			if (pool != NULL) {
+				if (g_hash_table_contains (pools, pool)) {
+					avail = 0;
+					g_free (pool);
+				} else {
+					g_hash_table_add (pools, pool);
+				}
+			}
+
+			fs->used += used;
+			fs->avail += avail;
+			fs->total += used + avail;
 		}
 
 		g_object_unref (file);
 	}
 
 	g_free (mountentries);
+	g_hash_table_destroy (pools);
 }
 
 static void

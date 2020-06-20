--- glib/gcharset.c.orig	2020-05-20 10:46:43 UTC
+++ glib/gcharset.c
@@ -407,7 +407,7 @@ unalias_lang (char *lang)
   if (g_once_init_enter (&alias_table))
     {
       GHashTable *table = g_hash_table_new (g_str_hash, g_str_equal);
-      read_aliases ("/usr/share/locale/locale.alias", table);
+      read_aliases ("%%LOCALBASE%%/share/locale/locale.alias", table);
       g_once_init_leave (&alias_table, table);
     }
 

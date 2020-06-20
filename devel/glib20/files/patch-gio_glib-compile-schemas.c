--- gio/glib-compile-schemas.c.orig	2020-05-20 10:46:43 UTC
+++ gio/glib-compile-schemas.c
@@ -1232,6 +1232,7 @@ parse_state_start_schema (ParseState  *state,
       return;
     }
 
+#if 0
   if (path && (g_str_has_prefix (path, "/apps/") ||
                g_str_has_prefix (path, "/desktop/") ||
                g_str_has_prefix (path, "/system/")))
@@ -1244,6 +1245,7 @@ parse_state_start_schema (ParseState  *state,
       g_printerr ("%s\n", message);
       g_free (message);
     }
+#endif
 
   state->schema_state = schema_state_new (path, gettext_domain,
                                           extends, extends_name, list_of);

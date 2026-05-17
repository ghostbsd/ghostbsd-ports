--- src/gpm-backlight-helper.c.orig	2026-05-16 18:48:49.150296000 -0300
+++ src/gpm-backlight-helper.c	2026-05-16 18:52:05.765561000 -0300
@@ -30,11 +30,109 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 
+#ifdef __FreeBSD__
+#include <string.h>
+#include <sys/ioctl.h>
+#include <sys/backlight.h>
+#include <dirent.h>
+#endif
+
 #define GCM_BACKLIGHT_HELPER_EXIT_CODE_SUCCESS			0
 #define GCM_BACKLIGHT_HELPER_EXIT_CODE_FAILED			1
 #define GCM_BACKLIGHT_HELPER_EXIT_CODE_ARGUMENTS_INVALID	3
 #define GCM_BACKLIGHT_HELPER_EXIT_CODE_INVALID_USER		4
 
+#ifdef __FreeBSD__
+
+#define GCM_BACKLIGHT_HELPER_DEV_LOCATION	"/dev/backlight"
+
+/**
+ * gcm_backlight_helper_get_panel_device:
+ *
+ * Find the first BACKLIGHT_TYPE_PANEL device in /dev/backlight/
+ **/
+static gchar *
+gcm_backlight_helper_get_panel_device (void)
+{
+	DIR *dir;
+	struct dirent *de;
+	gchar *result = NULL;
+
+	dir = opendir (GCM_BACKLIGHT_HELPER_DEV_LOCATION);
+	if (dir == NULL)
+		return NULL;
+
+	while ((de = readdir (dir)) != NULL) {
+		gchar *path;
+		struct backlight_info info;
+		int fd;
+
+		if (de->d_name[0] == '.')
+			continue;
+
+		path = g_build_filename (GCM_BACKLIGHT_HELPER_DEV_LOCATION, de->d_name, NULL);
+		fd = open (path, O_RDONLY);
+		if (fd < 0) {
+			g_free (path);
+			continue;
+		}
+
+		if (ioctl (fd, BACKLIGHTGETINFO, &info) == 0) {
+			if (info.type == BACKLIGHT_TYPE_PANEL) {
+				close (fd);
+				result = path;
+				break;
+			}
+		}
+		close (fd);
+		g_free (path);
+	}
+	closedir (dir);
+
+	return result;
+}
+
+static gint
+gcm_backlight_helper_get_brightness (const gchar *path)
+{
+	struct backlight_props props;
+	int fd;
+
+	fd = open (path, O_RDONLY);
+	if (fd < 0)
+		return -1;
+
+	if (ioctl (fd, BACKLIGHTGETSTATUS, &props) != 0) {
+		close (fd);
+		return -1;
+	}
+	close (fd);
+	return (gint) props.brightness;
+}
+
+static gboolean
+gcm_backlight_helper_set_brightness (const gchar *path, gint value)
+{
+	struct backlight_props props;
+	int fd;
+
+	fd = open (path, O_RDWR);
+	if (fd < 0)
+		return FALSE;
+
+	memset (&props, 0, sizeof (props));
+	props.brightness = (uint32_t) value;
+
+	if (ioctl (fd, BACKLIGHTUPDATESTATUS, &props) != 0) {
+		close (fd);
+		return FALSE;
+	}
+	close (fd);
+	return TRUE;
+}
+
+#else /* Linux */
+
 #define GCM_BACKLIGHT_HELPER_SYSFS_LOCATION			"/sys/class/backlight"
 
 /**
@@ -141,6 +239,8 @@
 	return ret;
 }
 
+#endif /* !__FreeBSD__ */
+
 /**
  * main:
  **/
@@ -152,14 +252,18 @@
 	gint euid;
 	guint retval = 0;
 	const gchar *pkexec_uid_str;
-	GError *error = NULL;
-	gboolean ret = FALSE;
 	gint set_brightness = -1;
 	gboolean get_brightness = FALSE;
 	gboolean get_max_brightness = FALSE;
+#ifdef __FreeBSD__
+	gchar *device_path = NULL;
+#else
+	GError *error = NULL;
+	gboolean ret = FALSE;
 	gchar *filename = NULL;
 	gchar *filename_file = NULL;
 	gchar *contents = NULL;
+#endif
 
 	const GOptionEntry options[] = {
 		{ "set-brightness", '\0', 0, G_OPTION_ARG_INT, &set_brightness,
@@ -195,7 +299,68 @@
 		goto out;
 	}
 
+#ifdef __FreeBSD__
 	/* find device */
+	device_path = gcm_backlight_helper_get_panel_device ();
+	if (device_path == NULL) {
+		g_print ("%s\n", _("No backlights were found on your system"));
+		retval = GCM_BACKLIGHT_HELPER_EXIT_CODE_FAILED;
+		goto out;
+	}
+
+	/* GetBrightness */
+	if (get_brightness) {
+		gint brightness = gcm_backlight_helper_get_brightness (device_path);
+		if (brightness < 0) {
+			g_print ("%s\n", _("Could not get the value of the backlight"));
+			retval = GCM_BACKLIGHT_HELPER_EXIT_CODE_FAILED;
+			goto out;
+		}
+		g_print ("%d", brightness);
+		retval = GCM_BACKLIGHT_HELPER_EXIT_CODE_SUCCESS;
+		goto out;
+	}
+
+	/* GetMaxBrightness -- FreeBSD backlight is always 0-100 */
+	if (get_max_brightness) {
+		g_print ("100");
+		retval = GCM_BACKLIGHT_HELPER_EXIT_CODE_SUCCESS;
+		goto out;
+	}
+
+	/* get calling process */
+	uid = getuid ();
+	euid = geteuid ();
+	if (uid != 0 || euid != 0) {
+		g_print ("%s\n", _("This program can only be used by the root user"));
+		retval = GCM_BACKLIGHT_HELPER_EXIT_CODE_ARGUMENTS_INVALID;
+		goto out;
+	}
+
+	/* check we're not being spoofed */
+	pkexec_uid_str = g_getenv ("PKEXEC_UID");
+	if (pkexec_uid_str == NULL) {
+		g_print ("%s\n", _("This program must only be run through pkexec"));
+		retval = GCM_BACKLIGHT_HELPER_EXIT_CODE_INVALID_USER;
+		goto out;
+	}
+
+	/* SetBrightness */
+	if (set_brightness != -1) {
+		if (!gcm_backlight_helper_set_brightness (device_path, set_brightness)) {
+			g_print ("%s\n", _("Could not set the value of the backlight"));
+			retval = GCM_BACKLIGHT_HELPER_EXIT_CODE_FAILED;
+			goto out;
+		}
+	}
+
+	retval = GCM_BACKLIGHT_HELPER_EXIT_CODE_SUCCESS;
+out:
+	g_free (device_path);
+	return retval;
+
+#else /* Linux */
+	/* find device */
 	filename = gcm_backlight_helper_get_best_backlight ();
 	if (filename == NULL) {
 		/* TRANSLATORS: no backlights found */
@@ -279,5 +444,5 @@
 	g_free (filename_file);
 	g_free (contents);
 	return retval;
+#endif /* !__FreeBSD__ */
 }
-

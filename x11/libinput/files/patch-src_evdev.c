On FreeBSD, libudev-devd's create_evdev_handler() needs an open fd to
successfully populate udev properties (ID_INPUT, ID_INPUT_KEYBOARD, etc.)
via ioctl. The sysctl bit arrays (key_bits, rel_bits, etc.) are not
available on this system, so the handler falls back to open() + ioctl,
using path_to_fd() to find an already-open fd in the process.

The udev_device passed to evdev_device_create() was created before the
device fd was opened, so create_evdev_handler() could not use path_to_fd()
and may have failed to set ID_INPUT* properties. After open_restricted()
opens the fd, create a fresh udev_device: this time path_to_fd() finds
the open fd, ioctls succeed, and properties are correctly populated.

Also handle -EINVAL from cuse-based evdev backends in evdev_sync_device(),
and replace the device fd with /dev/null on dispatch error to allow cuse
backends to release the character device node on detach.

--- src/evdev.c.orig	2026-04-02 01:04:12 UTC
+++ src/evdev.c
@@ -1007,7 +1007,7 @@ evdev_sync_device(struct libinput *libinput, struct ev

 	evdev_device_dispatch_frame(libinput, device, frame);

-	return rc == -EAGAIN ? 0 : rc;
+	return (rc == -EAGAIN || rc == -EINVAL) ? 0 : rc;
 }

 static inline void
@@ -1105,6 +1105,17 @@ evdev_device_dispatch(void *data)

 	if (rc != -EAGAIN && rc != -EINTR) {
 		libinput_remove_source(libinput, device->source);
+		/*
+		 * Dirty hack to allow cuse-based evdev backends to release
+		 * character device file when device has been detached
+		 * but still have it descriptor opened.
+		 * Issuing evdev_device_suspend() here leads to SIGSEGV
+		 */
+		int dummy_fd = open("/dev/null", O_RDONLY | O_CLOEXEC);
+		if (dummy_fd >= 0) {
+			dup2(dummy_fd, device->fd);
+			close(dummy_fd);
+		}
 		device->source = NULL;
 	}
 }
@@ -2251,6 +2262,7 @@
 	struct evdev_device *device = NULL;
 	int rc;
 	int fd = -1;
+	struct udev_device *udev_device_refreshed = NULL;
 	int unhandled_device = 0;
 	const char *devnode = udev_device_get_devnode(udev_device);
 	_autofree_ char *sysname = str_sanitize(udev_device_get_sysname(udev_device));
@@ -2278,6 +2290,25 @@
 		goto err;
 	}

+	/*
+	 * On FreeBSD, libudev-devd's create_evdev_handler() may not populate
+	 * udev properties (ID_INPUT, ID_INPUT_KEYBOARD, etc.) if the device fd
+	 * was not yet open when udev_device_new_from_devnum() was called.
+	 * Now that the fd is open, create a fresh udev_device: path_to_fd()
+	 * will find the open fd and evdev capabilities can be queried via ioctl,
+	 * ensuring ID_INPUT* properties are correctly set.
+	 */
+	{
+		struct stat st;
+		if (fstat(fd, &st) == 0)
+			udev_device_refreshed =
+				udev_device_new_from_devnum(
+					udev_device_get_udev(udev_device),
+					'c', st.st_rdev);
+		if (udev_device_refreshed)
+			udev_device = udev_device_refreshed;
+	}
+
 	if (!evdev_device_have_same_syspath(udev_device, fd))
 		goto err;

@@ -2372,6 +2403,8 @@

 	evdev_notify_added_device(device);

+	if (udev_device_refreshed)
+		udev_device_unref(udev_device_refreshed);
 	return device;

 err_notify:
@@ -2388,5 +2421,7 @@
 		}
 	}

+	if (udev_device_refreshed)
+		udev_device_unref(udev_device_refreshed);
 	return unhandled_device ? EVDEV_UNHANDLED_DEVICE : NULL;
 }
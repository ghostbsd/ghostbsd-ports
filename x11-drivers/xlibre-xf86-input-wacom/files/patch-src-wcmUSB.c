--- src/wcmUSB.c.orig	2018-03-12 16:31:49 UTC
+++ src/wcmUSB.c
@@ -27,8 +27,14 @@
 
 #include <math.h>
+#ifdef __linux__
 #include <asm/types.h>
+/* Not sure if these 2 lines are necessary: */
+#else
+#define LINUX_VERSION_CODE 1
+#define KERNEL_VERSION(a,b,c) 0
+#endif
 #include <linux/input.h>
 #include <sys/utsname.h>
 
 #define MAX_USB_EVENTS 128
 
@@ -304,6 +304,11 @@ static struct WacomModelDesc
 	{ WACOM_VENDOR_ID, 0x314,200000, 200000, &usbIntuosPro,  "Intuos Pro S"		},
 	{ WACOM_VENDOR_ID, 0x315,200000, 200000, &usbIntuosPro,  "Intuos Pro M"		},
 	{ WACOM_VENDOR_ID, 0x317,200000, 200000, &usbIntuosPro,  "Intuos Pro L"		},
+
+	{ WACOM_VENDOR_ID, 0x33B,200000, 200000, &usbIntuos5,    "Intuos Draw small"	},
+	{ WACOM_VENDOR_ID, 0x33C,200000, 200000, &usbIntuos5,    "Intuos Art/Photo/Comic small"},
+	{ WACOM_VENDOR_ID, 0x33D,200000, 200000, &usbIntuos5,    "Intuos Draw medium"	},
+	{ WACOM_VENDOR_ID, 0x33E,200000, 200000, &usbIntuos5,    "Intuos Art medium"	},
 
 	{ WACOM_VENDOR_ID, 0x3F, 200000, 200000, &usbCintiqV5,   "Cintiq 21UX"		},
 	{ WACOM_VENDOR_ID, 0xC5, 200000, 200000, &usbCintiqV5,   "Cintiq 20WSX"		},

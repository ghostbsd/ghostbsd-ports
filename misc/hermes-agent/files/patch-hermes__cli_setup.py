--- hermes_cli/setup.py.orig	2026-07-08 03:11:08 UTC
+++ hermes_cli/setup.py
@@ -2033,6 +2033,7 @@ def setup_gateway(config: dict):
             _is_service_installed,
             _is_service_running,
             supports_systemd_services,
+            supports_freebsd_rc,
             has_conflicting_systemd_units,
             has_legacy_hermes_units,
             install_linux_gateway_from_setup,
@@ -2043,6 +2044,9 @@ def setup_gateway(config: dict):
             launchd_install,
             launchd_start,
             launchd_restart,
+            freebsd_rc_install,
+            freebsd_rc_start,
+            freebsd_rc_restart,
             UserSystemdUnavailableError,
             SystemScopeRequiresRootError,
             _system_scope_wizard_would_need_root,
@@ -2052,7 +2056,8 @@ def setup_gateway(config: dict):
         service_installed = _is_service_installed()
         service_running = _is_service_running()
         supports_systemd = supports_systemd_services()
-        supports_service_manager = supports_systemd or _is_macos or _is_windows
+        supports_rc = supports_freebsd_rc()
+        supports_service_manager = supports_systemd or supports_rc or _is_macos or _is_windows
 
         print()
         if supports_systemd and has_conflicting_systemd_units():
@@ -2070,6 +2075,8 @@ def setup_gateway(config: dict):
                 try:
                     if supports_systemd:
                         systemd_restart()
+                    elif supports_rc:
+                        freebsd_rc_restart()
                     elif _is_macos:
                         launchd_restart()
                     elif _is_windows:
@@ -2095,6 +2102,8 @@ def setup_gateway(config: dict):
                 try:
                     if supports_systemd:
                         systemd_start()
+                    elif supports_rc:
+                        freebsd_rc_start()
                     elif _is_macos:
                         launchd_start()
                     elif _is_windows:
@@ -2112,6 +2121,8 @@ def setup_gateway(config: dict):
         elif supports_service_manager:
             if supports_systemd:
                 svc_name = "systemd"
+            elif supports_rc:
+                svc_name = "rc.d"
             elif _is_macos:
                 svc_name = "launchd"
             else:
@@ -2126,6 +2137,9 @@ def setup_gateway(config: dict):
                     started_inline = False
                     if supports_systemd:
                         installed_scope, did_install = install_linux_gateway_from_setup(force=False)
+                    elif supports_rc:
+                        freebsd_rc_install(force=False)
+                        did_install = True
                     elif _is_macos:
                         launchd_install(force=False)
                         did_install = True
@@ -2143,6 +2157,8 @@ def setup_gateway(config: dict):
                         try:
                             if supports_systemd:
                                 systemd_start(system=installed_scope == "system")
+                            elif supports_rc:
+                                freebsd_rc_start()
                             elif _is_macos:
                                 launchd_start()
                         except UserSystemdUnavailableError as e:

--- bsd-user/freebsd/os-socket.c.orig	2019-03-18 23:38:22 UTC
+++ bsd-user/freebsd/os-socket.c
@@ -28,13 +28,12 @@ abi_long t2h_freebsd_cmsg(struct msghdr *msgh,
         struct target_msghdr *target_msgh)
 {
     struct cmsghdr *cmsg = CMSG_FIRSTHDR(msgh);
-    abi_long msg_controllen;
+    socklen_t msg_controllen;
     abi_ulong target_cmsg_addr;
     struct target_cmsghdr *target_cmsg;
     socklen_t space = 0;
 
-
-    msg_controllen = tswapal(target_msgh->msg_controllen);
+    msg_controllen = tswap32(target_msgh->msg_controllen);
     if (msg_controllen < sizeof(struct target_cmsghdr)) {
         goto the_end;
     }
@@ -46,7 +45,7 @@ abi_long t2h_freebsd_cmsg(struct msghdr *msgh,
     while (cmsg && target_cmsg) {
         void *data = CMSG_DATA(cmsg);
         void *target_data = TARGET_CMSG_DATA(target_cmsg);
-        int len = tswapal(target_cmsg->cmsg_len) -
+        int len = tswap32(target_cmsg->cmsg_len) -
             TARGET_CMSG_ALIGN(sizeof(struct target_cmsghdr));
         space += CMSG_SPACE(len);
         if (space > msgh->msg_controllen) {
@@ -87,7 +86,7 @@ abi_long t2h_freebsd_cmsg(struct msghdr *msgh,
     unlock_user(target_cmsg, target_cmsg_addr, 0);
 
 the_end:
-    msgh->msg_controllen = space;
+    msgh->msg_controllen = tswap32(space);
     return 0;
 }
 
@@ -95,12 +94,12 @@ abi_long h2t_freebsd_cmsg(struct target_msghdr *target
         struct msghdr *msgh)
 {
     struct cmsghdr *cmsg = CMSG_FIRSTHDR(msgh);
-    abi_long msg_controllen;
+    socklen_t msg_controllen;
     abi_ulong target_cmsg_addr;
     struct target_cmsghdr *target_cmsg;
     socklen_t space = 0;
 
-    msg_controllen = tswapal(target_msgh->msg_controllen);
+    msg_controllen = tswap32(target_msgh->msg_controllen);
     if (msg_controllen < sizeof(struct target_cmsghdr)) {
         goto the_end;
     }
@@ -123,7 +122,7 @@ abi_long h2t_freebsd_cmsg(struct target_msghdr *target
         }
         target_cmsg->cmsg_level = tswap32(cmsg->cmsg_level);
         target_cmsg->cmsg_type = tswap32(cmsg->cmsg_type);
-        target_cmsg->cmsg_len = tswapal(TARGET_CMSG_LEN(len));
+        target_cmsg->cmsg_len = tswap32(TARGET_CMSG_LEN(len));
         if ((cmsg->cmsg_level == TARGET_SOL_SOCKET) &&
             (cmsg->cmsg_type == SCM_RIGHTS)) {
             int *fd = (int *)data;
@@ -153,7 +152,7 @@ abi_long h2t_freebsd_cmsg(struct target_msghdr *target
     unlock_user(target_cmsg, target_cmsg_addr, space);
 
 the_end:
-    target_msgh->msg_controllen = tswapal(space);
+    target_msgh->msg_controllen = tswap32(space);
     return 0;
 }
 

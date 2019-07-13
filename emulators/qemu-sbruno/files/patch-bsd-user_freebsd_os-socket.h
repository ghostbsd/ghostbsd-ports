--- bsd-user/freebsd/os-socket.h.orig	2019-03-18 23:38:22 UTC
+++ bsd-user/freebsd/os-socket.h
@@ -54,8 +54,8 @@ static inline abi_long do_freebsd_sendmsg(int fd, abi_
         msg.msg_name = NULL;
         msg.msg_namelen = 0;
     }
-    if (tswapal(msgp->msg_controllen) > 0) {
-        msg.msg_controllen = 2 * tswapal(msgp->msg_controllen);
+    if (tswap32(msgp->msg_controllen) > 0) {
+        msg.msg_controllen = 2 * tswap32(msgp->msg_controllen);
         msg.msg_control = alloca(msg.msg_controllen);
         msg.msg_flags = tswap32(msgp->msg_flags);
     } else {
@@ -64,7 +64,7 @@ static inline abi_long do_freebsd_sendmsg(int fd, abi_
         msg.msg_flags = 0;
     }
 
-    count = tswapal(msgp->msg_iovlen);
+    count = tswap32(msgp->msg_iovlen);
     target_vec = tswapal(msgp->msg_iov);
     vec = lock_iovec(VERIFY_READ, target_vec, count, 1);
     msg.msg_iovlen = count;
@@ -107,11 +107,11 @@ static inline abi_long do_freebsd_recvmsg(int fd, abi_
         msg.msg_name = NULL;
         msg.msg_namelen = 0;
     }
-    msg.msg_controllen = 2 * tswapal(msgp->msg_controllen);
+    msg.msg_controllen = 2 * tswap32(msgp->msg_controllen);
     msg.msg_control = alloca(msg.msg_controllen);
     msg.msg_flags = tswap32(msgp->msg_flags);
 
-    count = tswapal(msgp->msg_iovlen);
+    count = tswap32(msgp->msg_iovlen);
     target_vec = tswapal(msgp->msg_iov);
     vec = lock_iovec(VERIFY_WRITE, target_vec, count, 0);
     msg.msg_iovlen = count;

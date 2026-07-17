--- imap/lmtp_sieve.c.orig	2026-07-15 01:09:36 UTC
+++ imap/lmtp_sieve.c
@@ -55,6 +55,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 
+#include "acl.h"
 #include "annotate.h"
 #include "append.h"
 #include "assert.h"

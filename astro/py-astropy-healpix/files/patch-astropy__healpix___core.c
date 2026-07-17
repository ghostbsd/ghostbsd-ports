-- workaround for https://github.com/astropy/astropy-healpix/issues/321

--- astropy_healpix/_core.c.orig	2026-07-07 20:08:05 UTC
+++ astropy_healpix/_core.c
@@ -310,7 +310,7 @@ static void bit_scan_reverse_loop(
         int64_t  in = *(int64_t *) &args[0][i * steps[0]];
         int    *out =  (int *)     &args[1][i * steps[1]];
         #if __has_include(<stdbit.h>)
-            *out = 63 - stdc_leading_zeros(in);
+            *out = 63 - stdc_leading_zeros((unsigned long long)in);
         #elif defined(_MSC_VER)
             unsigned long index;
             if (_BitScanReverse64(&index, in))

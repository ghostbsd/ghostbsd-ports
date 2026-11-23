--- source/blender/modifiers/intern/MOD_grease_pencil_build.cc.orig
+++ source/blender/modifiers/intern/MOD_grease_pencil_build.cc
@@ -472,7 +472,7 @@
   }
 
   parallel_sort(
-      distances.begin(), distances.end(), [](Pair &a, Pair &b) { return a.value < b.value; });
+      distances.begin(), distances.end(), [](const Pair &a, const Pair &b) { return a.value < b.value; });
 
   Array<int> new_order(curves.curves_num());
   for (const int i : curves.curves_range()) {

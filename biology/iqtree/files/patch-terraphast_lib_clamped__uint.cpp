--- terraphast/lib/clamped_uint.cpp.orig	2026-05-05 02:34:53 UTC
+++ terraphast/lib/clamped_uint.cpp
@@ -90,14 +90,10 @@ template class checked_uint<true>;
 template class checked_uint<true>;
 
 // explicitly instantiate template functions
-template bool operator==(checked_uint<false>, checked_uint<false>);
-template bool operator!=(checked_uint<false>, checked_uint<false>);
 template checked_uint<false> operator+(checked_uint<false>, checked_uint<false>);
 template checked_uint<false> operator*(checked_uint<false>, checked_uint<false>);
 template std::ostream& operator<<(std::ostream&, checked_uint<false>);
 
-template bool operator==(checked_uint<true>, checked_uint<true>);
-template bool operator!=(checked_uint<true>, checked_uint<true>);
 template checked_uint<true> operator+(checked_uint<true>, checked_uint<true>);
 template checked_uint<true> operator*(checked_uint<true>, checked_uint<true>);
 template std::ostream& operator<<(std::ostream&, checked_uint<true>);

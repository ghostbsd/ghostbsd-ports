--- cmake/posix.cmake.orig	2026-07-12 07:07:00 UTC
+++ cmake/posix.cmake
@@ -88,9 +88,6 @@ else()
 
 	if(NOT DISABLE_CURSES)
 		set(CURSES_NEED_NCURSES TRUE)
-		if(NOT APPLE)
-			set(CURSES_NEED_WIDE TRUE)
-		endif()
 		find_package(Curses REQUIRED)
 		set(INCLUDES ${INCLUDES} ${CURSES_INCLUDE_DIRS})
 		set(LIBS ${LIBS} ${CURSES_LIBRARIES})

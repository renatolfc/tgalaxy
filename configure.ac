#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([tgalaxy], [0.1], [renato@renatocunha.com])
AM_INIT_AUTOMAKE(tgalaxy, 0.1)
AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_SUBDIRS(include)

CFLAGS="$CFLAGS -pipe"
LDFLAGS=$LDFLAGS
CXXFLAGS="$CXXFLAGS -pipe"

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AX_CHECK_GLUT

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
#AC_HEADER_STDBOOL
#AC_C_INLINE

# Checks for library functions.
#AC_FUNC_MALLOC

AC_ARG_ENABLE(static,
			  [  --enable-static	Compile a static binary (default: no)])
if test "$enable_static" = "yes"; then
	LDFLAGS="$LDFLAGS -static"
fi

AC_ARG_ENABLE(debug,
			  [  --enable-debug	[Enable debug (default: no)]])
if test "$enable_debug" != "yes"; then
	CXXFLAGS="$CXXFLAGS -O2 -pipe -fsigned-char -fomit-frame-pointer -fexpensive-optimizations -ffast-math"
else
	CXXFLAGS="$CXXFLAGS -O0 -g -fsigned-char -Wsign-compare -Wall"
	CPPFLAGS="$CPPFLAGS -DDEBUG"
fi

AC_CONFIG_FILES([
                 src/Makefile
                 src/include/Makefile
])

AC_OUTPUT([
		   Makefile
])


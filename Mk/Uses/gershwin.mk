# Handle GNUstep related ports for Gershwin
#
# Feature:	gershwin
# Usage:	USES=gershwin
#
# Defined specific dependencies under USE_GERSHWIN
# Expected arguments for USE_GERSHWIN:
#
# base:		depends on the gershwin-libs-base port
# gui:		depends on the gershwin-libs-gui port
# back:		depends on the gershwin-libs-back port
# build:	prepare the build dependencies for a regular Gershwin port
#

.if !defined(_INCLUDE_USES_GERSHWIN_MK)
_INCLUDE_USES_GERSHWIN_MK=	yes
.include "${USESDIR}/gmake.mk"

GNUSTEP_PREFIX?=	/
DEFAULT_LIBVERSION?=	0.0.1

GNUSTEP_SYSTEM_ROOT=		${GNUSTEP_PREFIX}System
GNUSTEP_MAKEFILES=		${GNUSTEP_SYSTEM_ROOT}/Library/Makefiles
GNUSTEP_SYSTEM_LIBRARIES=	${GNUSTEP_SYSTEM_ROOT}/Library/Libraries
GNUSTEP_SYSTEM_HEADERS=		${GNUSTEP_SYSTEM_ROOT}/Library/Headers
GNUSTEP_SYSTEM_TOOLS=		${GNUSTEP_SYSTEM_ROOT}/Library/Tools

GNUSTEP_LOCAL_ROOT=		${GNUSTEP_PREFIX}Local
GNUSTEP_LOCAL_LIBRARIES=	${GNUSTEP_LOCAL_ROOT}/Library/Libraries
GNUSTEP_LOCAL_TOOLS=		${GNUSTEP_LOCAL_ROOT}/Library/Tools

LIB_DIRS+=	${GNUSTEP_SYSTEM_LIBRARIES} \
		${GNUSTEP_LOCAL_LIBRARIES}

.  for a in CFLAGS CPPFLAGS CXXFLAGS OBJCCFLAGS OBJCFLAGS LDFLAGS
MAKE_ENV+=	ADDITIONAL_${a}="${ADDITIONAL_${a}} ${${a}}"
.  endfor
.  for a in FLAGS INCLUDE_DIRS LIB_DIRS
MAKE_ENV+=	ADDITIONAL_${a}="${ADDITIONAL_${a}}"
.  endfor
MAKE_ARGS+=messages=yes

MAKEFILE=	GNUmakefile
#MAKE_ENV+=	GNUSTEP_CONFIG_FILE=${PORTSDIR}/devel/gershwin-tools-make/files/GNUstep.conf
GNU_CONFIGURE_PREFIX=	${GNUSTEP_PREFIX}

.  if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.  else
GNU_ARCH=	${MACHINE_ARCH}
.  endif

PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} VERSION=${PORTVERSION}
PLIST_SUB+=	MAJORVERSION=${PORTVERSION:C/([0-9]).*/\1/1}
PLIST_SUB+=	LIBVERSION=${DEFAULT_LIBVERSION}
PLIST_SUB+=	MAJORLIBVERSION=${DEFAULT_LIBVERSION:C/([0-9]).*/\1/1}

.  if defined(USE_GERSHWIN)
.    if ${USE_GERSHWIN:Mbase}
LIB_DEPENDS+=	libgnustep-base.so:lang/gershwin-libs-base
.    endif

.    if ${USE_GERSHWIN:Mbuild}
PATH:=	${GNUSTEP_SYSTEM_TOOLS}:${GNUSTEP_LOCAL_TOOLS}:${PATH}
MAKE_ENV+=	PATH="${PATH}" GNUSTEP_MAKEFILES="${GNUSTEP_MAKEFILES}" \
		LD_LIBRARY_PATH="${GNUSTEP_SYSTEM_LIBRARIES}:${GNUSTEP_LOCAL_LIBRARIES}"
# All GNUstep things installed from ports should be in the System domain.
# Things installed from source can then freely live in the Local domain without
# conflicts.
MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM
CONFIGURE_ENV+=	PATH="${PATH}" GNUSTEP_MAKEFILES="${GNUSTEP_MAKEFILES}" \
		LD_LIBRARY_PATH="${GNUSTEP_SYSTEM_LIBRARIES}:${GNUSTEP_LOCAL_LIBRARIES}"
BUILD_DEPENDS+=	gershwin-tools-make>0:devel/gershwin-tools-make
# Use gershwin-libobjc2 instead of regular libobjc2
# libobjc2 requires libBlocksRuntime from gershwin-libdispatch (not the system one)
# Use BUILD_DEPENDS for libdispatch to avoid finding system /usr/lib/libBlocksRuntime.so
LIB_DEPENDS+=	libobjc.so.4.6:lang/gershwin-libobjc2
BUILD_DEPENDS+=	/System/Library/Libraries/libBlocksRuntime.so:devel/gershwin-libdispatch
RUN_DEPENDS+=	/System/Library/Libraries/libBlocksRuntime.so:devel/gershwin-libdispatch
OBJCFLAGS+=	-I${GNUSTEP_SYSTEM_HEADERS}
LDFLAGS+=	-L${GNUSTEP_SYSTEM_LIBRARIES} -Wl,-rpath,${GNUSTEP_SYSTEM_LIBRARIES}
# Set up objc compiler env vars (self-contained, no objc.mk dependency)
CONFIGURE_ENV+=	OBJC="${CC}" OBJCFLAGS="${OBJCFLAGS}" LDFLAGS="${LDFLAGS}" \
		LIBS="-L${GNUSTEP_SYSTEM_LIBRARIES} -Wl,-rpath,${GNUSTEP_SYSTEM_LIBRARIES}"
MAKE_ENV+=	OBJC="${CC}" OBJCFLAGS="${OBJCFLAGS}"
# Cache variables for configure runtime tests that may fail in poudriere
# because /System/Library/Libraries is not in ldconfig hints and LD_LIBRARY_PATH
# doesn't work reliably. These tell configure the ObjC compiler works and
# supports -fconstant-string-class (both true for clang + libobjc2).
CONFIGURE_ARGS+=	gs_cv_objc_works=yes \
			gs_cv_objc_compiler_supports_constant_string_class=yes
.    endif

.    if ${USE_GERSHWIN:Mgui}
LIB_DEPENDS+=	libgnustep-gui.so:x11-toolkits/gershwin-libs-gui
.    endif

.    if ${USE_GERSHWIN:Mback}
BUILD_DEPENDS+=	gershwin-libs-back>0:x11-toolkits/gershwin-libs-back
RUN_DEPENDS+=	gershwin-libs-back>0:x11-toolkits/gershwin-libs-back
.    endif

.  endif

.endif

# GhostBSD: standalone port providing LLVM runtime shared libraries
# This allows mesa-dri and other consumers to depend on a minimal
# LLVM package instead of the full devel/llvm17.
PORTNAME=	llvm
DISTVERSION=	17.0.6
CATEGORIES=	devel
MASTER_SITES=	https://github.com/llvm/llvm-project/releases/download/llvmorg-${DISTVERSION}/
PKGNAMESUFFIX=	${LLVM_SUFFIX}-libs
DISTNAME=	llvm-project-${DISTVERSION}.src
DISTFILES=	llvm-project-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	ghostbsd@ghostbsd.org
COMMENT=	LLVM runtime shared libraries
WWW=		https://llvm.org/

.include "${.CURDIR}/../llvm-devel/Makefile.LICENSE"

BUILD_DEPENDS=	swig:devel/swig

LIB_DEPENDS=	libzstd.so:archivers/zstd

LLVM_RELEASE=	${DISTVERSION:C/-rc.*//}
LLVM_MAJOR_MINOR=${LLVM_RELEASE:C/\.[0-9]$//}
LLVM_MAJOR=	${LLVM_MAJOR_MINOR:C/\.[0-9]$//}
LLVM_SUFFIX=	${LLVM_MAJOR}

LLVM_DIR=	llvm${LLVM_SUFFIX}
LLVM_PREFIX=	${PREFIX}/${LLVM_DIR}

USES=		cmake compiler:c++17-lang cpe tar:xz python:build perl5 \
		lua:53 libedit
USE_LDCONFIG=	${LLVM_PREFIX}/lib

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_SOURCE_PATH=	${WRKSRC}/llvm
# Build with same configuration as devel/llvm17 default to ensure ABI compatibility
CMAKE_ARGS=	-DLLVM_BUILD_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_LINK_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_ENABLE_RTTI=ON
CMAKE_ARGS+=	-DLLVM_DEFAULT_TARGET_TRIPLE=${CONFIGURE_TARGET}
CMAKE_ARGS+=	-DLLVM_HOST_TRIPLE=${CONFIGURE_TARGET}
CMAKE_ARGS+=	-DLLVM_PARALLEL_LINK_JOBS=1
CMAKE_ARGS+=	-DLLVM_ENABLE_Z3_SOLVER=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_LIBXML2=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_LIBEDIT=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_TERMINFO=OFF
CMAKE_ARGS+=	-DLLVM_VERSION_SUFFIX=
# Same projects as devel/llvm17 default flavor on amd64
CMAKE_ARGS+=	-DLLVM_ENABLE_PROJECTS="clang;lld;compiler-rt;clang-tools-extra;lldb;mlir;openmp;polly"
CMAKE_ARGS+=	-DCLANG_DEFAULT_OPENMP_RUNTIME=libomp
CMAKE_ARGS+=	-DCOMPILER_RT_INSTALL_PATH=${LLVM_PREFIX}/lib/clang/${LLVM_RELEASE}
CMAKE_ARGS+=	-DLIBOMPTARGET_BUILD_DEVICERTL_BCLIB=OFF
CMAKE_ARGS+=	-DLIBOMPTARGET_DEP_LIBFFI_INCLUDE_DIR=""
CMAKE_ARGS+=	-DLIBOMPTARGET_DEP_LIBFFI_LIBRARIES=""
CMAKE_ARGS+=	-DLUA_INCLUDE_DIR=${LOCALBASE}/include/lua${LUA_VER_STR}
CMAKE_ARGS+=	-DLUA_LIBRARY=${LOCALBASE}/lib/liblua-${LUA_VER}.so
CMAKE_ARGS+=	-DCURSES_INCLUDE_PATH=/usr/include
CMAKE_ARGS+=	-DCURSES_CURSES_LIBRARY=/usr/lib/libcurses.so
CMAKE_ARGS+=	-DCURSES_FORM_LIBRARY=/usr/lib/libform.so
CMAKE_ARGS+=	-DCURSES_NCURSES_LIBRARY=/usr/lib/libncurses.so
CMAKE_ARGS+=	-DPANEL_LIBRARIES=/usr/lib/libpanel.so
# Do not set LLVM_TARGETS_TO_BUILD - builds all targets like BE_STANDARD
CMAKE_ARGS+=	-DLLVM_INCLUDE_TESTS=OFF
CMAKE_ARGS+=	-DLLVM_INCLUDE_EXAMPLES=OFF
CMAKE_ARGS+=	-DLLVM_INCLUDE_BENCHMARKS=OFF
CMAKE_ARGS+=	-DLLVM_INCLUDE_DOCS=OFF

PLIST_SUB+=	LLVM_MAJOR=${LLVM_MAJOR} \
		LLVM_RELEASE=${LLVM_RELEASE} \
		LLVM_MAJOR_MINOR=${LLVM_MAJOR_MINOR} \
		LLVM_SUFFIX=${LLVM_SUFFIX}

.include <bsd.port.pre.mk>

# keep in sync with devel/llvm17/Makefile
.if ${ARCH:Marmv[67]*} && (!defined(CPUTYPE) || ${CPUTYPE:M*soft*} == "")
TARGET_ABI=	-gnueabihf
.elif ${ARCH:Marm*}
TARGET_ABI=	-gnueabi
.else
TARGET_ABI=
.endif

CONFIGURE_TARGET:=${ARCH:C/amd64/x86_64/:C/arm64/aarch64/}-portbld-${OPSYS:tl}${OSREL}${TARGET_ABI}

# Only install the shared libraries (libLLVM, libLTO, libRemarks),
# remove everything else produced by the full build.
post-install:
	@${RM} -r ${STAGEDIR}${LLVM_PREFIX}/bin
	@${RM} -r ${STAGEDIR}${LLVM_PREFIX}/include
	@${RM} -r ${STAGEDIR}${LLVM_PREFIX}/lib/cmake
	@${RM} -r ${STAGEDIR}${LLVM_PREFIX}/lib/clang
	@${RM} -r ${STAGEDIR}${LLVM_PREFIX}/libexec
	@${FIND} ${STAGEDIR}${LLVM_PREFIX}/lib -name "*.a" -delete
	@${FIND} ${STAGEDIR}${LLVM_PREFIX}/lib -name "*.so*" \
		! -name "libLLVM*" ! -name "libLTO*" ! -name "libRemarks*" -delete
	@${RM} -r ${STAGEDIR}${LLVM_PREFIX}/lib/python*
	@${RM} -r ${STAGEDIR}${LLVM_PREFIX}/share

.include <bsd.port.post.mk>
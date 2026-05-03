# GhostBSD: standalone port providing LLVM runtime shared libraries.
# This is based on devel/llvm22 (default flavor) but only installs
# libLLVM, libLTO, and libRemarks.  Builds with identical options and
# patches so the resulting .so files are ABI-compatible with the full port.
PORTNAME=	llvm
DISTVERSION=	22.1.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/llvm/llvm-project/releases/download/llvmorg-${DISTVERSION}/
PKGNAMESUFFIX=	${LLVM_SUFFIX}-libs
DISTNAME=	llvm-project-${DISTVERSION}.src
DISTFILES=	llvm-project-${DISTVERSION}.src${EXTRACT_SUFX}

MAINTAINER=	ghostbsd@ghostbsd.org
COMMENT=	LLVM runtime shared libraries
WWW=		https://llvm.org/

.include "${.CURDIR}/../llvm-devel/Makefile.LICENSE"

LIB_DEPENDS=	libzstd.so:archivers/zstd

LLVM_RELEASE=	${DISTVERSION:C/-rc.*//}
LLVM_MAJOR_MINOR=${LLVM_RELEASE:C/\.[0-9]$//}
LLVM_MAJOR=	${LLVM_MAJOR_MINOR:C/\.[0-9]$//}
LLVM_SUFFIX=	${LLVM_MAJOR}

LLVM_DIR=	llvm${LLVM_SUFFIX}
LLVM_PREFIX=	${PREFIX}/${LLVM_DIR}

# Use patches and templates from the parent llvm22 port
PATCHDIR=	${.CURDIR}/../llvm22/files
FILESDIR=	${.CURDIR}/../llvm22/files

USES=		cmake compiler:c++17-lang cpe tar:xz shebangfix
_USES_PYTHON?=	python:build
USES+=		${_USES_PYTHON}
USE_LDCONFIG=	${LLVM_PREFIX}/lib
SHEBANG_FILES=	\
		clang-tools-extra/clang-include-fixer/find-all-symbols/tool/run-find-all-symbols.py \
		clang-tools-extra/clang-tidy/tool/clang-tidy-diff.py \
		clang-tools-extra/clang-tidy/tool/run-clang-tidy.py \
		clang/tools/clang-format/clang-format-diff.py \
		clang/tools/clang-format/git-clang-format \
		clang/tools/scan-build-py/bin/analyze-build \
		clang/tools/scan-build-py/bin/intercept-build \
		clang/tools/scan-build-py/bin/scan-build \
		clang/tools/scan-build-py/libexec/analyze-c++ \
		clang/tools/scan-build-py/libexec/analyze-cc \
		clang/tools/scan-build-py/libexec/intercept-c++ \
		clang/tools/scan-build-py/libexec/intercept-cc \
		clang/tools/scan-view/bin/scan-view \
		clang/utils/hmaptool/hmaptool \
		llvm/tools/opt-viewer/opt-diff.py \
		llvm/tools/opt-viewer/opt-stats.py \
		llvm/tools/opt-viewer/opt-viewer.py \
		llvm/tools/opt-viewer/optrecord.py \
		llvm/utils/lit/lit.py \
		llvm/utils/llvm-lit/llvm-lit.in

SUB_FILES=	llvm-wrapper.sh
SUB_LIST=	LLVM_PREFIX="${LLVM_PREFIX}" LLVM_SUFFIX="${LLVM_SUFFIX}"

CMAKE_INSTALL_PREFIX=	${LLVM_PREFIX}
CMAKE_SOURCE_PATH=	${WRKSRC}/llvm
CMAKE_ARGS=	-DLLVM_BUILD_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_LINK_LLVM_DYLIB=ON
CMAKE_ARGS+=	-DLLVM_ENABLE_RTTI=ON
CMAKE_ARGS+=	-DLLVM_DEFAULT_TARGET_TRIPLE=${CONFIGURE_TARGET}
CMAKE_ARGS+=	-DLLVM_HOST_TRIPLE=${CONFIGURE_TARGET}
CMAKE_ARGS+=	-DLLVM_PARALLEL_LINK_JOBS=1
CMAKE_ARGS+=	-DLLVM_ENABLE_Z3_SOLVER=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_LIBXML2=OFF
CMAKE_ARGS+=	-DLLVM_ENABLE_LIBEDIT=OFF
CMAKE_ARGS+=	-DLLVM_VERSION_SUFFIX=

# Same options as devel/llvm22 default flavor
OPTIONS_DEFINE=	BE_AMDGPU BE_WASM CLANG COMPILER_RT LLD
OPTIONS_SINGLE=		BACKENDS
OPTIONS_SINGLE_BACKENDS=BE_FREEBSD BE_NATIVE BE_STANDARD

OPTIONS_DEFAULT=	CLANG LLD

# BE_NATIVE for 32-bit
OPTIONS_DEFAULT_armv6=		BE_NATIVE
OPTIONS_DEFAULT_armv7=		BE_NATIVE
OPTIONS_DEFAULT_i386=		BE_NATIVE BE_AMDGPU BE_WASM
OPTIONS_DEFAULT_powerpc=	BE_NATIVE
OPTIONS_DEFAULT_powerpcspe=	BE_NATIVE
# BE for 64-bit (always use default-flavor settings)
OPTIONS_DEFAULT_aarch64=	BE_STANDARD BE_AMDGPU BE_WASM
OPTIONS_DEFAULT_amd64=		BE_STANDARD BE_AMDGPU BE_WASM
OPTIONS_DEFAULT_powerpc64=	BE_STANDARD BE_AMDGPU BE_WASM
OPTIONS_DEFAULT_powerpc64le=	BE_STANDARD BE_AMDGPU BE_WASM
OPTIONS_DEFAULT_riscv64=	BE_STANDARD BE_AMDGPU BE_WASM

OPTIONS_EXCLUDE_armv6=	COMPILER_RT
OPTIONS_EXCLUDE_armv7=	COMPILER_RT

OPTIONS_DEFINE+=	EXTRAS LLDB MLIR OPENMP POLLY
OPTIONS_DEFINE_amd64=	GOLD
OPTIONS_DEFINE_powerpc=	GOLD
OPTIONS_DEFINE_powerpc64=	GOLD
OPTIONS_DEFINE_powerpc64le=	GOLD
OPTIONS_DEFAULT+=	COMPILER_RT EXTRAS LLDB MLIR OPENMP POLLY
OPTIONS_DEFAULT_amd64+=	GOLD
OPTIONS_DEFAULT_powerpc+=	GOLD
OPTIONS_DEFAULT_powerpc64+=	GOLD
OPTIONS_DEFAULT_powerpc64le+=	GOLD

_OPTIONS_EXCLUDE_ptr32=	FLANG MLIR OPENMP POLLY
OPTIONS_EXCLUDE_armv6+=	${_OPTIONS_EXCLUDE_ptr32}
OPTIONS_EXCLUDE_armv7+=	${_OPTIONS_EXCLUDE_ptr32}
OPTIONS_EXCLUDE_i386=	${_OPTIONS_EXCLUDE_ptr32}
OPTIONS_EXCLUDE_powerpc=	${_OPTIONS_EXCLUDE_ptr32}
OPTIONS_EXCLUDE_riscv64=	LLDB

BE_AMDGPU_DESC=		AMD GPU backend (required by mesa)
BE_FREEBSD_DESC=	Backends for FreeBSD architectures
BE_FREEBSD_CMAKE_ON=	-DLLVM_TARGETS_TO_BUILD="${FREEBSD_BACKENDS:ts;}"
BE_NATIVE_DESC=		Backend(s) for this architecture (${_NATIVE_BACKENDS})
BE_NATIVE_CMAKE_ON=	-DLLVM_TARGETS_TO_BUILD="${NATIVE_BACKENDS:ts;}"
BE_STANDARD_DESC=	All non-experimental backends
BE_WASM_DESC=		WebAssembly backend (required by firefox via wasi)
CLANG_DESC=	Build clang
CLANG_CMAKE_ON=		-DCLANG_DEFAULT_OPENMP_RUNTIME=libomp
CLANG_USES=		perl5
COMPILER_RT_DESC=	Sanitizer libraries
COMPILER_RT_CMAKE_ON=	\
	-DCOMPILER_RT_INSTALL_PATH=${LLVM_PREFIX}/lib/clang/${LLVM_RELEASE} \
	-DCOMPILER_RT_DEFAULT_TARGET_ONLY=On
COMPILER_RT_CONFLICTS_BUILD=${ARCH}-binutils
EXTRAS_DESC=		Extra clang tools
EXTRAS_IMPLIES=		CLANG
GOLD_DESC=		Build the LLVM Gold plugin for LTO
GOLD_BUILD_DEPENDS=	${LOCALBASE}/bin/ld.gold:devel/binutils
GOLD_CMAKE_ON=		-DLLVM_BINUTILS_INCDIR=${LOCALBASE}/include
GOLD_EXTRA_PATCHES_OFF=	${PATCHDIR}/gold-off-llvm_tools_CMakeLists.txt
LLD_DESC=		Install lld, the LLVM linker
LLDB_BUILD_DEPENDS=	\
	${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
	swig:devel/swig
LLDB_CMAKE_ON= \
	-DLUA_INCLUDE_DIR=${LOCALBASE}/include/lua${LUA_VER_STR} \
	-DLUA_LIBRARY=${LOCALBASE}/lib/liblua-${LUA_VER}.so \
	-DCURSES_INCLUDE_PATH=/usr/include \
	-DCURSES_CURSES_LIBRARY=/usr/lib/libcurses.so \
	-DCURSES_FORM_LIBRARY=/usr/lib/libform.so \
	-DCURSES_NCURSES_LIBRARY=/usr/lib/libncurses.so \
	-DLLDB_ENABLE_PYTHON_LIMITED_API=OFF \
	-DPANEL_LIBRARIES=/usr/lib/libpanel.so
LLDB_DESC=		Install lldb, the LLVM debugger
LLDB_IMPLIES=		CLANG
LLDB_USES=		gnome lua:54 libedit
LLDB_USE=		gnome=libxml2
LLDB_VARS=		_USES_PYTHON=python
MLIR_DESC=		Multi-Level Intermediate Representation
OPENMP_DESC=		Install libomp, the LLVM OpenMP runtime library
OPENMP_CMAKE_ON= \
	-DLIBOMPTARGET_BUILD_DEVICERTL_BCLIB=OFF \
	-DLIBOMPTARGET_DEP_LIBFFI_INCLUDE_DIR="" \
	-DLIBOMPTARGET_DEP_LIBFFI_LIBRARIES=""
POLLY_DESC=		Polyhedral loop and data-locality optimizer

.if defined(WITH_DEBUG)
CMAKE_BUILD_TYPE=	RelWithDebInfo
STRIP=
.endif

PLIST_SUB+=	LLVM_MAJOR=${LLVM_MAJOR} \
		LLVM_MAJOR_MINOR=${LLVM_MAJOR_MINOR} \
		LLVM_SUFFIX=${LLVM_SUFFIX}

.include <bsd.port.options.mk>

# keep in sync with /usr/src/lib/clang/clang.build.mk
# ----------- start of sync block ------------------
.if ${ARCH:Marmv[67]*} && (!defined(CPUTYPE) || ${CPUTYPE:M*soft*} == "")
TARGET_ABI=	-gnueabihf
.elif ${ARCH:Marm*}
TARGET_ABI=	-gnueabi
.else
TARGET_ABI=
.endif

CONFIGURE_TARGET:=${ARCH:C/amd64/x86_64/:C/arm64/aarch64/}-portbld-${OPSYS:tl}${OSREL}${TARGET_ABI}
# ----------- end of sync block --------------------

.if ${PORT_OPTIONS:MCLANG}
LLVM_ENABLE_PROJECTS+=	clang
.endif

.if ${PORT_OPTIONS:MCOMPILER_RT}
LLVM_ENABLE_RUNTIMES+=	compiler-rt
.endif

.if ${PORT_OPTIONS:MEXTRAS}
LLVM_ENABLE_PROJECTS+=	clang-tools-extra
.endif

.if ${PORT_OPTIONS:MLLD}
LLVM_ENABLE_PROJECTS+=	lld
.endif

.if ${PORT_OPTIONS:MLLDB}
LLVM_ENABLE_PROJECTS+=	lldb
.endif

.if ${PORT_OPTIONS:MMLIR}
LLVM_ENABLE_PROJECTS+=	mlir
.endif

.if ${PORT_OPTIONS:MOPENMP}
LLVM_ENABLE_RUNTIMES+=	openmp
USE_LDCONFIG+=	${LLVM_PREFIX}/lib/${CONFIGURE_TARGET}
.endif

.if ${PORT_OPTIONS:MPOLLY}
LLVM_ENABLE_PROJECTS+=	polly
.endif

.if defined(LLVM_ENABLE_PROJECTS)
CMAKE_ARGS+=	-DLLVM_ENABLE_PROJECTS="${LLVM_ENABLE_PROJECTS:ts;}"
.endif
.if defined(LLVM_ENABLE_RUNTIMES)
CMAKE_ARGS+=	-DLLVM_ENABLE_RUNTIMES="${LLVM_ENABLE_RUNTIMES:ts;}"
.endif

.include <bsd.port.pre.mk>

_FREEBSD_BACKENDS=	AArch64 ARM Mips PowerPC RISCV Sparc X86
FREEBSD_BACKENDS=	${_FREEBSD_BACKENDS}
.if ${ARCH} == amd64
_NATIVE_BACKENDS=	X86
.elif ${ARCH} == aarch64
_NATIVE_BACKENDS=	AArch64 ARM
.elif ${ARCH:Marmv*}
_NATIVE_BACKENDS=	ARM
.elif ${ARCH} == i386
_NATIVE_BACKENDS=	X86
.elif ${ARCH:Mmips*}
_NATIVE_BACKENDS=	Mips
.elif ${ARCH:Mpowerpc*}
_NATIVE_BACKENDS=	PowerPC
.elif ${ARCH:Mriscv*}
_NATIVE_BACKENDS=	RISCV
.endif
NATIVE_BACKENDS=	${_NATIVE_BACKENDS}
.if ${PORT_OPTIONS:MBE_AMDGPU}
FREEBSD_BACKENDS+=	AMDGPU
NATIVE_BACKENDS+=	AMDGPU
.endif
.if ${PORT_OPTIONS:MBE_WASM}
FREEBSD_BACKENDS+=	WebAssembly
NATIVE_BACKENDS+=	WebAssembly
.endif
STANDARD_BACKENDS=	${_FREEBSD_BACKENDS} AMDGPU AVR BPF Hexagon Lanai \
			LoongArch MSP430 NVPTX SPIRV SystemZ VE WebAssembly \
			XCore

.if ${ARCH} == "armv6"
BUILD_DEPENDS+=	${LOCALBASE}/bin/ld:devel/binutils
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

post-patch:
	${REINPLACE_CMD} -e 's|import lit|import lit${LLVM_SUFFIX}|' \
	    -e 's|from lit|from lit${LLVM_SUFFIX}|' \
	    -e 's|lit\.|lit${LLVM_SUFFIX}.|g' \
	    ${WRKSRC}/llvm/utils/lit/lit.py \
	    ${WRKSRC}/llvm/utils/lit/lit/*.py \
	    ${WRKSRC}/llvm/utils/lit/lit/formats/*.py
	${REINPLACE_CMD} -e 's,/usr/local/,${LOCALBASE}/,' \
	    ${WRKSRC}/llvm/CMakeLists.txt

post-patch-CLANG-on:
	${REINPLACE_CMD} -e 's|%%LLVM_PREFIX%%|${LLVM_PREFIX}|' \
	    ${WRKSRC}/clang/lib/Driver/ToolChains/CommonArgs.cpp
	${REINPLACE_CMD} -e 's|%%LLVM_SUFFIX%%|${LLVM_SUFFIX}|' \
	    ${WRKSRC}/clang/tools/clang-format/clang-format.py \
	    ${WRKSRC}/clang/tools/clang-format/clang-format-sublime.py \
	    ${WRKSRC}/clang/tools/clang-format/git-clang-format

post-patch-LLD-on:
	${REINPLACE_CMD} -e "s|'indexsidebar.html'|['indexsidebar.html']|" \
	    ${WRKSRC}/lld/docs/conf.py

# Only install the shared libraries (libLLVM, libLTO, libRemarks).
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
	@${RM} -r ${STAGEDIR}${LLVM_PREFIX}/lib/${CONFIGURE_TARGET}
	@${RM} -r ${STAGEDIR}${LLVM_PREFIX}/share
	@${RM} -r ${STAGEDIR}${PREFIX}/bin
	@${RM} -r ${STAGEDIR}${PREFIX}/share

.include <bsd.port.post.mk>
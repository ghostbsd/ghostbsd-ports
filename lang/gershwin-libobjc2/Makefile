PORTNAME=	libobjc2
DISTVERSION=	20260129
CATEGORIES=	lang devel gnustep
PKGNAMEPREFIX=	gershwin-

MAINTAINER=	jpm820@proton.me
COMMENT=	Replacement Objective-C runtime for Gershwin
WWW=		https://github.com/gnustep/libobjc2

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/include/tsl/robin_map.h:devel/robin-map \
		gershwin-libdispatch>0:devel/gershwin-libdispatch \
		gershwin-tools-make>0:devel/gershwin-tools-make

CONFLICTS_INSTALL=	libobjc2

USES=		cmake compiler objc:compiler
USE_LDCONFIG=	/System/Library/Libraries
NO_MTREE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_TAGNAME=	4148a3d06381658b5c4f8b6401aee68d6852a123

LDFLAGS+=	-lm

CMAKE_INSTALL_PREFIX=	/
CMAKE_ARGS+=	-DGNUSTEP_INSTALL_TYPE=SYSTEM \
		-DCMAKE_BUILD_TYPE=Release \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++ \
		-DEMBEDDED_BLOCKS_RUNTIME=OFF \
		-DBlocksRuntime_INCLUDE_DIR=/System/Library/Headers \
		-DBlocksRuntime_LIBRARIES=/System/Library/Libraries/libBlocksRuntime.so \
		-DCMAKE_REQUIRED_LINK_OPTIONS="-L/System/Library/Libraries" \
		-DLIB_INSTALL_PATH=System/Library/Libraries \
		-DHEADER_INSTALL_PATH=System/Library/Headers \
		-DCMAKE_INSTALL_RPATH=/System/Library/Libraries \
		-DCMAKE_BUILD_RPATH=/System/Library/Libraries

LDFLAGS_armv7=	-Wl,-znotext
SSP_UNSAFE=	yes

PLIST_SUB+=	SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

SHLIB_MAJOR=	4
SHLIB_MINOR=	6

.include <bsd.port.pre.mk>

.if ${ARCH:Mpowerpc*} || ${ARCH:Mriscv64*}
CMAKE_ARGS+=	-DTESTS:BOOL=OFF
.endif

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-stdlib=libstdc++
.endif

post-install:
	${LN} -sf libobjc.so.${SHLIB_MAJOR}.${SHLIB_MINOR} ${STAGEDIR}/System/Library/Libraries/libobjc.so.${SHLIB_MAJOR}
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/ldconfig
	${ECHO} "/System/Library/Libraries" > ${STAGEDIR}${PREFIX}/libdata/ldconfig/gershwin

.include <bsd.port.post.mk>

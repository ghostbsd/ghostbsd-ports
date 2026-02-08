PORTNAME=	libdispatch
DISTVERSION=	20260129
CATEGORIES=	devel
PKGNAMEPREFIX=	gershwin-

MAINTAINER=	jpm820@proton.me
COMMENT=	Grand Central Dispatch API support library for Gershwin
WWW=		https://github.com/swiftlang/swift-corelibs-libdispatch

LICENSE=	APACHE20

CONFLICTS_INSTALL=	libdispatch

USES=		cmake compiler:c++17-lang
USE_LDCONFIG=	/System/Library/Libraries
USE_CXXSTD=	c++17
NO_MTREE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	swiftlang
GH_PROJECT=	swift-corelibs-libdispatch
GH_TAGNAME=	swift-6.1.1-RELEASE

CMAKE_ARGS=	-DCMAKE_INSTALL_PREFIX=/System/Library \
		-DCMAKE_INSTALL_LIBDIR=/System/Library/Libraries \
		-DINSTALL_DISPATCH_HEADERS_DIR=/System/Library/Headers/dispatch \
		-DINSTALL_BLOCK_HEADERS_DIR=/System/Library/Headers \
		-DINSTALL_OS_HEADERS_DIR=/System/Library/Headers/os \
		-DINSTALL_PRIVATE_HEADERS=ON \
		-DCMAKE_INSTALL_MANDIR=/System/Library/Documentation/man \
		-DCMAKE_C_COMPILER=clang \
		-DCMAKE_CXX_COMPILER=clang++


.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc)
CFLAGS+=	-Wno-incompatible-function-pointer-types
.endif

.include <bsd.port.mk>

PORTNAME=	tools-make
DISTVERSION=	20260129
CATEGORIES=	devel gnustep
PKGNAMEPREFIX=	gershwin-

MAINTAINER=	jpm820@proton.me
COMMENT=	GNUstep makefile package
WWW=		http://www.gnustep.org/

LICENSE=	GPLv3

BUILD_DEPENDS=	gershwin-libdispatch>0:devel/gershwin-libdispatch

USES=		gershwin objc:compiler
CONFLICTS=	gnustep-make
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_TAGNAME=	8964f83f4564c18efb73296bf2e75339c93665bf

MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c"

pre-configure:
	${CP} ${FILESDIR}/GNUstep.conf ${WRKSRC}/FilesystemLayouts/gershwin

CONFIGURE_ARGS+= \
	--with-config-file=/System/Library/Preferences/GNUstep.conf \
	--with-layout=gershwin \
	--with-library-combo=ng-gnu-gnu \
	--enable-objc-nonfragile-abi \
	--with-objc-lib-flag=" " \
	LDFLAGS="-L/System/Library/Libraries -Wl,-rpath,/System/Library/Libraries" \
	CPPFLAGS="-I/System/Library/Headers" \
	libobjc_LIBS=" "

GNU_CONFIGURE_PREFIX= ${GNUSTEP_PREFIX}
NO_ARCH=	yes

.include <bsd.port.mk>

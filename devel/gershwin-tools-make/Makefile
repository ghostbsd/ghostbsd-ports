PORTNAME=	tools-make
DISTVERSION=	2025061501
CATEGORIES=	devel gnustep
PKGNAMEPREFIX=	gershwin-

MAINTAINER=	jpm820@proton.me
COMMENT=	GNUstep makefile package
WWW=		http://www.gnustep.org/

LICENSE=	GPLv3

USES=		gershwin objc
CONFLICTS=	gnustep-make
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_TAGNAME=	faa64aa

MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
CONFIGURE_ENV+=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c"

pre-configure:
	${CP} ${FILESDIR}/GNUstep.conf ${WRKSRC}/FilesystemLayouts/gershwin

CONFIGURE_ARGS+= \
	--with-config-file=/System/Library/Preferences/GNUstep.conf \
	--with-layout=gershwin \
	--with-library-combo=ng-gnu-gnu

GNU_CONFIGURE_PREFIX= ${GNUSTEP_PREFIX}
NO_ARCH=	yes

.include <bsd.port.mk>

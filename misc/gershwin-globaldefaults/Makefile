PORTNAME=	gershwin-globaldefaults
DISTVERSION=	2025062103
CATEGORIES=	misc
MASTER_SITES=	GH

MAINTAINER=	jpm820@proton.me
COMMENT=	Gershwin global defaults for GNUstep under /System
WWW=		https://github.com/gershwin-os/gershwin-globaldefaults

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-os
GH_TAGNAME=	750e040

NO_ARCH=	yes
NOPREFIX=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/System/Library/Preferences/GlobalDefaults
	${INSTALL_DATA} ${WRKSRC}/System/Library/Preferences/GlobalDefaults/*.plist \
		${STAGEDIR}/System/Library/Preferences/GlobalDefaults

.include <bsd.port.mk>

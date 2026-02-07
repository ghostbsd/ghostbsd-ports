PORTNAME=	gershwin-system
DISTVERSION=	20260129
CATEGORIES=	misc
MASTER_SITES=	GH

MAINTAINER=	jpm820@proton.me
COMMENT=	Gershwin global defaults for GNUstep under /System
WWW=		https://github.com/gershwin-desktop/gershwin-system

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-desktop
GH_TAGNAME=	f4ce91f


NO_ARCH=	yes
NOPREFIX=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/System/Library/Preferences/GlobalDefaults
	${INSTALL_DATA} ${WRKSRC}/Library/Preferences/GlobalDefaults/*.plist \
		${STAGEDIR}/System/Library/Preferences/GlobalDefaults

.include <bsd.port.mk>

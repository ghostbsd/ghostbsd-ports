PORTNAME=	gershwin-ghostbsd-wrappers
DISTVERSION=	20250710
CATEGORIES=	sysutils gnustep

MAINTAINER=	jpm820@proton.me
COMMENT=	Wrappers for GhostBSD apps
WWW=		https://github.com/gershwin-desktop/ghostbsd-gershwin-wrappers

LICENSE=	BSD3CLAUSE

USES=		gershwin
USE_GERSHWIN=	back build

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-desktop
GH_TAGNAME=	d912804

MAKE_ARGS+=     GNUSTEP_INSTALLATION_DOMAIN=LOCAL

ALL_TARGET=     all
INSTALL_TARGET= install-apps

post-install:
	@${MKDIR} ${STAGEDIR}/Library
	${CP} -R ${WRKSRC}/Library/Tools ${STAGEDIR}/Library/

.include <bsd.port.mk>

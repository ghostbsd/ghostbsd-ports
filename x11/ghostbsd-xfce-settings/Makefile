# Created by: Angelescu Ovidiu  <angelescuo@yahoo.com>
# $FreeBSD$

PORTNAME=	ghostbsd-xfce-settings
PORTVERSION=	3.5
CATEGORIES=	x11

MAINTAINER=	eturgeon@ixsystems.com
COMMENT=	GhostBSD xfce settings in installed mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/xdg
	${CP} -R   ${WRKSRC}/etc/xdg/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/xdg
.include <bsd.port.mk>

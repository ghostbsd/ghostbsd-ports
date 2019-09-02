# New ports collection makefile for: xfce settings in installed mode
# Date created:        17 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-xfce-settings
PORTVERSION=	2.9
CATEGORIES=	x11

MAINTAINER=	eturgeon@ixsystems.com
COMMENT=	GhostBSD xfce settings in installed mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/skel
	${CP} -R   ${WRKSRC}/etc/skel/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/skel
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/xdg
	${CP} -R   ${WRKSRC}/etc/xdg/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/xfce-installed-settings/etc/xdg
.include <bsd.port.mk>

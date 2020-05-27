# New ports collection makefile for: ghostbsd gnome  settings in installed mode
# Date created:        27 may 2020
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME=	ghostbsd-gnome-settings
PORTVERSION=	1.1
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD gnome settings in installed mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	glib-compile-schemas:devel/glib20 \
		dpkg:archivers/dpkg \
		${LOCALBASE}/share/gnome-background-properties/ghostbsd.xml:x11-themes/ghostbsd-wallpapers
NO_BUILD=	

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/gnome-installed-settings
	${CP} -R   ${WRKSRC}/ghostbsd/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/gnome-installed-settings
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/gnome-background-properties
	${CP} ${WRKSRC}/gnome-background-properties/ghostbsd.xml ${STAGEDIR}/${PREFIX}/share/gnome-background-properties
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
	${CP} -R   ${WRKSRC}/schemas/* ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
.include <bsd.port.mk>

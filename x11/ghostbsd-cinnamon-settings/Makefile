# New ports collection makefile for: cinnamon settings in installed mode
# Date created:        17 may 2015
# Whom:                angelescuo@yahoo.com
#
# $FreeBSD$
#

PORTNAME= 	ghostbsd-cinnamon-settings
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD cinnamon settings in installed mode
LICENSE =	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	glib-compile-schemas:${PORTSDIR}/devel/glib20 \
		 dpkg:${PORTSDIR}/archivers/dpkg \
		 ${LOCALBASE}/share/mate-background-properties/ghostbsd.xml:x11-themes/ghostbsd-wallpapers

NO_BUILD=	yes

do-install:
	@${MKDIR} -p ${STAGEDIR}/${PREFIX}/share/ghostbsd/cinnamon-installed-settings
	@${CP} -R   ${WRKSRC}/ghostbsd/* ${STAGEDIR}/${PREFIX}/share/ghostbsd/cinnamon-installed-settings
	@${MKDIR} -p ${STAGEDIR}/${PREFIX}/share/cinnamon-background-properties
	@${CP} ${WRKSRC}/cinnamon-background-properties/ghostbsd.xml ${STAGEDIR}/${PREFIX}/share/cinnamon-background-properties
	@${MKDIR} -p ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
	@${CP} -R   ${WRKSRC}/schemas/* ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
.include <bsd.port.mk>

# Created by: Angelescu Ovidiu <angelescuo@yahoo.com>
# $FreeBSD$

PORTNAME=	ghostbsd-gnome-settings
PORTVERSION=	1.2
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD gnome settings in installed mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	glib-compile-schemas:devel/glib20 \
		dpkg:archivers/dpkg \
		${LOCALBASE}/share/mate-background-properties/ghostbsd.xml:x11-themes/ghostbsd-wallpapers
NO_BUILD=	

do-install:
	${MKDIR} -p ${STAGEDIR}/${PREFIX}/etc
	${CP} -R   ${WRKSRC}/etc/* ${STAGEDIR}/${PREFIX}/etc
	${MKDIR} -p ${STAGEDIR}/${PREFIX}/bin
	${CP} -R   ${WRKSRC}/bin/* ${STAGEDIR}/${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/gnome-background-properties
	${CP} ${WRKSRC}/gnome-background-properties/ghostbsd.xml ${STAGEDIR}/${PREFIX}/share/gnome-background-properties
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
	${CP} -R   ${WRKSRC}/schemas/* ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
.include <bsd.port.mk>

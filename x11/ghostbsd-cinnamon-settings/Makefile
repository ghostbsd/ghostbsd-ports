# Created by:  Angelescu Ovidiu  <angelescuo@yahoo.com>
# $FreeBSD$


PORTNAME= 	ghostbsd-cinnamon-settings
PORTVERSION=	1.10
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
	@${MKDIR} -p ${STAGEDIR}/usr/share/skel
	@${CP} -R   ${WRKSRC}/skel/* ${STAGEDIR}/usr/share/skel
	${MKDIR} -p ${STAGEDIR}/${PREFIX}/etc
	${CP} -R   ${WRKSRC}/etc/* ${STAGEDIR}/${PREFIX}/etc
	${MKDIR} -p ${STAGEDIR}/${PREFIX}/bin
	${CP} -R   ${WRKSRC}/bin/* ${STAGEDIR}/${PREFIX}/bin
	@${MKDIR} -p ${STAGEDIR}/${PREFIX}/share/cinnamon-background-properties
	@${CP} ${WRKSRC}/cinnamon-background-properties/ghostbsd.xml ${STAGEDIR}/${PREFIX}/share/cinnamon-background-properties
	@${MKDIR} -p ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
	@${CP} -R   ${WRKSRC}/schemas/* ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
.include <bsd.port.mk>

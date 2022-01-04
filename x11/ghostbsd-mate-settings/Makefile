# Created by: Angelescu Ovidiu <angelescuo@yahoo.com>
# $FreeBSD$
#

PORTNAME=	ghostbsd-mate-settings
PORTVERSION=	22.02
CATEGORIES=	x11

MAINTAINER=	ericturgeon.bsd@gmail.com
COMMENT=	GhostBSD mate settings in installed mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	glib-compile-schemas:devel/glib20 \
		 dpkg:archivers/dpkg

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/bin
	${CP}    ${WRKSRC}/bin/* ${STAGEDIR}/${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc
	${CP} -R   ${WRKSRC}/etc/* ${STAGEDIR}/${PREFIX}/etc
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
	${CP} -R   ${WRKSRC}/schemas/* ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
.include <bsd.port.mk>

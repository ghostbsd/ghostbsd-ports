PORTNAME=	ghostbsd-mate-settings
PORTVERSION=	26.01.0
CATEGORIES=	x11

MAINTAINER=	ericturgeon.bsd@gmail.com
COMMENT=	GhostBSD mate settings in installed mode
WWW=		http://www.ghostbsd.org/

LICENSE=	BSD

USES=		desktop-file-utils gnome
USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD
USE_GNOME=	glib20

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/bin
	${CP}    ${WRKSRC}/bin/* ${STAGEDIR}/${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc
	${CP} -R   ${WRKSRC}/etc/* ${STAGEDIR}/${PREFIX}/etc
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
	${CP} -R   ${WRKSRC}/schemas/* ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
.include <bsd.port.mk>


PORTNAME=	ghostbsd-wallpapers
PORTVERSION=	22.02
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	22
MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	2022 GhostBSD wallpaper colection

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/backgrounds/ghostbsd
	${CP} -PR ${WRKSRC}/*.jpg ${STAGEDIR}${PREFIX}/share/backgrounds/ghostbsd
	# ${CP} -PR ${WRKSRC}/*.png ${STAGEDIR}${PREFIX}/share/backgrounds/ghostbsd
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mate-background-properties
	${CP} -PR ${WRKSRC}/ghostbsd.xml ${STAGEDIR}${PREFIX}/share/mate-background-properties/ghostbsd${PKGNAMESUFFIX}.xml
.include <bsd.port.mk>

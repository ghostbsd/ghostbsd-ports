
PORTNAME=	ghostbsd-wallpapers
PORTVERSION=	21.12
CATEGORIES=	x11-themes
PKGNAMESUFFIX=	21
MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GhostBSD wallpaper colection

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/backgrounds/ghostbsd
	${CP} -PR ${WRKSRC}/*.jpg ${STAGEDIR}${PREFIX}/share/backgrounds/ghostbsd
	# ${CP} -PR ${WRKSRC}/*.png ${STAGEDIR}${PREFIX}/share/backgrounds/ghostbsd
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mate-background-properties
	${CP} -PR ${WRKSRC}/ghostbsd21.xml ${STAGEDIR}${PREFIX}/share/mate-background-properties/ghostbsd21.xml
.include <bsd.port.mk>

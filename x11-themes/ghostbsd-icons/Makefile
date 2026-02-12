PORTNAME=	ghostbsd-icons
PORTVERSION=	26.01.0
CATEGORIES=	x11-themes

MAINTAINER=	ericturgeon.bsd@gmail.com
COMMENT=	GhostBSD icons for GTK DE
WWW=		http://www.ghostbsd.org/

LICENSE=	CCBYSA
LICENSE_NAME=	CREATIVE COMMON
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept
LICENSE_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/
	${CP} -R ${WRKSRC}/icons/* ${STAGEDIR}${PREFIX}/share/icons
.include <bsd.port.mk>

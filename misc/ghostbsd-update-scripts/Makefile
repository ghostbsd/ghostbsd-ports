
PORTNAME=	ghostbsd-update-scripts
PORTVERSION=	21.08.21
CATEGORIES=	misc

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GhostBSD update scripts

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

SUB_FILES=	pkg-install
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/ghostbsd-update-scripts
	${CP} -PR ${WRKSRC}/change_rc.sh ${STAGEDIR}${PREFIX}/share/ghostbsd-update-scripts/

.include <bsd.port.mk>

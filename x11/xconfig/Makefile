PORTNAME=	xconfig
PORTVERSION=	2.0
CATEGORIES=	x11

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GhostBSD X configuration tool

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/cardDetect
	${CP} -PR ${WRKSRC}/cardDetect/XF86Config.* ${STAGEDIR}${PREFIX}/etc/X11/cardDetect
	${MKDIR} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/xconfig ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>

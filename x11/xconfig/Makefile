PORTNAME=	xconfig
PORTVERSION=	3.0
CATEGORIES=	x11

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GhostBSD X configuration tool
WWW=	https://github.com/ghostbsd/xconfig

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/cardDetect
	${CP} -PR ${WRKSRC}/cardDetect/XF86Config.* ${STAGEDIR}${PREFIX}/etc/X11/cardDetect
	${MKDIR} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/xconfig ${STAGEDIR}/${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/xconfig ${STAGEDIR}${PREFIX}/etc/rc.d/xconfig

.include <bsd.port.mk>

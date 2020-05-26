# Created by: Eric Turgeon <ericturgeon.bsd@gmail.org>
# $FreeBSD$

PORTNAME=	xconfig
PORTVERSION=	0.2
CATEGORIES=	misc

MAINTAINER=	ericturgeon.bsd@gmail.com
COMMENT=	GhostBSD X configuration tool

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/cardDetect
	${CP} -PR ${WRKSRC}/cardDetect/XF86Config.* ${STAGEDIR}${PREFIX}/etc/X11/cardDetect
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/init.d/
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/xconfig ${STAGEDIR}/${PREFIX}/etc/init.d
	${MKDIR} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/xconfig ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>

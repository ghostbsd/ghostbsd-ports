# Created by: Eric Turgeon <ericturgeon.bsd@gmail.org>
# $FreeBSD$

PORTNAME=	ghostbsd-pkg-conf
PORTVERSION=	21.08.27
CATEGORIES=	misc

MAINTAINER=	ericturgeon.bsd@gmail.com
COMMENT=	GhostBSD pkg configuration file

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pkg/repos/
	${CP} -PR ${WRKSRC}${PREFIX}/etc/pkg/repos/* ${STAGEDIR}${PREFIX}/etc/pkg/repos/

.include <bsd.port.mk>

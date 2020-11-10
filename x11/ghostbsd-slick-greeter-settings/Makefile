# Created by: Angelescu Ovidiu <angelescuo@yahoo.com>
# $FreeBSD$

PORTNAME=	ghostbsd-slick-greeter-settings
PORTVERSION=	1.2
PORTSREVISION=	1
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD lightdm slick greeter settings

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/lightdm
	${CP} ${WRKSRC}/slick-greeter.conf ${STAGEDIR}/${PREFIX}/etc/lightdm/slick-greeter.conf.sample
.include <bsd.port.mk>

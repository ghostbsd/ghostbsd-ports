# Created by: Angelescu Ovidiu <angelescuo@yahoo.com>
# $FreeBSD$

PORTNAME=	ghostbsd-slick-greeter-settings
PORTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD lightdm settings

LICENSE=	BSD

RUN_DEPENDS=	lightdm:x11/lightdm \
		slick-greeter:x11/slick-greeter

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

PLIST_FILES=	etc/lightdm/slick-greeter.conf

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/lightdm
	${CP} ${WRKSRC}/slick-greeter.conf ${STAGEDIR}/${PREFIX}/etc/lightdm/
.include <bsd.port.mk>

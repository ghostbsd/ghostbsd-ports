PORTNAME=	ghostbsd-slick-greeter-settings
PORTVERSION=	26.01.0
CATEGORIES=	x11

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GhostBSD lightdm slick greeter settings

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/lightdm
	${CP} ${WRKSRC}/slick-greeter.conf ${STAGEDIR}/${PREFIX}/etc/lightdm/slick-greeter.conf.sample
.include <bsd.port.mk>

PORTNAME=	ghostbsd-slick-greeter-settings
PORTVERSION=	26.01.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GhostBSD lightdm slick greeter settings
WWW=		http://www.ghostbsd.org/

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/lightdm
	${INSTALL_DATA} ${WRKSRC}/slick-greeter.conf \
		${STAGEDIR}${PREFIX}/etc/lightdm/slick-greeter.conf.sample

.include <bsd.port.mk>

# Created by: Angelescu Ovidiu  <angelescuo@yahoo.com>
# $FreeBSD$


PORTNAME=	ghostbsd-slim-theme
PORTVERSION=	1.4
CATEGORIES=	x11

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	GhostBSD theme for slim and autologin too

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	slim:x11/slim \

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/slim/themes/ghostbsd
	${CP} -R ${WRKSRC}/gbsd/* ${STAGEDIR}/${PREFIX}/share/slim/themes/ghostbsd/
	${CP} -R ${WRKSRC}/winter ${STAGEDIR}/${PREFIX}/share/slim/themes/
	${CP} -R ${WRKSRC}/wood ${STAGEDIR}/${PREFIX}/share/slim/themes/
	${CP} -R ${WRKSRC}/forest ${STAGEDIR}/${PREFIX}/share/slim/themes/

.include <bsd.port.mk>

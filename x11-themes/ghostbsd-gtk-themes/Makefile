PORTNAME=	ghostbsd-gtk-themes
PORTVERSION=	26.01.0
CATEGORIES=	x11-themes

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GhostBSD themes for mate flavour

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/themes/
	${CP} -R ${WRKSRC}/themes/* ${STAGEDIR}${PREFIX}/share/themes
.include <bsd.port.mk>

PORTNAME=	ghostbsd-xfce-settings
PORTVERSION=	26.01.0
CATEGORIES=	x11

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GhostBSD xfce settings in installed mode
WWW=		http://www.ghostbsd.org/

LICENSE=	BSD

RUN_DEPENDS=	ghostbsd-wallpapers26>0:x11-themes/ghostbsd-wallpapers26 \
		ghostbsd-xfce4>0:x11/ghostbsd-xfce

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/xdg
	${CP} -R ${WRKSRC}/etc/xdg/* ${STAGEDIR}/${PREFIX}/etc/xdg
.include <bsd.port.mk>

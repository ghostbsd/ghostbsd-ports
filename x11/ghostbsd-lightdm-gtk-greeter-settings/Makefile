# Created by: Angelescu Ovidiu <angelescuo@yahoo.com>
# $FreeBSD$


PORTNAME=	ghostbsd-lightdm-gtk-greeter-settings
PORTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD lightdm gtk greeter settings

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

RUN_DEPENDS=	lightdm:x11/lightdm \
		${LOCALBASE}/etc/lightdm/lightdm-gtk-greeter.conf:x11/lightdm-gtk-greeter \
		${LOCALBASE}/share/themes/Vimix-Dark/index.theme:x11-themes/ghostbsd-mate-themes

NO_BUILD=	yes

PLIST_FILES=	share/ghostbsd/lightdm-gtk-greeter/README.md

do-install:
		${MKDIR} ${STAGEDIR}/${PREFIX}/share/ghostbsd/lightdm-gtk-greeter
		${CP} ${WRKSRC}/README.md ${STAGEDIR}/${PREFIX}/share/ghostbsd/lightdm-gtk-greeter/
		
.include <bsd.port.mk>

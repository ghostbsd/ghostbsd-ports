# Created by: Angelescu Ovidiu <angelescuo@yahoo.com>
# $FreeBSD$


PORTNAME=	ghostbsd-lightdm-gtk-greeter-settings
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	angelescuo@yahoo.com
COMMENT=	GhostBSD lightdm gtk greeter settings

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

USES=		metaport

RUN_DEPENDS=	lightdm:x11/lightdm \
		${LOCALBASE}/etc/lightdm/lightdm-gtk-greeter.conf.sample:x11/lightdm-gtk-greeter \
		${LOCALBASE}/share/themes/Vimix-Dark/index.theme:x11-themes/ghostbsd-mate-themes

NO_BUILD=	yes
NO_MTREE=	yes

.include <bsd.port.mk>

PORTNAME=       xfce4-appmenu-plugin
DISTVERSION=    20250708
CATEGORIES=     x11
PKGNAMEPREFIX=	gershwin-

MAINTAINER=     jpm820@gmail.com
COMMENT=        Application Menu plugin for XFCE panel
WWW=            https://gitlab.com/vala-panel-project/vala-panel-appmenu

LICENSE=        LGPL3
LICENSE_FILE=   ${WRKSRC}/LICENSE

RUN_DEPENDS=    gershwin-appmenu-registrar>=0:x11/gershwin-appmenu-registrar \
		gershwin-appmenu-gtk-module>=0:x11/gershwin-gtk-app-menu

USES=		meson gnome xfce pkgconfig gettext vala:build
CONFLICTS=	xfce4-appmenu-plugin

MESON_ARGS=     -Dvalapanel=disabled \
		-Dxfce=enabled \
		-Dmate=disabled \
		-Dbudgie=disabled \
		-Djayatana=disabled \
		-Dregistrar=disabled \
		-Dappmenu-gtk-module=disabled

USE_XFCE=       panel xfconf
USE_GNOME=      gtk30 glib20 gtk20 gdkpixbuf

USE_GITHUB=     yes
GH_ACCOUNT=     gershwin-desktop
GH_PROJECT=     vala-panel-appmenu
GH_TAGNAME=     4c00900

post-extract:
	@${CP} ${FILESDIR}/meson.build ${WRKSRC}/meson.build
	@${CP} ${FILESDIR}/lib-meson.build ${WRKSRC}/lib/meson.build

.include <bsd.port.mk>

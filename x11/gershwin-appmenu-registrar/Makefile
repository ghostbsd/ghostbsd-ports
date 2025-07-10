PORTNAME=       appmenu-registrar
DISTVERSION=    20250708
CATEGORIES=     x11
PKGNAMEPREFIX=	gershwin-

MAINTAINER=     jpm820@proton.me
COMMENT=        Appmenu DBusMenu registrar
WWW=            https://gitlab.com/vala-panel-project/vala-panel-appmenu/-/tree/master/subprojects/registrar

LICENSE=        LGPL3
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=   meson gnome pkgconfig gettext vala:build
CONFLICTS=	appmenu-registrar

MESON_ARGS=     -Dvalapanel=disabled \
		-Dxfce=disabled \
		-Dmate=disabled \
		-Dbudgie=disabled \
		-Djayatana=disabled \
		-Dregistrar=enabled \
		-Dappmenu-gtk-module=disabled

USE_GNOME=      gtk30 glib20 gdkpixbuf

USE_GITHUB=     yes
GH_ACCOUNT=     gershwin-desktop
GH_PROJECT=     vala-panel-appmenu
GH_TAGNAME=     4c00900

post-extract:
	@${CP} ${FILESDIR}/meson.build ${WRKSRC}/meson.build
	@${CP} ${FILESDIR}/translator-meson.build ${WRKSRC}/subprojects/appmenu-glib-translator/meson.build

.include <bsd.port.mk>

PORTNAME=	gershwin-windowmanager
DISTVERSION=	20260129
CATEGORIES=	x11 gnustep

MAINTAINER=	jpm820@proton.me
COMMENT=	Gershwin window manager combining WindowManager and XCBKit
WWW=		https://github.com/gershwin-desktop/gershwin-windowmanager

LICENSE=	MIT

LIB_DEPENDS=	libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-image.so:x11/xcb-util-image

USES=		gershwin pkgconfig xorg
USE_GERSHWIN=	back build
USE_XORG=	xcb xcomposite xrender xdamage xfixes

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-desktop
GH_TAGNAME=	47b878f

.include <bsd.port.mk>

PORTNAME=	mocka-dock
DISTVERSION=	0.0.1
CATEGORIES=	x11

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	Taskbar-style dock applet for the MATE panel
WWW=		https://github.com/mocka-desktop/mocka-dock

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gettext-tools gnome mate meson pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	mocka-desktop
USE_GNOME=	cairo glib20 gtk30 libwnck3
USE_MATE=	panel
USE_XORG=	x11 xcomposite xdamage

GLIB_SCHEMAS=	org.mocka_desktop.Dock.gschema.xml

PLIST_FILES=	lib/mate-panel/libmocka-dock-applet.so \
		share/mate-panel/applets/org.mocka_desktop.DockApplet.mate-panel-applet

.include <bsd.port.mk>

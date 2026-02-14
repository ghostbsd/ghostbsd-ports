PORTNAME=	ghostbsd-mate-settings
PORTVERSION=	26.01.1
CATEGORIES=	x11

MAINTAINER=	ericturgeon.bsd@gmail.com
COMMENT=	GhostBSD mate settings in installed mode
WWW=		http://www.ghostbsd.org/

LICENSE=	BSD

USES=		desktop-file-utils gnome
USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD
USE_GNOME=	glib20

GLIB_SCHEMAS=	92_org.gnome.desktop.screensaver.wallpaper.gschema.override \
		92_org.mate.NotificationDaemon.gschema.override \
		92_org.mate.caja.gschema.override \
		92_org.mate.desktop.background.gschema.override \
		92_org.mate.desktop.interface.gschema.override \
		92_org.mate.font-rendering.gschema.override \
		92_org.mate.marco.gschema.override \
		92_org.mate.panel.menubar.gschema.override \
		92_org.mate.peripherals-keyboard-xkb.kbd.gschema.override \
		92_org.mate.peripherals-mouse.gschema.override \
		92_org.mate.peripherals-touchpad.gschema.override \
		92_org.mate.session.gschema.override \
		92_org.mate.terminal.gschema.override

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/bin
	${CP}    ${WRKSRC}/bin/* ${STAGEDIR}/${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc
	${CP} -R   ${WRKSRC}/etc/* ${STAGEDIR}/${PREFIX}/etc
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
	${CP} -R   ${WRKSRC}/schemas/* ${STAGEDIR}/${PREFIX}/share/glib-2.0/schemas
.include <bsd.port.mk>

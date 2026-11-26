PORTNAME=	ginrose
DISTVERSIONPREFIX=	v
DISTVERSION=	26.0.5.0
CATEGORIES=	games

MAINTAINER=	rafaelpasquarella@gmail.com
COMMENT=	Roblox and Roblox Studio launchers built around Rosemary
WWW=		https://github.com/nunreasonable/ginrose

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Roblox ships x86-64 macOS clients only

RUN_DEPENDS=	rosemary:emulators/rosemary-ginrose \
		dejavu>0:x11-fonts/dejavu \
		gtk-update-icon-cache:graphics/gtk-update-icon-cache \
		xdg-mime:devel/xdg-utils

USES=		cargo desktop-file-utils gnome
USE_GITHUB=	yes
GH_ACCOUNT=	nunreasonable
USE_GNOME=	cairo glib20 gtk40 libadwaita

ICON_SIZES=	16 24 32 48 64 128 256 512

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ginrose \
		${STAGEDIR}${PREFIX}/bin/ginrose-studio
	${INSTALL_DATA} ${WRKSRC}/packaging/desktop/*.desktop \
		${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/flatpak/*.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo
.for size in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/assets/icons/${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/me.daeese.apps.ginrose.png
	${INSTALL_DATA} ${WRKSRC}/assets/studio-icons/${size}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/me.daeese.apps.ginrose.studio.png
.endfor

.include <bsd.port.mk>

PORTNAME=	gershwin-desktop
PORTVERSION=	20250722
CATEGORIES=	x11 gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jpm820@proton.me
COMMENT=	GNUstep Gershwin desktop environment meta port
WWW=		https://github.com/gershwin-desktop/gershwin-desktop

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	gershwin-globaldefaults>0:misc/gershwin-globaldefaults \
		gershwin-tools-make>0:devel/gershwin-tools-make \
		gershwin-libs-base>0:lang/gershwin-libs-base \
		gershwin-libs-gui>0:x11-toolkits/gershwin-libs-gui \
		gershwin-libs-back>0:x11-toolkits/gershwin-libs-back \
		gershwin-workspace>0:deskutils/gershwin-workspace \
		gershwin-dbuskit>0:devel/gershwin-dbuskit \
		gershwin-appmenu-registrar>0:x11/gershwin-appmenu-registrar \
		gershwin-appmenu-gtk-module>0:x11/gershwin-gtk-app-menu \
		gershwin-xfce4-appmenu-plugin>0:x11/gershwin-xfce4-appmenu-plugin \
		gershwin-rik-theme>0:x11-themes/gershwin-rik-theme \
		gershwin-systempreferences>0:deskutils/gershwin-systempreferences \
		gershwin-terminal>0:x11/gershwin-terminal \
		gershwin-textedit>0:deskutils/gershwin-textedit \
		ghostbsd-gershwin-settings>0:x11/ghostbsd-gershwin-settings \
		ghostbsd-wallpapers>0:x11-themes/ghostbsd-wallpapers \
		ghostbsd-xfce-themes>0:x11-themes/ghostbsd-xfce-themes \
		ghostbsd-zsh-settings>0:shells/ghostbsd-zsh-settings \
		wmctrl-fork>0:x11/wmctrl-fork \
		xfce4-wm>0:x11-wm/xfce4-wm \
		xfce4-panel>0:x11-wm/xfce4-panel \
		xfce4-pulseaudio-plugin>0:audio/xfce4-pulseaudio-plugin

USES=		metaport

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}
	${ECHO_CMD} "This is a meta port for the Gershwin desktop environment." > \
		${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}/README

.include <bsd.port.mk>

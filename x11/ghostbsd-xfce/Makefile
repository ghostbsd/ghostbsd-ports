PORTNAME=	ghostbsd-xfce4
PORTVERSION=	4.16
CATEGORIES=	x11 xfce

MAINTAINER=	goddard1905@gmail.com
COMMENT=	Meta-port for the Xfce Desktop Environment

RUN_DEPENDS=	xfwm4:x11-wm/xfce4-wm \
		xfce4-session:x11-wm/xfce4-session \
		xfce4-panel:x11-wm/xfce4-panel \
		xfdesktop:x11-wm/xfce4-desktop \
		xfsettingsd:sysutils/xfce4-settings \
                xfce4-battery-plugin:sysutils/xfce4-battery-plugin \
		xfce4-bsdcpufreq-plugin:sysutils/xfce4-bsdcpufreq-plugin \
		xfce4-clipman-plugin:x11/xfce4-clipman-plugin \
		xfce4-cpugraph-plugin:sysutils/xfce4-cpugraph-plugin \
		xfce4-datetime-plugin:x11-clocks/xfce4-datetime-plugin \
		xfce4-dev-tools:devel/xfce4-dev-tools \
		xfce4-dict-plugin:textproc/xfce4-dict-plugin \
		xfce4-diskperf-plugin:sysutils/xfce4-diskperf-plugin \
		xfce4-fsguard-plugin:sysutils/xfce4-fsguard-plugin \
		xfce4-genmon-plugin:sysutils/xfce4-genmon-plugin \
		xfce4-mailwatch-plugin:mail/xfce4-mailwatch-plugin \
		xfce4-mount-plugin:sysutils/xfce4-mount-plugin \
		xfce4-netload-plugin:sysutils/xfce4-netload-plugin \
		xfce4-notifyd:deskutils/xfce4-notifyd \
		xfce4-power-manager:sysutils/xfce4-power-manager \
		xfce4-screenshooter-plugin:x11/xfce4-screenshooter-plugin \
		xfce4-screensaver:x11/xfce4-screensaver \
		xfce4-smartbookmark-plugin:www/xfce4-smartbookmark-plugin \
		xfce4-systemload-plugin:sysutils/xfce4-systemload-plugin \
		xfce4-taskmanager:x11/xfce4-taskmanager \
		xfce4-terminal:x11/xfce4-terminal \
		xfce4-timer-plugin:x11-clocks/xfce4-timer-plugin \
		xfce4-tumbler:deskutils/xfce4-tumbler \
		xfce4-verve-plugin:x11/xfce4-verve-plugin \
		xfce4-volumed-pulse:deskutils/xfce4-volumed-pulse \
		xfce4-wavelan-plugin:sysutils/xfce4-wavelan-plugin \
		xfce4-weather-plugin:misc/xfce4-weather-plugin \
		xfce4-whiskermenu-plugin:x11/xfce4-whiskermenu-plugin \
		xfce4-xkb-plugin:deskutils/xfce4-xkb-plugin \
		ghostbsd-xfce-settings:x11/ghostbsd-xfce-settings \

USES=		metaport

OPTIONS_DEFINE=		APPFINDER GREYBIRD ICONS LIGHTDM MOUSEPAD NOTIFY \
			TERMINAL XPM
OPTIONS_DEFAULT=	APPFINDER GREYBIRD ICONS MOUSEPAD NOTIFY TERMINAL \
			XPM
APPFINDER_RUN_DEPENDS=	xfce4-appfinder:misc/xfce4-appfinder
APPFINDER_DESC=		Launcher and finder
GREYBIRD_DESC=		Install Greybird theme
GREYBIRD_RUN_DEPENDS=	greybird-theme>0:x11-themes/greybird-theme
ICONS_RUN_DEPENDS=	adwaita-icon-theme>0:x11-themes/adwaita-icon-theme
LIGHTDM_RUN_DEPENDS=	lightdm-gtk-greeter:x11/lightdm-gtk-greeter
LIGHTDM_DESC=		LightDM display manger
MOUSEPAD_RUN_DEPENDS=	mousepad:editors/mousepad
MOUSEPAD_DESC=		Text editor
NOTIFY_RUN_DEPENDS=	xfce4-notifyd-config:deskutils/xfce4-notifyd
TERMINAL_RUN_DEPENDS=	xfce4-terminal:x11/xfce4-terminal
TERMINAL_DESC=		Terminal emulator
XPM_RUN_DEPENDS=	xfce4-power-manager:sysutils/xfce4-power-manager
XPM_DESC=		Power manager

do-install:	# empty

.include <bsd.port.mk>

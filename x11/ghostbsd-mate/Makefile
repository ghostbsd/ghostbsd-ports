# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ghostbsd-mate
PORTVERSION=	1.22.1
CATEGORIES=	x11 mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	"meta-port" for the GhostBSD MATE integrated X11 desktop

USES=		metaport

RUN_DEPENDS=	mate-terminal:x11/mate-terminal \
		mate-screensaver:x11/mate-screensaver \
		mate-calc:math/mate-calc \
		mate-screenshot:deskutils/mate-utils \
		mate-system-monitor:sysutils/mate-system-monitor \
		eom:graphics/eom \
		engrampa:archivers/engrampa \
		atril:graphics/atril \
		mate-volume-control:audio/mate-media \
		mate-power-manager:sysutils/mate-power-manager \
		caja-sendto:deskutils/caja-extensions \
		mozo:deskutils/mozo \
		mate-applets>=1.22.0:x11/mate-applets \
		${LOCALBASE}/share/fonts/dejavu/DejaVuSerif.ttf:x11-fonts/dejavu \
		${LOCALBASE}/share/hal/fdi/information/10freedesktop/10-camera-ptp.fdi:sysutils/hal-info \
		mate-user-guide>=1.22.0:misc/mate-user-guide

USE_MATE=	caja:run controlcenter:run icontheme:run \
		marco:run notificationdaemon:run panel:run \
		polkit:run session:run \
		pluma:run

.include <bsd.port.mk>

#.Created.by:.Eric Turgeon.<eturgeon@ixsystems.com>
# $FreeBSD$

PORTNAME=	ghostbsd-drivers
PORTVERSION=	20.12
CATEGORIES=	x11-drivers

MAINTAINER=	eturgeon@ixsystems.com
COMMENT=	GhostBSD default pkg
USES=		metaport

OPTIONS_RADIO=		SERVERS
OPTIONS_RADIO_SERVERS=	XLIBRE XORG
OPTIONS_DEFAULT=	XLIBRE
XLIBRE_DESC=	Use the XLibre X server.
XORG_DESC=	Use the X.Org X server.

XLIBRE_RUN_DEPENDS=	Xorg:x11/xorg-minimal \
			xlibre-xf86-input-joystick>0:x11-drivers/xlibre-xf86-input-joystick \
			xlibre-xf86-input-keyboard>0:x11-drivers/xlibre-xf86-input-keyboard \
			xlibre-xf86-input-mouse>0:x11-drivers/xlibre-xf86-input-mouse \
			xlibre-xf86-input-synaptics>0:x11-drivers/xlibre-xf86-input-synaptics \
			xlibre-xf86-input-vmmouse>0:x11-drivers/xlibre-xf86-input-vmmouse \
			xlibre-xf86-video-scfb>0:x11-drivers/xf86-video-scfb@xlibre \
			xlibre-xf86-video-vesa>0:x11-drivers/xlibre-xf86-video-vesa

XORG_RUN_DEPENDS=	Xorg:x11/xorg-minimal \
			xf86-input-joystick>0:x11-drivers/xf86-input-joystick \
			xf86-input-keyboard>0:x11-drivers/xf86-input-keyboard \
			xf86-input-mouse>0:x11-drivers/xf86-input-mouse \
			xf86-input-synaptics>0:x11-drivers/xf86-input-synaptics \
			xf86-input-vmmouse>0:x11-drivers/xf86-input-vmmouse \
			xf86-video-scfb>0:x11-drivers/xf86-video-scfb \
			xf86-video-vesa>0:x11-drivers/xf86-video-vesa

RUN_DEPENDS=		bwi-firmware-kmod>0:net/bwi-firmware-kmod \
			bwn-firmware-kmod>0:net/bwn-firmware-kmod

.include <bsd.port.mk>

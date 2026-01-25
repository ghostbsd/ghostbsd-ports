PORTNAME=	xlibre-xf86-video-vbox
PORTVERSION=	25.0.0
CATEGORIES=	x11-drivers

MAINTAINER=	ericturgeon@GhostBSD.org
COMMENT=	XLibre VirtualBox video driver
WWW=		https://github.com/X11Libre/xf86-video-vbox/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	VirtualBox graphics is only supported on x86-compatible architectures

USES=		pathfix xlibre-cat:driver
USE_XORG=	pciaccess

CONFLICTS_INSTALL=	virtualbox-ose-additions-72 \
			virtualbox-ose-additions-71 \
			virtualbox-ose-additions-70 \
			virtualbox-ose-additions-legacy \
			virtualbox-ose-additions

.include <bsd.port.mk>

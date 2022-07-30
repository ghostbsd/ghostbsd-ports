# Created by: Eric Turgeon <eturgeon@ixsystems.com>
# $FreeBSD$

PORTNAME=	ghostbsd-utils
PORTVERSION=	22.07.30
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	eturgeon@ixsystems.com
COMMENT=	GhostBSD util tools

USES=		metaport

RUN_DEPENDS=	update-station:ports-mgmt/update-station \
		sudo:security/sudo \
		setxkbmap:x11/setxkbmap \
		xmodmap:x11/xmodmap \
		xdg-user-dirs-update:devel/xdg-user-dirs \
		networkmgr:net-mgmt/networkmgr \
		software-station:ports-mgmt/software-station \
		fish:shells/fish \
		webcamd:multimedia/webcamd \
		${LOCALBASE}/sbin/automount:sysutils/automount

.include <bsd.port.mk>

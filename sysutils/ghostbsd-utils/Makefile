# Created by: Eric Turgeon <eturgeon@ixsystems.com>
# $FreeBSD$

PORTNAME=	ghostbsd-utils
PORTVERSION=	21.05.11
PORTREVISION=	0
CATEGORIES=	sysutils

MAINTAINER=	eturgeon@ixsystems.com
COMMENT=	GhostBSD util tools

USES=		metaport

RUN_DEPENDS=	update-station:ports-mgmt/update-station \
		sudo:security/sudo \
		gksu:sysutils/gksu \
		setxkbmap:x11/setxkbmap \
		xmodmap:x11/xmodmap \
		xdg-user-dirs-update:devel/xdg-user-dirs \
		networkmgr:net-mgmt/networkmgr \
		software-station:ports-mgmt/software-station \
		fish:shells/fish \
		bash:shells/bash \
		ksh93:shells/ksh93 \
		zsh:shells/zsh \
		webcamd:multimedia/webcamd \
		${LOCALBASE}/sbin/automount:sysutils/automount

.include <bsd.port.mk>

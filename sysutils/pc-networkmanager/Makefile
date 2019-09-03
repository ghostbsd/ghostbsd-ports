# Created by: Kris Moore <kris@ixsystems.com>
# $FreeBSD$

PORTNAME=	pc-networkmanager
PORTVERSION=	201806271233
CATEGORIES=	sysutils

MAINTAINER=	kris@ixsystems.com
COMMENT=	TrueOS Qt based network manager

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libtrueos-ui.so:sysutils/trueos-libqt5

MAKE_ARGS=      PREFIX=${STAGEDIR}${PREFIX}

CONFLICTS=      pcbsd-utils*

USES=		qmake qt:5 shebangfix tar:xz
SHEBANG_FILES=	src/NetworkManager/resources/umts_stick
USE_LDCONFIG=	yes
USE_QT=		core gui network svg linguist \
		buildtools x11extras widgets
USE_GL+=	gl

QMAKE_ARGS=     CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pc-networkmanager
GH_TAGNAME=	a94041aee30de01f99f697ac2062cce807dd1e42

.include <bsd.port.mk>

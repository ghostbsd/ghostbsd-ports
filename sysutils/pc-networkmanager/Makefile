PORTNAME=	pc-networkmanager
PORTVERSION=	201806271233
CATEGORIES=	sysutils

MAINTAINER=	jt@obs-sec.com
COMMENT=	TrueOS Qt based network manager
WWW=		https://github.com/trueos/pc-networkmanager

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libtrueos-ui.so:sysutils/trueos-libqt5

MAKE_ARGS=      PREFIX=${STAGEDIR}${PREFIX}

CONFLICTS=      pcbsd-utils*

USES=		gl qmake qt:5 shebangfix tar:xz
SHEBANG_FILES=	src/NetworkManager/resources/umts_stick
USE_LDCONFIG=	yes
USE_QT=		core gui network svg linguist \
		buildtools x11extras widgets
USE_GL+=	gl

QMAKE_ARGS=     CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_TAGNAME=	ae50abf3ba522a7685f275157455f6d424453bb2

.include <bsd.port.mk>

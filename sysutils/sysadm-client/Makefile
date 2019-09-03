# $FreeBSD$

PORTNAME=	sysadm-client
PORTVERSION=	201802091522
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	jt@ixsystems.com
COMMENT=	SysAdm Qt5 Client

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src-qt5
USES=		compiler:c++11-lang gmake pkgconfig qmake ssl qt:5 tar:xz
USE_QT=		core buildtools_build gui network qmake websockets widgets svg concurrent
USE_GL+=	gl
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	sysadm-ui-qt
GH_TAGNAME=	e472d2ead74b3ea1774ae53ba486becc2fd0ba8c

DEPRECATED=	No longer maintained upstream
EXPIRATION_DATE=	2019-11-01

.include <bsd.port.mk>

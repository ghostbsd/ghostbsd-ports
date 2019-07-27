# $FreeBSD$

PORTNAME=	sysadm
PORTVERSION=	201806120928
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	jt@ixsystems.com
COMMENT=	SysAdm API server

LICENSE=	BSD3CLAUSE

WRKSRC_SUBDIR=	src
USES=		compiler:c++11-lang pkgconfig qmake qt:5 ssl tar:xz
USE_QT=		concurrent core network buildtools qmake gui websockets sql
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	sysadm
GH_TAGNAME=	aab6f484ef01c893ae1701f64732254855eb3cdd

.include <bsd.port.mk>

# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	pc-mixer
PORTVERSION=	20180328
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	QT5 based audio mixer for FreeBSD

LICENSE=	BSD2CLAUSE

MAKE_ARGS=      PREFIX=${STAGEDIR}${PREFIX}

MAKE_JOBS_UNSAFE=yes
ONLY_FOR_ARCHS= amd64
USE_LDCONFIG=   yes
USES=		compiler:c++11-lang gl qmake qt:5 shebangfix tar:xz
USE_LDCONFIG=	yes
USE_QT=		core gui network svg linguist \
		buildtools x11extras widgets multimedia
USE_GL+=	gl

WRKSRC_SUBDIR=  src-qt5

QMAKE_ARGS=     CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pc-mixer
GH_TAGNAME=	dbbddfbe318db719dcfea337676e758efaa56ea2

.include <bsd.port.mk>

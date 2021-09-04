PORTNAME=	trueos-libqt5
PORTVERSION=	20180529
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	jt@ixsystems.com
COMMENT=	TrueOS QT5 Library

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS= amd64

MAKE_JOBS_UNSAFE=yes
MAKE_ARGS=      PREFIX=${STAGEDIR}${PREFIX}
USES=		gl qmake qt:5 shebangfix tar:xz

USE_LDCONFIG=	yes
USE_GL+=	gl
USE_QT=        core gui network svg linguist \
		buildtools x11extras widgets
USE_LDCONFIG=   yes

QMAKE_ARGS=     CONFIG+="configure"

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_TAGNAME=	9e92b465d823185c9b96f2017e06f2a06b6143fa

.include <bsd.port.mk>

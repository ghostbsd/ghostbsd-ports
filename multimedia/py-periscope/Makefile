PORTNAME=	periscope
DISTVERSION=	0.2.4
PORTREVISION=	6
CATEGORIES=	multimedia python
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/periscope/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	python-${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX} \
		periscope.desktop
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	python-${PORTNAME}_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Subtitles searching module
WWW=		https://code.google.com/archive/p/periscope/

LICENSE=	LGPL3

DEPRECATED=	Unmaintained upstream, last release 2011
EXPIRATION_DATE=2026-09-30

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		desktop-file-utils python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

NO_WRKSUBDIR=	yes

PLIST_FILES=	share/applications/periscope.desktop

OPTIONS_DEFINE=	UNRAR
OPTIONS_DEFAULT=	UNRAR

UNRAR_RUN_DEPENDS=	unrar:archivers/unrar

post-patch:
	${REINPLACE_CMD} -e 's|from BeautifulSoup import|from bs4 import|' \
		${WRKSRC}/periscope/plugins/Podnapisi.py \
		${WRKSRC}/periscope/plugins/Subtitulos.py \
		${WRKSRC}/periscope/plugins/SubsWiki.py \
		${WRKSRC}/periscope/plugins/Addic7ed.py \
		${WRKSRC}/periscope/plugins/SubScene.py
	${REINPLACE_CMD} -e 's|import os, re, BeautifulSoup|import os, re, bs4|' \
		${WRKSRC}/periscope/plugins/TvSubtitles.py

pre-build:
	@${LOCALBASE}/bin/2to3-${PYTHON_VER} --no-diffs --nobackups --verbose --write \
		${WRKSRC}/

post-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/periscope.desktop \
		${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>

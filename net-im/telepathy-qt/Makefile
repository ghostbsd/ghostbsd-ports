PORTNAME=	telepathy-qt
DISTVERSION=	0.9.8
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	https://telepathy.freedesktop.org/releases/${PORTNAME}/
PKGNAMESUFFIX=	5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level Qt binding for Telepathy
WWW=		https://telepathy.freedesktop.org/doc/telepathy-qt

LICENSE=	LGPL21

DEPRECATED=	Leaf library depending on Qt5
EXPIRATION_DATE=2025-03-31

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libtelepathy-farstream.so:net-im/telepathy-farstream \
		libtelepathy-glib.so:net-im/telepathy-glib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus@${PY_FLAVOR}

USES=		cmake compiler:c++11-lang gettext gnome gstreamer localbase:ldflags pathfix \
		pkgconfig python:build qt:5
USE_GNOME=	glib20 libxslt:build
USE_QT=		core dbus gui network xml \
		buildtools:build qmake:build testlib:build widgets:build

CMAKE_ON=	ENABLE_FARSTREAM CMAKE_DISABLE_FIND_PACKAGE_Doxygen
CMAKE_OFF=	ENABLE_EXAMPLES ENABLE_FARSIGHT ENABLE_TESTS
CMAKE_ARGS=	-DDESIRED_QT_VERSION:STRING=${PKGNAMESUFFIX} \
		-DQT_QMAKE_EXECUTABLE:FILEPATH=${QMAKE}

OPTIONS_DEFINE=	DOCS

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README html
# Manually set DOCSDIR, to handle the version suffix
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R doc/html .
. for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>

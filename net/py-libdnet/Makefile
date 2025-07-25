PORTREVISION=	5
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python module for libdnet

BUILD_DEPENDS=	${PY_SETUPTOOLS}
LIB_DEPENDS=	libdnet.so:net/libdnet

USES=		autoreconf libtool localbase:ldflags python

MASTERDIR=	${.CURDIR}/../libdnet
INSTALL_WRKSRC=	${WRKSRC}/python
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${NONEXISTENT}
PLIST_FILES=	${PYTHON_SITELIBDIR}/dnet${PYTHON_TAG}.so \
		${PYTHON_SITELIBDIR}/dnet-${PORTVERSION}-py${PYTHON_VER}.egg-info/PKG-INFO \
		${PYTHON_SITELIBDIR}/dnet-${PORTVERSION}-py${PYTHON_VER}.egg-info/SOURCES.txt \
		${PYTHON_SITELIBDIR}/dnet-${PORTVERSION}-py${PYTHON_VER}.egg-info/dependency_links.txt \
		${PYTHON_SITELIBDIR}/dnet-${PORTVERSION}-py${PYTHON_VER}.egg-info/top_level.txt

LIBDNET_SLAVE=	yes

USE_PYTHON=	cython flavors
CONFIGURE_ARGS=	--with-python=${PYTHON_CMD}

.if defined(MAINTAINER_MODE)
regression-test: install
	${PYTHON_CMD} ${INSTALL_WRKSRC}/test.py
.endif

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	${REINPLACE_CMD} 's|%%CYTHON%%|cython-${PYTHON_VER}|g' \
		${WRKSRC}/python/Makefile.am

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/dnet*.so

.include "${MASTERDIR}/Makefile"

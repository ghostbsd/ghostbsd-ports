PORTNAME=	faster-coco-eval
PORTVERSION=	1.7.2
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	faster_coco_eval-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Faster interpretation of the original COCOEval for computer vision
WWW=		https://github.com/MiXaiLL76/faster_coco_eval

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.12.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython concurrent autoplist

post-extract:
	@${REINPLACE_CMD} -e 's/^license = "\([^"]*\)"/license = {text = "\1"}/' \
		-e '/^license-files/d' \
		-e 's/pybind11>=2.12.0, <3/pybind11>=2.12.0/' \
		${WRKSRC}/pyproject.toml
	@${REINPLACE_CMD} -e '/data_files=/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>

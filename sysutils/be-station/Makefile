PORTNAME=	be-station
PORTVERSION=	0.8
CATEGORIES=	sysutils

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GUI to create boot environment
WWW=		http://github.com/ghostbsd/be-station

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.15:devel/py-python-distutils-extra@${PY_FLAVOR}
RUN_DEPENDS=	sudo:security/sudo \
		${PYTHON_PKGNAMEPREFIX}bectl>=0.7:sysutils/py-bectl@${PY_FLAVOR}

USES=		python:3.12+ gnome gettext-tools
USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD
USE_PYTHON=	distutils
USE_GNOME=	pygobject3 intltool

.include <bsd.port.mk>

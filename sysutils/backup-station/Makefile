PORTNAME=	backup-station
PORTVERSION=	0.6
CATEGORIES=	sysutils

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	Tool install and deinstall software and pksystem packages
WWW=		http://github.com/ghostbsd/software-station

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.15:devel/py-python-distutils-extra@${PY_FLAVOR}
RUN_DEPENDS=	sudo:security/sudo \
		pkg:ports-mgmt/pkg \
		${PYTHON_PKGNAMEPREFIX}bectl>=0.1:sysutils/py-bectl@${PY_FLAVOR}

USES=		python:3.9+ gnome gettext-tools
USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD
USE_PYTHON=	distutils
USE_GNOME=	pygobject3 intltool

.include <bsd.port.mk>

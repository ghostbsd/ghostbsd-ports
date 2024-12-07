PORTNAME=	software-station
PORTVERSION=	2.0
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/GhostBSD/${PORTNAME}/archive/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	Tool install and deinstall software and pksystem packages
WWW=	http://github.com/ghostbsd/software-station

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.15:devel/py-python-distutils-extra@${PY_FLAVOR}
RUN_DEPENDS=	sudo:security/sudo \
		pkg:ports-mgmt/pkg \
		${LOCALBASE}/etc/pkg/repos/GhostBSD.conf.ca:misc/ghostbsd-pkg-conf \
		${PYTHON_PKGNAMEPREFIX}requests>=0.1:www/py-requests@${PY_FLAVOR}

USES =		python:3.9+ gnome gettext-tools
USE_PYTHON=	distutils noflavors
USE_GNOME=	pygobject3 intltool

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

.include <bsd.port.mk>

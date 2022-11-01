PORTNAME=	software-station
PORTVERSION=	1.6
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/GhostBSD/${PORTNAME}/archive/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	Tool install and deinstall software and pksystem packages.
LICENSE =	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.15:devel/py-python-distutils-extra@${PY_FLAVOR}
RUN_DEPENDS=	sudo:security/sudo \
		pkg:ports-mgmt/pkg \
		${LOCALBASE}/etc/pkg/repos/GhostBSD.conf.ca:misc/ghostbsd-pkg-conf \
		${PYTHON_PKGNAMEPREFIX}requests>=0.1:www/py-requests@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

USES =		python:3.8+ gnome gettext-tools
USE_PYTHON=	distutils noflavors
USE_GNOME=	pygobject3 intltool

.include <bsd.port.mk>

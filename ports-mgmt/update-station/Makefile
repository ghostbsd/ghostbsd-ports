PORTNAME=	update-station
PORTVERSION=	5.9
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/GhostBSD/${PORTNAME}/archive/

MAINTAINER=	ericturgeon@ghostbsd.com
COMMENT=	Tool to update FreeBSD/GhostBSD software and system.
LICENSE =	BSD

RUN_DEPENDS=	sudo:security/sudo \
		pkg:ports-mgmt/pkg \
		distro:sysutils/py-distro@${PY_FLAVOR} \
		${LOCALBASE}/etc/pkg/repos/GhostBSD.conf.ca:misc/ghostbsd-pkg-conf \
		${PYTHON_PKGNAMEPREFIX}bectl>=0.1:sysutils/py-bectl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0.1:www/py-requests@${PY_FLAVOR} \
		ghostbsd-update-scripts>=0:misc/ghostbsd-update-scripts

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

USES =		python:3.9+ gnome gettext-tools
USE_PYTHON=	distutils
USE_GNOME=	pygobject3 

.include <bsd.port.mk>

# Created by: Eric Turgeon <ericturgeon@ghostbsd.org>
# $FreeBSD$

PORTNAME=	software-station
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/GhostBSD/${PORTNAME}/archive/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	Tool install and deinstall software and pksystem packages.
LICENSE =	BSD

RUN_DEPENDS=	sudo:security/sudo \
		pkg:ports-mgmt/pkg \
		${LOCALBASE}/etc/pkg/repos/GhostBSD.conf.ca:misc/ghostbsd-pkg-conf \
	        ${PYTHON_PKGNAMEPREFIX}requests>=0.1:www/py-requests@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

USES =		python:3.8+
USE_PYTHON=	distutils
USE_GNOME=	pygobject3

.include <bsd.port.mk>

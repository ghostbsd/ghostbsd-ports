# New ports collection makefile for: update-station
# Date created:        Sunday, April 17 2016
# Whom:                ericturgeon@ghostbsd.com
#
# $FreeBSD$
#

PORTNAME=	update-station
PORTVERSION=	3.9
PORTREVISION=	0
CATEGORIES=	ports-mgmt
MASTER_SITES=	https://github.com/GhostBSD/${PORTNAME}/archive/

MAINTAINER=	ericturgeon@ghostbsd.com
COMMENT=	Tool to update FreeBSD/GhostBSD software and system.
LICENSE =	BSD

RUN_DEPENDS=	sudo:security/sudo \
		${LOCALBASE}/etc/pkg/repos/GhostBSD.conf.ca:misc/ghostbsd-pkg-conf \
		${PYTHON_PKGNAMEPREFIX}bectl>=0.1:sysutils/py-bectl@${PY_FLAVOR} \
		ghostbsd-update-scripts>=0:misc/ghostbsd-update-scripts

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

USES =		python:3.6+
USE_PYTHON=	distutils
USE_GNOME=	pygobject3

.include <bsd.port.mk>

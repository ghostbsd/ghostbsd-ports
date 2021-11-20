# Created by:	Eric Turgeon ericturgeon@ghostbsd.org

PORTNAME=	station-tweak
PORTVERSION=	0.7
CATEGORIES=	x11
MASTER_SITES=	https://github.com/GhostBSD/${PORTNAME}/archive/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	Mate configuration system

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.15:devel/py-python-distutils-extra@${PY_FLAVOR}
RUN_DEPENDS=	wmctrl:x11/wmctrl

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

USES = python:3.6+ gnome gettext-tools
USE_PYTHON=	distutils noflavors
USE_GNOME=	pygobject3 intltool

.include <bsd.port.mk>

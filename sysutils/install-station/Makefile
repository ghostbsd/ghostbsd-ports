PORTNAME=	install-station
PORTVERSION=	0.4
CATEGORIES=	sysutils

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	New installer for GhostBSD
WWW=		https://github.com/GhostBSD/install-station

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR}
RUN_DEPENDS=	pc-sysinstall>0:sysutils/pc-sysinstall

USES=		python gnome gettext
USE_PYTHON=	distutils noflavors
USE_GNOME=	pygobject3 intltool

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

.include <bsd.port.mk>

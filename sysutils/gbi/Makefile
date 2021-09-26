# Created by:	Eric Turgeon ericturgeon@ghostbsd.org
# Date created:	November 11 2013


PORTNAME=	gbi
PORTVERSION=	9.5
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/GhostBSD/${PORTNAME}/archive/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	GBI is the GhostBSD front end user interface for pc-sysinstall.

LICENSE=	BSD

RUN_DEPENDS=	pc-sysinstall>0:sysutils/pc-sysinstall

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

USES =		python
USE_PYTHON=	distutils noflavors
USE_GNOME=	pygobject3

.include <bsd.port.mk>

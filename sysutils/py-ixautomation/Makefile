# Created by: Joe Maloney <jmaloney@ixsystems.com>
# $FreeBSD$

PORTNAME=	ixautomation
PORTVERSION=	19.04.25
PORTREVISION=	0
CATEGORIES=	sysutils
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jmaloney@ixsystems.com
COMMENT=	Automation framework for iXsystems projects

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}selenium>=0:www/py-selenium@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0:www/py-websocket-client@${PY_FLAVOR} \
		vm-bhyve>=0:sysutils/vm-bhyve \
		${LOCALBASE}/bin/expect:lang/expect \
		${LOCALBASE}/bin/sshpass:security/sshpass \
		bhyve-firmware>=0:sysutils/bhyve-firmware \
		dnsmasq>=0:dns/dnsmasq

WRKSRC_SUBDIR=  src
USES=		python:3.6
USE_PYTHON=	distutils noflavors
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	ixsystems
GH_PROJECT=	ixautomation
GH_TAGNAME=	fb316fc27f8e85df0e9340359c76c84e330117d6

.include <bsd.port.mk>

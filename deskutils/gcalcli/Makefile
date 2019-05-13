# Created by: ijliao
# $FreeBSD$

PORTNAME=	gcalcli
PORTVERSION=	4.0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@thelanman.net
COMMENT=	Google Calendar Command Line Interface

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}google-api-python-client>=0:www/py-google-api-python-client@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}python-gflags>=0:devel/py-python-gflags@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}oauth2client>0:security/py-oauth2client@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_GITHUB=	yes
SHEBANG_FILES=	gcalcli

USE_GITHUB=	yes
GH_ACCOUNT=	insanum

NO_ARCH=	yes

OPTIONS_DEFINE=		ICS_VCAL
OPTIONS_DEFAULT=	ICS_VCAL

ICS_VCAL_DESC=		Enable importing of ics/vcal files
ICS_VCAL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}vobject>=0.4.8:deskutils/py-vobject@${PY_FLAVOR}

.include <bsd.port.mk>

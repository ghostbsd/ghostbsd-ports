PORTNAME=	hpilo
PORTVERSION=	4.4.3
PORTREVISION=	1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Python cli to interact with HP iLO management interface
WWW=		https://github.com/seveas/python-hpilo

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	python

USE_GITHUB=	yes
GH_ACCOUNT=	seveas
GH_PROJECT=	python-hpilo

USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	RC4_SHA

RC4_SHA_DESC=	Enable RC4-SHA ciphers, for old iLO, but removed from openssl (custom openssl required)

# replace "RC4-SHA:" +  with nothing
post-patch-RC4_SHA-off:
	${REINPLACE_CMD} -e 's/"RC4-SHA:" + //g' ${WRKSRC}/hpilo.py

.include <bsd.port.mk>

PORTNAME=	dogtag-pki
DISTVERSIONPREFIX=	v
DISTVERSION=	11.7.0
PORTREVISION=	3
CATEGORIES=	security python

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Python client and server modules for Dogtag PKI
WWW=		https://github.com/dogtagpki/pki

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ldap>0:net/py-python-ldap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USERS=		pkiuser
GROUPS=		pkiuser

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	dogtagpki
GH_PROJECT=	pki
USE_PYTHON=	autoplist pep517

SHEBANG_FILES=	base/common/upgrade/*/*.py base/server/upgrade/*/*.py

NO_ARCH=	yes

PLIST_FILES=	share/pki/VERSION

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pki
	@${PRINTF} "Specification-Version: ${DISTVERSION}\nImplementation-Version: ${DISTVERSION}\n" > ${STAGEDIR}${PREFIX}/share/pki/VERSION

.include <bsd.port.mk>

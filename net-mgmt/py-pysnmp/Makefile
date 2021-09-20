# Created by: Martin Jackson <mhjacks@swbell.net>

PORTNAME=	pysnmp
PORTVERSION=	4.4.9
PORTREVISION=	2
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP \
		SF/pysnmp/pysnmp/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mhjacks@swbell.net
COMMENT=	SNMP framework for Python

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0.2.3:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>=0:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysmi>=0:net-mgmt/py-pysmi@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE= DOCS EXAMPLES

NO_ARCH=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

PORTDOCS=	*
PORTEXAMPLES=	*

BASEDOCS=	CHANGES.txt README.md TODO.txt THANKS.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BASEDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/source/docs && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>

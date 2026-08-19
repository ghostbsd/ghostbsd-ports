PORTNAME=	immanent-checker
DISTVERSION=	0.23
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.p.variablis.de/api/v4/projects/open-source%2Fimmanent-checker/packages/generic/${PORTNAME}/${DISTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTFILES=	immanent-checker-${DISTVERSION} \
		immanent-parser-${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Project structure and source expectation checker
WWW=		https://gitlab.p.variablis.de/open-source/immanent-checker

USES=		php:flavors
USE_PHP=	phar tokenizer

CONFLICTS_INSTALL=	php*-immanent-checker

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/immanent-checker \
		bin/immanent-parser

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/immanent-checker-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/immanent-checker
	${INSTALL_SCRIPT} ${DISTDIR}/immanent-parser-${DISTVERSION} \
		${STAGEDIR}${PREFIX}/bin/immanent-parser

.include <bsd.port.mk>

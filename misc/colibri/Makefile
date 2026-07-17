PORTNAME=	colibri
DISTVERSION=	g20260715
CATEGORIES=	misc # machine-learning
PKGNAMESUFFIX=	-ai

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Run GLM-5.2 (744B MoE) on a 25GB-RAM consumer machine
WWW=		https://github.com/JustVugg/colibri

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	JustVugg
GH_TAGNAME=	550ddcb

SHEBANG_FILES=	c/coli
SHEBANG_GLOB=	*.py

CFLAGS+=	-pthread -fopenmp # -fopenmp is for tests
LDFLAGS+=	-pthread -lm
MAKE_ARGS=	CC=${CC} \
		CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

TEST_TARGET=	test

# tests as of 2026-07-14:
# Ran 62 tests in 3.629s
# OK

.include <bsd.port.mk>

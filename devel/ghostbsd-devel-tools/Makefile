PORTNAME=	ghostbsd-devel-tools
PORTVERSION=	20250118
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GhostBSD development tools meta port
WWW=		https://github.com/ghostbsd/ghostbsd-ports

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	git>0:devel/git \
		nano>0:editors/nano \
		vim>0:editors/vim \
		gpg>0:security/gnupg \
		shellcheck>0:devel/hs-ShellCheck \
		portlint>0:ports-mgmt/portlint \
		py311-setuptools>0:devel/py-setuptools \
		poudriere>0:ports-mgmt/poudriere \
		python-distutils-extra>0:devel/py-python-distutils-extra \
		pylint>0:devel/pylint \
		transmission-utils>0:net-p2p/transmission-components@utils

USES=		metaport

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}
	${ECHO_CMD} "This is a meta port for GhostBSD development tools." > \
		${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}/README

.include <bsd.port.mk>
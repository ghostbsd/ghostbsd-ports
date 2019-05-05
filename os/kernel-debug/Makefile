# $FreeBSD$

.include "../Makefile.common"

PORTNAME=	kernel-debug
PORTVERSION=	${OS_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}

MAINTAINER=	kris@ixsystems.com
COMMENT=	Port for the kernel compiled with debugging enabled

BUILD_DEPENDS=	${OS_KERNDIST_DEBUG}:os/buildkernel-debug@${OS_FLAVOR}

USES=	os:flavors
PREFIX=/
EXTRACT_ONLY=
DISTFILES=
WRKSRC=/usr/src
NEED_ROOT=	yes

.include <bsd.port.pre.mk>

do-build:
	@${MKDIR} -p ${STAGEDIR}
	@${ECHO_MSG} "==> Extracting ${OS_KERNDIST_DEBUG}..."
	@${TAR} xpf ${OS_KERNDIST_DEBUG} -C ${STAGEDIR}

do-install:
	@${ECHO_MSG} "==> Generating plist..."
	@${MKDIR} -p ${STAGEDIR}
	@(cd ${STAGEDIR}; ${FIND} ./boot/kernel-debug \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' >> ${TMPPLIST})
	@(cd ${STAGEDIR}; ${FIND} ./boot/kernel-debug \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${XARGS} -I '{}' echo "@dir {}" >> ${TMPPLIST})

.include <bsd.port.post.mk>

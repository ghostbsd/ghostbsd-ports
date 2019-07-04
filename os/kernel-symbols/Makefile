# $FreeBSD$

PORTNAME=	kernel-symbols
PORTVERSION=	${BASEPKG_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	FreeBSD kernel debugging symbols

BUILD_DEPENDS=	${OS_KERNDIST}:os/buildkernel@${OS_FLAVOR}

USES=	os:flavors

PREFIX=/
NEED_ROOT=	yes
PKGVITAL=	yes

.include <bsd.port.pre.mk>

do-build:
	@${MKDIR} ${STAGEDIR}
	${ECHO_MSG} "==> Extracting ${OS_KERNDIST}..."
	${TAR} xpf ${OS_KERNDIST} -C ${STAGEDIR}

do-install:
	${ECHO_MSG} "==> Generating plist..."
	@${MKDIR} ${STAGEDIR}
	(cd ${STAGEDIR}; ${FIND} ./usr/lib/debug/boot/kernel \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} ./usr/lib/debug/boot/kernel \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${XARGS} -I '{}' echo "@dir {}" >> ${TMPPLIST})

.include "../Makefile.common"
.include <bsd.port.post.mk>

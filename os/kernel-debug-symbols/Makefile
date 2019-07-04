# $FreeBSD$

PORTNAME=	kernel-debug-symbols
PORTVERSION=	${BASEPKG_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	FreeBSD kernel debugging symbols

BUILD_DEPENDS=	${OS_KERNDIST_DEBUG}:os/buildkernel-debug@${OS_FLAVOR}

USES=	os:flavors

PREFIX=/
NEED_ROOT=	yes

.include <bsd.port.pre.mk>

do-build:
	@${MKDIR} ${STAGEDIR}
	${ECHO_MSG} "==> Extracting ${OS_KERNDIST_DEBUG}..."
	${TAR} xpf ${OS_KERNDIST_DEBUG} -C ${STAGEDIR}
	${MV} ${STAGEDIR}/usr/lib/debug/boot/kernel ${STAGEDIR}/usr/lib/debug/boot/kernel-debug

do-install:
	${ECHO_MSG} "==> Generating plist..."
	(cd ${STAGEDIR}; ${FIND} ./usr/lib/debug/boot/kernel-debug \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} ./usr/lib/debug/boot/kernel-debug \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${XARGS} -I '{}' echo "@dir {}" >> ${TMPPLIST})

.include "../Makefile.common"
.include <bsd.port.post.mk>

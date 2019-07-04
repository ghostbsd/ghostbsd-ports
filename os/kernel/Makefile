# $FreeBSD$

PORTNAME=	kernel
PORTVERSION=	${BASEPKG_PORTVERSION}
PORTEPOCH=	1
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	FreeBSD kernel without debug enabled

BUILD_DEPENDS=	${OS_KERNDIST}:os/buildkernel@${OS_FLAVOR}

USES=	os:flavors

PREFIX=/
NEED_ROOT=	yes
PKGVITAL=	yes

OPTIONS_DEFINE=	 DEBUG
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
RUN_DEPENDS+=	kernel-symbols=${BASEPKG_PORTVERSION}:os/kernel-symbols@${OS_FLAVOR}
.endif

do-build:
	@${MKDIR} ${STAGEDIR}
	${ECHO_MSG} "==> Extracting ${OS_KERNDIST}..."
	${TAR} xpf ${OS_KERNDIST} -C ${STAGEDIR}

do-install:
	${ECHO_MSG} "==> Generating plist..."
	@${MKDIR} ${STAGEDIR}
	(cd ${STAGEDIR}; ${FIND} ./boot/kernel \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} ./boot/kernel \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${XARGS} -I '{}' echo "@dir {}" >> ${TMPPLIST})

.include "../Makefile.common"
.include <bsd.port.post.mk>

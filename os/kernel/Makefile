# $FreeBSD$

.include "../Makefile.common"

PORTNAME=	kernel
PORTVERSION=	${OS_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}

MAINTAINER=	kris@ixsystems.com
COMMENT=	Port for the OS kernel

BUILD_DEPENDS=	${OS_KERNDIST}:os/buildkernel@${OS_FLAVOR}

USES=	os:flavors
PREFIX=/
EXTRACT_ONLY=
DISTFILES=
WRKSRC=/usr/src
NEED_ROOT=	yes
PKGVITAL=	yes

NO_OPTIONS_SORT=	yes

OPTIONS_DEFINE=	 DEBUG
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
RUN_DEPENDS+=	kernel-symbols=${OS_PORTVERSION}:os/kernel-symbols@${OS_FLAVOR}
.endif

do-build:
	@${MKDIR} -p ${STAGEDIR}
	@${ECHO_MSG} "==> Extracting ${OS_KERNDIST}..."
	@${TAR} xpf ${OS_KERNDIST} -C ${STAGEDIR}

do-install:
	@${ECHO_MSG} "==> Generating plist..."
	@${MKDIR} -p ${STAGEDIR}
	@(cd ${STAGEDIR}; ${FIND} ./boot/kernel \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' >> ${TMPPLIST})
	@(cd ${STAGEDIR}; ${FIND} ./boot/kernel \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${XARGS} -I '{}' echo "@dir {}" >> ${TMPPLIST})

.include <bsd.port.post.mk>

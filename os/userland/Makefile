# $FreeBSD$

.include "../Makefile.common"

PORTNAME=	userland
PORTVERSION=	${OS_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}

MAINTAINER=	kris@ixsystems.com
COMMENT=	Metaport for the OS userland

USES=	metaport os:flavors

NO_OPTIONS_SORT=	yes

OPTIONS_DEFINE=	DEBUG DOCS LIB32 TESTS ZOL
OPTIONS_DEFAULT= DOCS
OPTIONS_SUB=	yes
DOCS_DESC=	Include manpages and other documentation
LIB32_DESC=	Support for execution of i386 applications
TESTS_DESC=	Optional test framework scripts and tools
ZOL_DESC=	ZFS on Linux userland and kernel support

RUN_DEPENDS+=	/bin/sh:os/userland-base@${OS_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
RUN_DEPENDS+=	/usr/lib/debug/bin/sh.debug:os/userland-debug@${OS_FLAVOR}
.endif

.if ${PORT_OPTIONS:MDOCS}
RUN_DEPENDS+=	/usr/share/man/man1/sh.1.gz:os/userland-docs@${OS_FLAVOR}
.endif

.if ${PORT_OPTIONS:MLIB32}
RUN_DEPENDS+=	/usr/lib32/libc.a:os/userland-lib32@${OS_FLAVOR}
.endif

.if ${PORT_OPTIONS:MTESTS}
RUN_DEPENDS+=	/usr/tests/README:os/userland-tests@${OS_FLAVOR}
.endif

.if ${PORT_OPTIONS:MZOL} || ${FLAVOR} == "zol"
RUN_DEPENDS+=	${LOCALBASE}/sbin/zpool:sysutils/zol
.endif

.include <bsd.port.post.mk>

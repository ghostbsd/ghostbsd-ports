# $FreeBSD$

PORTNAME=	userland
PORTVERSION=	${BASEPKG_PORTVERSION}
PORTEPOCH=	1
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Metaport for the FreeBSD userland

USES=	metaport os:flavors

OPTIONS_DEFINE=	DEBUG DOCS LIB32 TESTS OPENZFS
OPTIONS_DEFAULT= DOCS
OPTIONS_SUB=	yes
DOCS_DESC=	Include manpages and other documentation
LIB32_DESC=	Support for execution of i386 applications
TESTS_DESC=	Optional test framework scripts and tools
OPENZFS_DESC=	OpenZFS userland and kernel support

RUN_DEPENDS+=	/COPYRIGHT:os/userland-base@${OS_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDEBUG}
RUN_DEPENDS+=	/usr/lib/debug/bin/sh.debug:os/userland-debug@${OS_FLAVOR}
.endif

.if ${PORT_OPTIONS:MDOCS}
RUN_DEPENDS+=	/usr/share/man/man1/sh.1.gz:os/userland-docs@${OS_FLAVOR}
.endif

.if ${PORT_OPTIONS:MLIB32}
RUN_DEPENDS+=	/usr/lib32/libc.so:os/userland-lib32@${OS_FLAVOR}
.endif

.if ${PORT_OPTIONS:MTESTS}
RUN_DEPENDS+=	/usr/tests/README:os/userland-tests@${OS_FLAVOR}
.endif

.if ${PORT_OPTIONS:MOPENZFS}
WITH_OPENZFS=	YES
OPTIONS_SET+=	OPENZFS
RUN_DEPENDS+=	${LOCALBASE}/sbin/zpool:sysutils/openzfs
.endif

.include "../Makefile.common"
.include <bsd.port.post.mk>

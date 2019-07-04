# $FreeBSD$

PORTNAME=	buildkernel-debug
PORTVERSION=	${BASEPKG_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Distribution tarball of debug kernel for packaging

SRCDIR?=/usr/src
.if !exists(${SRCDIR}/Makefile)
BUILD_DEPENDS=	${SRCDIR}/Makefile:os/src
.endif

USES=	os:flavors

PREFIX=/
WITHOUT_FBSD10_FIX=	yes
WRKSRC=${SRCDIR}
PLIST_FILES+=	${OS_KERNDIST_DEBUG}
LOCAL_SDIR?=	/usr/local_source
NEED_ROOT=	yes
.if exists(${LOCAL_SDIR}/${PORTNAME})
WRKSRC=	${LOCAL_SDIR}/${PORTNAME}
.endif

# Set default debug config
.if defined(${DEBUGKERNCONF})
KERNCONF=	${DEBUGKERNCONF}
.else
KERNCONF=	GENERIC
.endif

.if defined(_MAKE_JOBS_NUMBER)
JOBFLAG=	-j ${_MAKE_JOBS_NUMBER}
.else
JOBFLAG=	-j ${_SMP_CPUS}
.endif

.if defined(__MAKE_CONF)
MCONF=	__MAKE_CONF=${__MAKE_CONF}
.else
MCONF=
.endif

.include "../buildworld/Makefile.options"
.include "../buildworld/Makefile.options.desc"

.include <bsd.port.pre.mk>

.for var in ${OPTIONS_DEFINE}
.if !${PORT_OPTIONS:M${var}}
MFLAGS+=	WITHOUT_${var}=YES
.else
MFLAGS+=	WITH_${var}=YES
.endif
.endfor

check-sanity:

do-build:
	cd ${WRKSRC} && ${SETENV} -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} ${MCONF} ${KERNEL_MAKE_FLAGS} \
		KERNCONF=${KERNCONF} \
		${MFLAGS} \
		buildkernel

do-install:
	@${MKDIR} ${STAGEDIR}/kernel-debug
	@${MKDIR} ${STAGEDIR}/usr/dist
	cd ${WRKSRC} && ${SETENV} -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} ${MCONF} ${KERNEL_MAKE_FLAGS} \
		KERNCONF=${KERNCONF} \
		${MFLAGS} \
		DESTDIR=${STAGEDIR}/kernel-debug \
		installkernel
	${MV} ${STAGEDIR}/kernel-debug/boot/kernel ${STAGEDIR}/kernel-debug/boot/kernel-debug
	${TAR} cvJf ${STAGEDIR}/${OS_KERNDIST_DEBUG} -C ${STAGEDIR}/kernel-debug .
	${CHFLAGS} -R noschg ${STAGEDIR}/kernel-debug
	${RM} -rf ${STAGEDIR}/kernel-debug

.include "../Makefile.common"
.include <bsd.port.post.mk>

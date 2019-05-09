# $FreeBSD$

.include "../Makefile.common"

PORTNAME=	buildkernel-debug
PORTVERSION=	${OS_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}

MAINTAINER=	kris@ixsystems.com
COMMENT=	Buildkernel portition of os packages with debug enabled

SRCDIR?=/usr/src
.if !exists(${SRCDIR}/Makefile)
BUILD_DEPENDS=	${SRCDIR}/Makefile:os/src
.endif

USES=	os:flavors
PREFIX=/
EXTRACT_ONLY=
DISTFILES=
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

# This is utterly stoopid, but don't have a better solution right now
# Running concurrent builds of buildkernel in poudriere causes some failures
# where builds are trampling on each other... Something is being done
# outside of MAKEOBJDIRPREFIX...
KERNWRKSRC="${WRKDIR}/src"

check-sanity:

do-build:
	@if [ ! -d "${KERNWRKSRC}" ] ; then \
		cp -R ${WRKSRC} ${KERNWRKSRC}; \
	fi
	cd ${KERNWRKSRC} && env -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} ${MCONF} ${KERNEL_MAKE_FLAGS} \
		KERNCONF=${KERNCONF} \
		${MFLAGS} \
		buildkernel

do-install:
	${MKDIR} -p ${STAGEDIR}/kernel-debug
	${MKDIR} -p ${STAGEDIR}/usr/dist
	cd ${KERNWRKSRC} && env -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} ${MCONF} ${KERNEL_MAKE_FLAGS} \
		KERNCONF=${KERNCONF} \
		${MFLAGS} \
	       	DESTDIR=${STAGEDIR}/kernel-debug \
		installkernel
	mv ${STAGEDIR}/kernel-debug/boot/kernel ${STAGEDIR}/kernel-debug/boot/kernel-debug
	tar cvJf ${STAGEDIR}${OS_KERNDIST_DEBUG} -C ${STAGEDIR}/kernel-debug .
	chflags -R noschg ${STAGEDIR}/kernel-debug
	${RM} -rf ${STAGEDIR}/kernel-debug

.include <bsd.port.post.mk>

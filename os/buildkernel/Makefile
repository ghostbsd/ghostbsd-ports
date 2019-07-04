# $FreeBSD$

PORTNAME=	buildkernel
PORTVERSION=	${BASEPKG_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Distribution tarball of kernel for packaging

SRCDIR?=/usr/src
.if !exists(${SRCDIR}/Makefile)
BUILD_DEPENDS=	${SRCDIR}/Makefile:os/src
.endif

USES=	os:flavors

PREFIX=/
WITHOUT_FBSD10_FIX=	yes
WRKSRC=${SRCDIR}
PLIST_FILES+=	${OS_KERNDIST}
LOCAL_SDIR?=	/usr/local_source
NEED_ROOT=	yes
.if exists(${LOCAL_SDIR}/${PORTNAME})
WRKSRC=	${LOCAL_SDIR}/${PORTNAME}
.endif

# Set default non-debug config for HEAD / Other
.if exists(${SRCDIR}/sys/${ARCH}/conf/GENERIC-NODEBUG)
KERNCONF?=	GENERIC-NODEBUG
.else
KERNCONF?=	GENERIC
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
	@${MKDIR} ${STAGEDIR}/kernel
	@${MKDIR} ${STAGEDIR}/usr/dist
	cd ${WRKSRC} && ${SETENV} -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} ${MCONF} ${KERNEL_MAKE_FLAGS} \
		KERNCONF=${KERNCONF} \
		${MFLAGS} \
		DESTDIR=${STAGEDIR}/kernel \
		installkernel
	${TAR} cvJf ${STAGEDIR}/${OS_KERNDIST} -C ${STAGEDIR}/kernel .
	${CHFLAGS} -R noschg ${STAGEDIR}/kernel
	${RM} -rf ${STAGEDIR}/kernel

.include "../Makefile.common"
.include <bsd.port.post.mk>

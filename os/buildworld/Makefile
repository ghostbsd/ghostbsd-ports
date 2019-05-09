# $FreeBSD$

.include "../Makefile.common"

PORTNAME=	buildworld
PORTVERSION=	${OS_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}

MAINTAINER=	kris@ixsystems.com
COMMENT=	Port for the buildworld phase of OS

SRCDIR?=	/usr/src
BUILD_DEPENDS=	${SRCDIR}/Makefile:os/src

USES=	os:flavors
PREFIX=/
EXTRACT_ONLY=
DISTFILES=
SRCDIR?=/usr/src
WRKSRC=${SRCDIR}
WITHOUT_FBSD10_FIX=	yes
LOCAL_SDIR?=	/usr/local_source
NEED_ROOT=	yes
.if exists(${LOCAL_SDIR}/${PORTNAME})
WRKSRC=	${LOCAL_SDIR}/${PORTNAME}
.endif

.include "Makefile.options"
.include "Makefile.options.desc"

.include <bsd.port.pre.mk>

.for var in ${OPTIONS_DEFINE}
.if !${PORT_OPTIONS:M${var}}
MFLAGS+=	WITHOUT_${var}=YES
.else
MFLAGS+=	WITH_${var}=YES
.endif
.endfor

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

PLIST_FILES+=	${OS_WORLDDIST}

# This is broken right now
#MFLAGS+=	MAKEOBJDIRPREFIX=${WRKDIR}/obj

check-sanity:

do-build:
	cd ${WRKSRC} && env -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} ${MCONF} ${WORLD_MAKE_FLAGS} \
		${MFLAGS} \
		buildworld

do-install:
	${MKDIR} -p ${STAGEDIR}/world
	${MKDIR} -p ${STAGEDIR}/usr/dist
	cd ${WRKSRC} && env -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} ${MCONF} ${WORLD_MAKE_FLAGS} \
		${MFLAGS} \
	       	DESTDIR=${STAGEDIR}/world \
		installworld
	cd ${WRKSRC} && env -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} ${MCONF} ${WORLD_MAKE_FLAGS} \
		${MFLAGS} \
		DESTDIR=${STAGEDIR}/world \
		distribution
	if [ -e "${PORTSDIR}/local_source/trueos-manifest.json" ] ; then \
		${CP} ${FILESDIR}/trueos-manifest.json ${STAGEDIR}/world/var/db/trueos-manifest.json ; \
	elif [ -n "${TRUEOS_MANIFEST}" -a -e "${TRUEOS_MANIFEST}" ] ; then \
		cp ${TRUEOS_MANIFEST} ${STAGEDIR}/world/var/db/trueos-manifest.json ; \
	fi
	tar cvJf ${STAGEDIR}${OS_WORLDDIST} -C ${STAGEDIR}/world .
	chflags -R noschg ${STAGEDIR}/world
	rm -rf ${STAGEDIR}/world

clean:
	@if [ -d ${WRKDIR} ]; then \
		if [ -w ${WRKDIR} ]; then \
			${ECHO_MSG} "===> Cleaning for ${PKGNAME}"; \
			chflags -R noschg ${WRKDIR} ; \
			${RM} -r ${WRKDIR}; \
		else \
			${ECHO_MSG} "===>   ${WRKDIR} not writable, skipping"; \
		fi; \
	fi

.include <bsd.port.post.mk>

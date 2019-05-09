# $FreeBSD$

.include "../Makefile.common"

PORTNAME=	userland-base
PORTVERSION=	${OS_PORTVERSION}
PORTREVISION=	7
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}

MAINTAINER=	kris@ixsystems.com
COMMENT=	Port for the OS userland binaries

BUILD_DEPENDS=	${OS_WORLDDIST}:os/buildworld@${OS_FLAVOR} \
		${LOCALBASE}/bin/jq:textproc/jq

USES=	os:flavors
PREFIX=/
EXTRACT_ONLY=
DISTFILES=
NEED_ROOT=	yes
PKGVITAL=	yes

NO_OPTIONS_SORT=	yes

.include <bsd.port.pre.mk>

do-build:
	@${MKDIR} -p ${STAGEDIR}
	@${ECHO_MSG} "==> Extracting ${OS_WORLDDIST}..."
	@${TAR} xpf ${OS_WORLDDIST} -C ${STAGEDIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/pkgbase.setup.in ${STAGEDIR}/etc/pkgbase.setup
	@if [ -n "${STAGEDIR}/var/db/trueos-manifest.json" ] ; then \
		sh ${FILESDIR}/mk-pkg-repo.sh ${STAGEDIR}/var/db/trueos-manifest.json ${STAGEDIR} ; \
	fi
	@${ECHO} "${_OSVERSION_MAJOR}-${PKGVERSION}" > ${STAGEDIR}/etc/base_version

do-install:
	@${ECHO_MSG} "==> Generating plist..."
	@(cd ${STAGEDIR}; ${FIND} . \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -e 'usr/lib/debug' -e 'usr/tests' -e 'usr/lib32' -e 'usr/share/doc' -e 'usr/share/man' \
		>> ${TMPPLIST})
	@(cd ${STAGEDIR}; ${FIND} ./ \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -e '/' \
		| ${GREP} -v -e 'usr/lib/debug' -e 'usr/tests' -e 'usr/lib32' -e 'usr/share/doc' -e 'usr/share/man' \
		| ${XARGS} -I '{}' echo "@dir {}" \
		| ${GREP} -v -w '@dir ' \
		| ${CAT} >> ${TMPPLIST})
	@sh ${FILESDIR}/scrubplist.sh ${FILESDIR}/configs ${TMPPLIST} ${STAGEDIR}

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

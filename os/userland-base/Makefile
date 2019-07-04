# $FreeBSD$

PORTNAME=	userland-base
PORTVERSION=	${BASEPKG_PORTVERSION}
PORTREVISION=	4
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	FreeBSD base system share and libexec dirs

BUILD_DEPENDS=	${OS_WORLDDIST}:os/buildworld@${OS_FLAVOR} \
				jq:textproc/jq
RUN_DEPENDS=	/libexec/ld-elf.so.1:os/userland-base-bootstrap@${OS_FLAVOR} \
		/bin/sh:os/userland-bin@${OS_FLAVOR} \
		/boot/defaults/loader.conf:os/userland-boot@${OS_FLAVOR} \
		/etc/rc:os/userland-conf@${OS_FLAVOR} \
		/usr/lib/libelf.so:os/userland-lib@${OS_FLAVOR} \
		/rescue/sh:os/userland-rescue@${OS_FLAVOR} \
		/sbin/init:os/userland-sbin@${OS_FLAVOR}

USES=	os:flavors

PREFIX=/
NEED_ROOT=	yes
PKGVITAL=	yes

.include <bsd.port.pre.mk>

do-build:
	@${MKDIR} ${STAGEDIR}
	${ECHO_MSG} "==> Extracting ${OS_WORLDDIST}..."
	${TAR} xpf ${OS_WORLDDIST} -C ${STAGEDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/base-update.in ${STAGEDIR}/usr/sbin/base-update
	${INSTALL_SCRIPT} ${FILESDIR}/pkgbase.setup.in ${STAGEDIR}/etc/pkgbase.setup
	if [ -e "${STAGEDIR}/var/db/trueos-manifest.json" ] ; then \
		${SH} ${FILESDIR}/mk-pkg-repo.sh ${STAGEDIR}/var/db/trueos-manifest.json ${STAGEDIR} ; \
	fi
	${ECHO} "${_OSVERSION_MAJOR}-${PKGVERSION}" > ${STAGEDIR}/etc/base_version

do-install:
	${ECHO_MSG} "==> Generating plist..."
	${ECHO} "usr/sbin/base-update" >> ${TMPPLIST}
	${ECHO} "etc/pkgbase.setup" >> ${TMPPLIST}
	if [ -e "${STAGEDIR}/etc/pkg/Train.conf" ] ; then \
		${ECHO} "etc/pkg/Train.conf" >> ${TMPPLIST} ; \
	fi
	(cd ${STAGEDIR}; ${FIND} . \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -f ${FILESDIR}/exclude-list \
		>> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} ./ \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -e '/' \
		| ${GREP} -v -f ${FILESDIR}/exclude-list \
		| ${XARGS} -I '{}' echo "@dir {}" \
		| ${GREP} -v -w '@dir ' \
		| ${CAT} >> ${TMPPLIST})
	${SH} ${FILESDIR}/scrubplist.sh ${FILESDIR}/configs ${TMPPLIST} ${STAGEDIR}

clean:
	if [ -d ${WRKDIR} ]; then \
		if [ -w ${WRKDIR} ]; then \
			${ECHO_MSG} "===> Cleaning for ${PKGNAME}"; \
			${CHFLAGS} -R noschg ${WRKDIR} ; \
			${RM} -r ${WRKDIR}; \
		else \
			${ECHO_MSG} "===>   ${WRKDIR} not writable, skipping"; \
		fi; \
	fi

.include "../Makefile.common"
.include <bsd.port.post.mk>

# $FreeBSD$

PORTNAME=	userland-base
PORTVERSION=	${BASEPKG_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Port for the OS userland binaries

BUILD_DEPENDS=	${OS_WORLDDIST}:os/buildworld@${OS_FLAVOR} \
		${LOCALBASE}/bin/jq:textproc/jq
RUN_DEPENDS=	/libexec/ld-elf.so.1:os/userland-base-bootstrap@${OS_FLAVOR}

USES=	os:flavors

PREFIX=/
NEED_ROOT=	yes
PKGVITAL=	yes

NO_OPTIONS_SORT=	yes

.include <bsd.port.pre.mk>

do-build:
	@${MKDIR} ${STAGEDIR}
	@${ECHO_MSG} "==> Extracting ${OS_WORLDDIST}..."
	@${TAR} xpf ${OS_WORLDDIST} \
		--exclude ./libexec/ld-elf.so.1 \
		--exclude ./libexec/ld-elf32.so.1 \
		--exclude ./lib/libc.* \
		--exclude ./lib/libthr.* \
		--exclude ./lib/libm.* \
		--exclude ./usr/lib/libc.so \
		--exclude ./usr/lib/libthr.so \
		--exclude ./usr/lib/libm.so \
		-C ${STAGEDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/pkgbase.setup.in ${STAGEDIR}/etc/pkgbase.setup
	@if [ -n "${STAGEDIR}/var/db/trueos-manifest.json" ] ; then \
		${SH} ${FILESDIR}/mk-pkg-repo.sh ${STAGEDIR}/var/db/trueos-manifest.json ${STAGEDIR} ; \
	fi
	@${ECHO} "${_OSVERSION_MAJOR}-${PKGVERSION}" > ${STAGEDIR}/etc/base_version

do-install:
	@${ECHO_MSG} "==> Generating plist..."
	@(cd ${STAGEDIR}; ${FIND} . \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v \
			-e 'etc/login.conf.db' \
			-e 'etc/pwd.db' \
			-e 'etc/spwd.db' \
			-e 'usr/lib/debug' \
			-e 'usr/tests' \
			-e 'usr/lib32' \
			-e 'usr/share/doc' \
			-e 'usr/share/man' \
			-e 'var/db/services.db' \
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
	@${SH} ${FILESDIR}/scrubplist.sh ${FILESDIR}/configs ${TMPPLIST} ${STAGEDIR}

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

.include "../Makefile.common"
.include <bsd.port.post.mk>

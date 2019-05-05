# $FreeBSD$

.include "../Makefile.common"

PORTNAME=	userland-tests
PORTVERSION=	${OS_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}

MAINTAINER=	kris@ixsystems.com
COMMENT=	Userland tests

BUILD_DEPENDS=  ${OS_WORLDDIST}:os/buildworld@${OS_FLAVOR}

USES=	os:flavors
PREFIX=/
EXTRACT_ONLY=
DISTFILES=
NEED_ROOT=yes

.include <bsd.port.pre.mk>

do-build:
	@${MKDIR} -p ${STAGEDIR}
	@${ECHO_MSG} "==> Extracting ${OS_WORLDDIST}..."
	@${TAR} xpf ${OS_WORLDDIST} -C ${STAGEDIR}

do-install:
	@${ECHO_MSG} "==> Generating plist..."
	@(cd ${STAGEDIR}; ${FIND} ./usr/tests \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		>> ${TMPPLIST})
	@(cd ${STAGEDIR}; ${FIND} ./usr/tests \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -x '/' \
		| ${XARGS} -I '{}' echo "@dir {}" \
		| ${GREP} -v -x '@dir ' \
		| ${CAT} >> ${TMPPLIST})
	@sh ${PORTSDIR}/os/userland-base/files/scrubplist.sh \
		${PORTSDIR}/os/userland-base/files/configs \
		${TMPPLIST} ${STAGEDIR}

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

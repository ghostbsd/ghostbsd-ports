# $FreeBSD$

PORTNAME=	userland-lib
PORTVERSION=	${BASEPKG_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Userland library files

BUILD_DEPENDS=  ${OS_WORLDDIST}:os/buildworld@${OS_FLAVOR}

USES=	os:flavors

PREFIX=/
NEED_ROOT=	yes

.include <bsd.port.pre.mk>

do-build:
	@${MKDIR} ${STAGEDIR}
	${ECHO_MSG} "==> Extracting ${OS_WORLDDIST}..."
	${TAR} xpf ${OS_WORLDDIST} -C ${STAGEDIR}

do-install:
	${ECHO_MSG} "==> Generating plist..."
	(cd ${STAGEDIR}; ${FIND} ./lib ./usr/lib \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -e '\.a' \
		| ${GREP} -v -e 'usr/lib/debug' \
		| ${GREP} -v -e 'lib/libc\.so' \
		| ${GREP} -v -e 'lib/libthr\.so' \
		| ${GREP} -v -e 'lib/libm\.so' \
		| ${GREP} -v -e 'usr/lib/clang' \
		>> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} ./lib ./usr/lib \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -x '/' \
		| ${GREP} -v -e 'usr/lib/debug' \
		| ${GREP} -v -e 'usr/lib/clang' \
		| ${XARGS} -I '{}' echo "@dir {}" \
		| ${GREP} -v -x '@dir ' \
		| ${CAT} >> ${TMPPLIST})

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

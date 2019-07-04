# $FreeBSD$

PORTNAME=	userland-devel
PORTVERSION=	${BASEPKG_PORTVERSION}
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	FreeBSD userland compilers and libraries

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
	(cd ${STAGEDIR}; ${FIND} ./usr/bin ./usr/include ./usr/lib \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -e 'usr/include' \
			-e '\.a' \
			-e 'usr/bin/lldb' \
			-e 'usr/bin/llvm' \
			-e 'usr/bin/ld' \
			-e 'usr/bin/ld\.' \
			-e 'usr/bin/c++' \
			-e 'usr/bin/cc' \
			-e 'usr/bin/clang' \
			-e 'usr/lib/clang' \
		| grep -v -e 'usr/lib/debug' \
		>> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} ./usr/include ./usr/lib \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -x '/' \
		| ${GREP} -v -e 'usr/lib/debug' \
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

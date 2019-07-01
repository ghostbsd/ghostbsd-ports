# $FreeBSD$

PORTNAME=	userland-base-bootstrap
PORTVERSION=	${BASEPKG_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	os
PKGNAMEPREFIX=	${OS_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Port for libelf, rtld and other critical early libraries

BUILD_DEPENDS=	${OS_WORLDDIST}:os/buildworld@${OS_FLAVOR}

USES=	os:flavors

PREFIX=/
NEED_ROOT=	yes
PKGVITAL=	yes

.include <bsd.port.pre.mk>

do-build:
	@${MKDIR} ${STAGEDIR}
	${ECHO_MSG} "==> Extracting ${OS_WORLDDIST}..."
	${TAR} xpf ${OS_WORLDDIST} -C ${STAGEDIR}

do-install:
	${ECHO_MSG} "==> Generating plist..."
	(cd ${STAGEDIR}; ${FIND} ./libexec/ld-elf* ./lib/libc.* ./lib/libthr.* ./lib/libm.* \
		./usr/lib/libthr.* ./usr/lib/libm.* ./usr/lib/libc.* \
		\( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -e '\.a' \
		>> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} ./libexec ./lib ./usr/lib \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${GREP} -v -e '/' \
		| ${XARGS} -I '{}' echo "@dir {}" \
		| ${GREP} -v -w '@dir ' \
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

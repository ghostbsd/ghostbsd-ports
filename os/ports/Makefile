# $FreeBSD$

PORTNAME=	ports
PORTVERSION=	${BASEPKG_PORTVERSION}
CATEGORIES=	os
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	FreeBSD ports tree

PREFIX=/
BASE_PORTSDIR?=	/usr/ports
SRCDIR?=/usr/ports
NO_BUILD=	yes
WITHOUT_FBSD10_FIX=	yes
WRKSRC=	${BASE_PORTSDIR}

.include <bsd.port.pre.mk>

patch:
	${MKDIR} ${WRKDIR}

checksum fetch extract:
	${ECHO_MSG} ${.TARGET} not needed because building direct

stage-qa: stage

do-install:
	@${MKDIR} ${STAGEDIR}/${SRCDIR}
	${TAR} cf - -C ${WRKSRC} --exclude ./distfiles \
		--exclude ./work/ \
		--exclude .git \
		--exclude .svn . \
		| ${TAR} xpf - -C ${STAGEDIR}/${SRCDIR}
	(cd ${STAGEDIR}; ${FIND} . \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} .${SRCDIR} \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${XARGS} -I '{}' echo "@dir {}" >> ${TMPPLIST})

.include "../Makefile.common"
.include <bsd.port.post.mk>

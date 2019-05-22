# $FreeBSD$

.include "../Makefile.common"

PORTNAME=	src
PORTVERSION=	${OS_PORTVERSION}
PORTREVISION=	2
CATEGORIES=	os

MAINTAINER=	kris@ixsystems.com
COMMENT=	Port for the OS base sources

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	trueos
GH_TAGNAME=	86fbeda9c362564224db114156d71095eaac6f8f

PREFIX=/
SRCDIR?=/usr/src
NO_BUILD=	yes
WITHOUT_FBSD10_FIX=	yes
.if defined(${OS_SRCDIR}) && exists(${OS_SRCDIR})
WRKSRC=	${OS_SRCDIR}
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCAL_SDIR}/${PORTNAME})
checksum fetch:
	${ECHO_MSG} ${.TARGET} not needed because building direct
.endif

stage-qa: stage

do-install:
	${MKDIR} -p ${STAGEDIR}${SRCDIR}
	${TAR} cf - -C ${WRKSRC} --exclude .git --exclude .svn . | ${TAR} xpf - -C ${STAGEDIR}${SRCDIR}
	(cd ${STAGEDIR}; ${FIND} . \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} .${SRCDIR} \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${XARGS} -I '{}' echo "@dir {}" >> ${TMPPLIST})

.include <bsd.port.post.mk>

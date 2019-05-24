# $FreeBSD$

PORTNAME=	zol
PORTVERSION=	201905240000
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-src

MAINTAINER=	waqar@ixsystems.com
COMMENT=	Port for ZoL sources

USE_GITHUB=	yes
GH_ACCOUNT=	zfsonfreebsd
GH_PROJECT=	ZoF
GH_TAGNAME=	400b361

PREFIX=/
SRCDIR?=/usr/local/share/zol-src
NO_BUILD=	yes
LOCAL_SDIR?=	/usr/local_source
.if exists(${LOCAL_SDIR}/${PORTNAME})
WRKSRC=	${LOCAL_SDIR}/${PORTNAME}
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCAL_SDIR}/${PORTNAME})
checksum fetch:
	${ECHO_MSG} ${.TARGET} not needed because building direct
.endif

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

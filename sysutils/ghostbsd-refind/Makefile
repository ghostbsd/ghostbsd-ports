# Created by: Eric Turgeon <ericturgeon@GhostBSD.org>
# $FreeBSD$

PORTNAME=	ghostbsd-refind
PORTVERSION=	0.1
CATEGORIES=	x11-themes

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	rEFInd is an EFI boot manager utility

LICENSE=	BSD3CLAUSE GPLv3
LICENSE_COMB=   multi
LICENSE_FILE_BSD3CLAUSE=    ${WRKSRC}/refind/LICENSE.txt
LICENSE_FILE_GPLv3=    ${WRKSRC}/refind/COPYING.txt

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/refind
	${CP} -R ${WRKSRC}/refind/* ${STAGEDIR}${PREFIX}/refind/
.include <bsd.port.mk>

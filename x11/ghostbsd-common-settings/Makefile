# Created by: Angelescu Ovidiu  <angelescuo@yahoo.com>
# $FreeBSD$

PORTNAME=	ghostbsd-common-settings
PORTVERSION=	4.7
CATEGORIES=	x11

MAINTAINER=	eriturgeon@ghostbsd.org
COMMENT=	GhostBSD common settings in installed mode

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_BUILD=	yes

RUN_DEPENDS= dpkg:archivers/dpkg

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/sounds
	${CP} -R   ${WRKSRC}/local/* ${STAGEDIR}/${PREFIX}
.include <bsd.port.mk>

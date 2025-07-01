PORTNAME=	apps-projectcenter
DISTVERSION=	20250628
CATEGORIES=	devel gnustep
PKGNAMEPREFIX=	gershwin-

MAINTAINER=	jpm820@proton.me
COMMENT=	Development environment for GNUstep
WWW=		http://www.gnustep.org/experience/ProjectCenter.html

LICENSE=	GPLv2+ # comment in code; COPYING says GPLv3

USES=		gershwin
CONFLICTS=	projectcenter
USE_GERSHWIN=	back build

USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_TAGNAME=	b7fcad4

MAKE_ARGS+=     GNUSTEP_INSTALLATION_DOMAIN=LOCAL

.include <bsd.port.mk>

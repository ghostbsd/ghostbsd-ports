PORTNAME=	gershwin-workspace
DISTVERSION=	20260129
CATEGORIES=	deskutils gnustep

MAINTAINER=	jpm820@proton.me
COMMENT=	Gershwin workspace manager
WWW=		https://github.com/gershwin-desktop/gershwin-workspace

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:devel/dbus

USES=		gershwin pkgconfig
CONFLICTS=	gworkspace
USE_GERSHWIN=	back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-desktop
GH_TAGNAME=	1bc3b988

GNU_CONFIGURE=	yes

pre-configure:
	${RM} -r ${WRKSRC}/GWMetadata

.include <bsd.port.mk>

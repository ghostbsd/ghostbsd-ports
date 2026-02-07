PORTNAME=	gershwin
PORTVERSION=	20260129
CATEGORIES=	x11 gnustep
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jpm820@proton.me
COMMENT=	GNUstep Gershwin desktop environment meta port
WWW=		https://github.com/gershwin-desktop/gershwin-desktop

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	gershwin-system>0:misc/gershwin-system \
		gershwin-libdispatch>0:devel/gershwin-libdispatch \
		gershwin-tools-make>0:devel/gershwin-tools-make \
		gershwin-libobjc2>0:lang/gershwin-libobjc2 \
		gershwin-libs-base>0:lang/gershwin-libs-base \
		gershwin-libs-gui>0:x11-toolkits/gershwin-libs-gui \
		gershwin-libs-back>0:x11-toolkits/gershwin-libs-back \
		gershwin-eau-theme>0:x11-themes/gershwin-eau-theme \
		gershwin-workspace>0:deskutils/gershwin-workspace \
		gershwin-systempreferences>0:deskutils/gershwin-systempreferences \
		gershwin-textedit>0:deskutils/gershwin-textedit \
		gershwin-terminal>0:x11/gershwin-terminal \

USES=		metaport

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}
	${ECHO_CMD} "This is a meta port for the Gershwin desktop environment." > \
		${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}/README

.include <bsd.port.mk>

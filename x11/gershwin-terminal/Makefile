PORTNAME=	gershwin-terminal
DISTVERSION=	20250628
CATEGORIES=	x11 gnustep

MAINTAINER=	jpm820@proton.me
COMMENT=	Gershwin Terminal Emulator for GNUstep
WWW=		https://github.com/gershwin-desktop/gershwin-terminal

LICENSE=	GPLv2 # only

USES=		gershwin iconv
CONFLICTS=	terminal.app
USE_GERSHWIN=	back build

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-desktop
GH_TAGNAME=	c3def51

MAKE_ARGS+=	Terminal_TOOL_LIBS='${ICONV_LIB} -lutil'

.include <bsd.port.mk>

PORTNAME=	rofi
DISTVERSION?=	1.7.8
PORTREVISION?=	0
CATEGORIES=	x11 ${EXTRA_CATEGORIES}

MAINTAINER=	nomoo@nomoo.ru
COMMENT=	Window switcher, run dialog and dmenu replacement
WWW=		https://github.com/davatorium/rofi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libstartup-notification-1.so:x11/startup-notification \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-ewmh.so:x11/xcb-util-wm \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-util.so:x11/xcb-util \
		libxcb-xrm.so:x11/xcb-util-xrm \
		libxkbcommon-x11.so:x11/libxkbcommon \
		libxcb-keysyms.so:x11/xcb-util-keysyms
RUN_DEPENDS=	gsed:textproc/gsed

USES=		bison gnome meson pkgconfig shebangfix xorg
USE_GITHUB=	yes # required by rofi-wayland
USE_GNOME=	cairo gdkpixbuf librsvg2 pango
USE_XORG=	xcb
GH_ACCOUNT?=	davatorium
GH_TUPLE=	sardemff7:libgwater:d86f9903efb9c490c0e3b0316d7f2da5b5a5632c:libgwater/subprojects/libgwater \
		sardemff7:libnkutils:72bd7fb07f627a864e724639eea9fab6cccbd77c:libnkutils/subprojects/libnkutils
SHEBANG_FILES=	script/get_git_rev.sh \
		script/rofi-sensible-terminal
bash_CMD=	${SH}

CONFLICTS_INSTALL?=	${PORTNAME}-wayland

OPTIONS_DEFINE=	TEST MANPAGES
OPTIONS_DEFAULT=        MANPAGES
OPTIONS_SUB=            yes

MANPAGES_BUILD_DEPENDS=         pandoc:textproc/hs-pandoc

TEST_BUILD_DEPENDS=	checkmk:devel/check
TEST_MESON_ENABLED=	check

post-patch:
# Fix rofi-theme-selector which assumes we have GNU sed
	@${REINPLACE_CMD} 's|$${SED} -i |$${SED} -i"" |' \
		${WRKSRC}/script/rofi-theme-selector

.include <bsd.port.mk>

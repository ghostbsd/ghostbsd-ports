PORTNAME=	dfuife-curses
PORTVERSION=	1.5.1.20050829
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://people.xmms2.org/~alex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DFUI curses frontend

LICENSE=	BSD3CLAUSE

DEPRECATED=	Depends on deprecated port devel/libaura
EXPIRATION_DATE=2025-06-30

LIB_DEPENDS=	libaura3.so:devel/libaura \
		libdfui4.so:devel/libdfui

USES=		ncurses tar:bzip2

PLIST_FILES=	bin/dfuife_curses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dfuife_curses ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

PORTNAME=	wop
PORTVERSION=	0.4.3
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	https://mirror.amdmi3.ru/distfiles/
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}data-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free real-time Worms game
WWW=		https://web.archive.org/web/20141218154118/http://wormsofprey.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	makedepend:devel/makedepend

USES=		gmake sdl tar:bzip2
USE_SDL=	sdl net mixer ttf image
USE_CXXSTD=	c++98

MAKE_JOBS_UNSAFE=	yes
CXXFLAGS+=	-Wno-c++11-narrowing -Wno-reserved-user-defined-literal

DATAVERSION=	2005-12-21
DESKTOP_ENTRIES="Worms of Prey" \
		"Real-time Worms game" \
		"${DATADIR}/images/gui/wop32.png" \
		"wop" \
		"Game;ActionGame;" \
		false

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|__va_copy|va_copy|g' ${WRKSRC}/src/string.cpp
	@${REINPLACE_CMD} -e 's|; make|; ${MAKE_CMD}|g' ${WRKSRC}/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/sdlwidgets/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|= g++|?= g++|g' ${WRKSRC}/sdlwidgets/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|/etc/woprc|${PREFIX}/etc/woprc|' ${WRKSRC}/src/wopsettings.cpp
	@${REINPLACE_CMD} -e 's|\./data|${DATADIR}|' ${WRKSRC}/woprc
	@${REINPLACE_CMD} -e '/stdint.h/ d' ${WRKSRC}/src/attachableobject.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/wop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/woprc ${STAGEDIR}${PREFIX}/etc/woprc.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKDIR}/${PORTNAME}data-${DATAVERSION} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog README README-COMMAND-LINE-OPTIONS.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>

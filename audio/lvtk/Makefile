PORTNAME=	lvtk
DISTVERSION=	2.0.0rc1-14
DISTVERSIONSUFFIX=	-g1028f69
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Wraps the LV2 C API and extensions into easy to use C++ classes
WWW=		https://github.com/lvtk/lvtk

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		configure fails: waf is not compatible with python-3.12: No module named 'imp', see https://github.com/lvtk/lvtk/issues/60

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/gtkmm-2.4/gtkmm.h:x11-toolkits/gtkmm24

USES=		compiler:c++11-lang pkgconfig waf
USE_GITHUB=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/lvtk.lv2/volume.so

.include <bsd.port.mk>

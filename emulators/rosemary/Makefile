PORTNAME=	rosemary
PORTVERSION=	0.5.0.20261122
CATEGORIES=	emulators

MAINTAINER=	rafaelpasquarella@gmail.com
COMMENT=	Compatibility layer for running macOS applications
WWW=		https://github.com/microlift/rosemary

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	runs x86-64 macOS programs natively, without the lifter on other hosts yet

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/lib/libSDL3.so.0:devel/sdl3 \
		${LOCALBASE}/lib/libvulkan.so.1:graphics/vulkan-loader

USES=		cargo gl
USE_GITHUB=	yes
GH_ACCOUNT=	microlift
GH_TAGNAME=	27beeb53c385c9b04c0d33f8c040c724022c7ae4
USE_GL=		egl

CARGO_BUILD_ARGS=	--bin rosemary
CARGO_INSTALL_PATH=	crates/rosemary

CONFLICTS_INSTALL=	rosemary-ginrose

PLIST_FILES=	bin/rosemary

OPTIONS_DEFINE=		OPENAL
OPTIONS_DEFAULT=	OPENAL
OPENAL_DESC=		OpenAL for programs that use Apple's OpenAL framework
OPENAL_RUN_DEPENDS=	${LOCALBASE}/lib/libopenal.so.1:audio/openal-soft

.include <bsd.port.mk>

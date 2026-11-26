PORTNAME=	rosemary
PORTVERSION=	26.0.5.0
CATEGORIES=	emulators
PKGNAMESUFFIX=	-ginrose

MAINTAINER=	rafaelpasquarella@gmail.com
COMMENT=	Ginrose's build of Rosemary, a compatibility layer for macOS apps
WWW=		https://github.com/nunreasonable/rosemary

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	runs x86-64 macOS programs natively, without the lifter on other hosts yet

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/lib/libSDL3.so.0:devel/sdl3 \
		${LOCALBASE}/lib/libvulkan.so.1:graphics/vulkan-loader

USES=		cargo gl
USE_GITHUB=	yes
GH_ACCOUNT=	nunreasonable
GH_TAGNAME=	ginrose-26.0.5.0
USE_GL=		egl

CARGO_BUILD_ARGS=	--bin rosemary
CARGO_INSTALL_PATH=	crates/rosemary

CONFLICTS_INSTALL=	rosemary

PLIST_FILES=	bin/rosemary

OPTIONS_DEFINE=		OPENAL
OPTIONS_DEFAULT=	OPENAL
OPENAL_DESC=		OpenAL for programs that use Apple's OpenAL framework
OPENAL_RUN_DEPENDS=	${LOCALBASE}/lib/libopenal.so.1:audio/openal-soft

.include <bsd.port.mk>

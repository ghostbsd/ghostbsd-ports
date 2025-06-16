PORTNAME=	libs-base
DISTVERSION=	20250615
CATEGORIES=	lang devel gnustep
PKGNAMEPREFIX=	gershwin-

MAINTAINER=	jpm820@proton.me
COMMENT=	GNUstep Foundation library
WWW=		http://www.gnustep.org/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libffi.so:devel/libffi \
		libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp

USES=		pkgconfig iconv gnome gershwin

RUN_DEPENDS=	${GNUSTEP_PREFIX}System/Library/Makefiles/GNUstep.sh:devel/gershwin-tools-make

USE_GNOME=	libxml2 libxslt
USE_GITHUB=	yes
GH_ACCOUNT=	gnustep
GH_TAGNAME=	d147fba
USE_GERSHWIN=	build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}
CONFLICTS=	gnustep-base

OPTIONS_DEFINE=		ICU GNUTLS
OPTIONS_RADIO=		ZEROCONF
OPTIONS_RADIO_ZEROCONF=	AVAHI MDNS
OPTIONS_DEFAULT=	ICU GNUTLS AVAHI
OPTIONS_SUB=		yes

ZEROCONF_DESC=	Zeroconf (Bonjour) support
AVAHI_DESC=	Zeroconf via Avahi (preferred)
MDNS_DESC=	Zeroconf via mDNSResponder

ICU_LIB_DEPENDS=	libicuuc.so:devel/icu
ICU_CONFIGURE_OFF=	--disable-icu

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_OFF=	--disable-tls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libavahi-client.so:net/avahi-app
CONFIGURE_ARGS+=	--with-zeroconf-api=avahi
.elif ${PORT_OPTIONS:MMDNS}
LIB_DEPENDS+=	libdns_sd.so:net/mDNSResponder
CONFIGURE_ARGS+=	--with-zeroconf-api=mdns
.else
CONFIGURE_ARGS+=	--disable-zeroconf
.endif

.include <bsd.port.mk>

PORTNAME=	libxcrypt
DISTVERSIONPREFIX=	v
DISTVERSION=	4.4.38
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extended crypt library for descrypt, md5crypt, bcrypt, and others
WWW=		https://github.com/besser82/libxcrypt

LICENSE=	LGPL21

USES=		autoreconf gmake libtool pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	besser82

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-static

CFLAGS+=	-Wno-gnu-statement-expression

TEST_TARGET=	check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcrypt.so.2.0.0

.include <bsd.port.mk>

PORTNAME=	pkcs11-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	security

MAINTAINER=	eric.devolder@gmail.com
COMMENT=	Tools for managing PKCS11 cryptographic tokens
WWW=		https://github.com/Mastercard/pkcs11-tools

LICENSE=	APACHE20 THIRDPARTY
LICENSE_COMB=	multi
LICENSE_NAME_THIRDPARTY=	Third-party licenses
LICENSE_FILE_THIRDPARTY=	${WRKSRC}/docs/TPLICENSES.md
LICENSE_PERMS_THIRDPARTY=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	autoconf-archive>0:devel/autoconf-archive \
		flex:textproc/flex

USES=		autoreconf:build bison compiler:c11 libtool:build pkgconfig ssl

IGNORE_SSL=	libressl openssl111 openssl34
IGNORE_SSL_REASON_openssl111=	No support for OpenSSL 3.X providers
IGNORE_SSL_REASON_libressl=	No support for OpenSSL 3.X providers
IGNORE_SSL_REASON_openssl34=	No support for PQC algotithms

USE_GITHUB=	yes
GH_ACCOUNT=	Mastercard
GH_TUPLE=	coreutils:gnulib:34e1754363:gnulib \
		oasis-tcs:pkcs11:858bfc8:oasis_pkcs11

GNU_CONFIGURE=	yes

MAKE_ENV=	LIBCRYPTO_RPATH=${OPENSSLBASE}/lib

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	BASH DOCS ZSH
OPTIONS_DEFAULT=BASH ZSH
OPTIONS_SUB=	yes

post-extract:
	@${RMDIR} ${WRKSRC}/.gnulib ${WRKSRC}/include/oasis-pkcs11
	@${MV} ${WRKSRC_gnulib} ${WRKSRC}/.gnulib
	@${MV} ${WRKSRC_oasis_pkcs11} ${WRKSRC}/include/oasis-pkcs11

pre-configure:
	@cd ${WRKSRC} && BUILD_PORT=1 ${WRKSRC}/bootstrap.sh

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/README.md \
		${WRKSRC}/docs/INSTALL.md \
		${WRKSRC}/docs/MANUAL.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

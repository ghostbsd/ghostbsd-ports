PORTNAME=	ngrok
PORTVERSION=	2.2.8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://bin.equinox.io/a/${${ARCH}_HASH}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd-${ARCH:S/i386/386/}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Secure tunnels to localhost
WWW=		https://ngrok.com/

# run 'ngrok credits' for details
LICENSE=	APACHE20

ONLY_FOR_ARCHS=	amd64 i386

i386_HASH=	jsV5s66bZvF
amd64_HASH=	b8MLqEs7iBz

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/ngrok

NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

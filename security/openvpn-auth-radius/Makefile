PORTNAME=	openvpn-auth-radius
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	security net-vpn
MASTER_SITES=	http://www.nongnu.org/radiusplugin/ \
		http://svn-cache.ipcopaddons.org/
DISTNAME=	radiusplugin_v${PORTVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	RADIUS authentication plugin for OpenVPN
WWW=		https://www.nongnu.org/radiusplugin/index.html

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/sbin/openvpn:security/openvpn
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		gmake ssl
MAKEFILE=	Makefile.bsd
WRKSRC=		${WRKDIR}/radiusplugin

PORTDOCS=	README
PORTEXAMPLES=	radiusplugin.cnf
PLIST_FILES=	lib/radiusplugin.so

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_LIB} ${WRKSRC}/radiusplugin.so ${STAGEDIR}${LOCALBASE}/lib

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/radiusplugin.cnf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>

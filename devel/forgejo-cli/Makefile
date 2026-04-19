PORTNAME=	forgejo-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	devel
MASTER_SITES=	https://codeberg.org/forgejo-contrib/${PORTNAME}/archive/ \
		LOCAL/jrm:comp
DISTFILES=	${DISTVERSIONFULL}${EXTRACT_SUFX} \
		fj-comp-${DISTVERSIONFULL}${EXTRACT_SUFX}:comp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	CLI client for Forgejo
WWW=		https://codeberg.org/forgejo-contrib/forgejo-cli

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl

CARGO_ENV=	LIBGIT2_SYS_USE_PKG_CONFIG=1 \
		LIBSSH2_SYS_USE_PKG_CONFIG=1 \
		OPENSSL_DIR=${OPENSSLBASE}

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		 ${STAGEDIR}${PREFIX}/share/fish/completions \
		 ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKDIR}/fj-comp/fj \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_DATA} ${WRKDIR}/fj-comp/fj.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/
	${INSTALL_DATA} ${WRKDIR}/fj-comp/_fj \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>

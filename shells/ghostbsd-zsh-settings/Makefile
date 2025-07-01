PORTNAME=	ghostbsd-zsh-settings
PORTVERSION=	0.1
CATEGORIES=	shells

MAINTAINER=	jpm820@proton.me
COMMENT=	GhostBSD integration settings for the zsh shell

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=    zsh:shells/zsh \
		${LOCALBASE}/share/zsh-autosuggestions/zsh-autosuggestions.zsh:shells/zsh-autosuggestions \
		${LOCALBASE}/share/zsh/site-functions/_pkg:shells/zsh-completions

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	ghostbsd

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/zshrc ${STAGEDIR}${PREFIX}/etc/zshrc

.include <bsd.port.mk>

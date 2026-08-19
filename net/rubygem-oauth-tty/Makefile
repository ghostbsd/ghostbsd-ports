PORTNAME=	oauth-tty
PORTVERSION=	1.0.12
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OAuth 1.0 TTY Command Line Interface
WWW=		https://oauth-tty.galtzo.com/ \
		https://github.com/ruby-oauth/oauth-tty

LICENSE=	MIT
#LICENSE_FILE=	${WRKSRC}/MIT.md

RUN_DEPENDS=	rubygem-anonymous_loader>=0.1.1<1:devel/rubygem-anonymous_loader \
		rubygem-auth-sanitizer>=0.2.2<1:security/rubygem-auth-sanitizer \
		rubygem-version_gem>=1.1.12<2:devel/rubygem-version_gem

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/oauth

.include <bsd.port.mk>

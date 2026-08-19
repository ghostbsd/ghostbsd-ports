PORTNAME=	lambda
DISTVERSION=	0.1.4
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://uniquesoftwaredesigns.com/${PORTNAME}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Lambda calculus interpreter
WWW=		https://uniquesoftwaredesigns.com/lambda/docs/lambda.html

LICENSE=	GPLv2

DEPRECATED=		Upstream unmaintained since 2004
EXPIRATION_DATE=	2026-09-30

USES=		perl5 ncurses readline shebangfix
USE_CXXSTD=	c++14
USE_PERL5=	build

SHEBANG_FILES=	docs/trans_xml_for_cat.pl

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/lambda \
		share/lambda/definitions \
		share/lambda/definitions_with_numbers

DOCS=		lambda.html lambdamanual.html user_manual_style.css
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|-ltermcap|-lncurses|' ${WRKSRC}/configure \
		${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lambda ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/definitions* ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

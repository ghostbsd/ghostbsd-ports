# $FreeBSD$

PORTNAME=	sysup
PORTVERSION=	0.8.6
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	kris@ixsystems.com
COMMENT=	System Update Utility

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go
RUN_DEPENDS=	${LOCALBASE}/sbin/beadm:sysutils/beadm

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	trueos

GH_TUPLE=	gorilla:websocket:v1.4.0:websocket/src/github.com/gorilla/websocket

USE_RC_SUBR=	sysup

PLIST_FILES=	bin/sysup

post-extract:
	${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}
	${LN} -sf ${WRKSRC} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}
	${RM} ${WRKSRC}/go.mod

do-build:
	@${RM} -rf ${WRKSRC}/vendor
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} CGO_ENABLED=0 ${BUILD_ENV} GOPATH=${WRKSRC}\
	       go build -o sysup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sysup ${STAGEDIR}${PREFIX}/bin/sysup

.include <bsd.port.mk>

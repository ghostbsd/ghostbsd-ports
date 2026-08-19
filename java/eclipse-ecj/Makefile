PORTNAME=	ecj
PORTVERSION=	4.4.2
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/eclipse/downloads/drops4/R-${PORTVERSION}-${DROPDATE}/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	ecjsrc-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Eclipse Java Compiler
WWW=		https://www.eclipse.org/

LICENSE=	EPL

DEPRECATED=	No maintainer, last update was 2015, does not build with Java 11, only usage in the ports tree (math/scilab) was just deprecated. Mail the maintainer if you use this.
EXPIRATION_DATE=	2026-11-09

EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	xf
EXTRACT_AFTER_ARGS=	-C ${WRKSRC}

USES=		java:ant,run
JAVA_VERSION=	8

SUB_FILES=	ecj.sh
SUB_LIST=	PORTVERSION=${PORTVERSION}
NO_WRKSUBDIR=	yes

DROPDATE=	201502041700
PLIST_FILES=	bin/${PORTNAME}.sh \
		%%JAVAJARDIR%%/${PORTNAME}-${PORTVERSION}.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${PORTVERSION}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/ecj.sh ${STAGEDIR}/${PREFIX}/bin

.include <bsd.port.mk>

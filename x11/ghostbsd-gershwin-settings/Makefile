PORTNAME=	ghostbsd-gershwin-settings
PORTVERSION=	26.01.0
CATEGORIES=	x11

MAINTAINER=	jpm820@proton.me
COMMENT=	GhostBSD gershwin settings in installed mode
WWW=		http://www.ghostbsd.org

LICENSE=	BSD

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}

	# Recursively install bin/ scripts
	@cd ${WRKSRC}/bin && \
		${FIND} . -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/bin/{}" \; && \
		${FIND} . -type f -exec ${INSTALL_SCRIPT} "{}" "${STAGEDIR}${PREFIX}/bin/{}" \;

	# Recursively install etc files
	@cd ${WRKSRC}/etc && \
		${FIND} . -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/etc/{}" \; && \
		${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${PREFIX}/etc/{}" \;

	# Recursively install share files
	@cd ${WRKSRC}/share && \
		${FIND} . -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/share/{}" \; && \
		${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${PREFIX}/share/{}" \;

.include <bsd.port.mk>

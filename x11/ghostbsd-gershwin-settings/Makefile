PORTNAME=	ghostbsd-gershwin-settings
DISTVERSION=	20250722
CATEGORIES=	x11

MAINTAINER=	jpm820@proton.me
COMMENT=	GhostBSD integration settings for the Gershwin desktop
WWW=		https://github.com/gershwin-desktop/ghostbsd-gershwin-settings

LICENSE=	BSD2CLAUSE

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-desktop
GH_TAGNAME=	c383fb3

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

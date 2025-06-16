PORTNAME=	ghostbsd-gershwin-settings
DISTVERSION=	20250615
CATEGORIES=	x11

MAINTAINER=	jpm820@proton.me
COMMENT=	GhostBSD integration settings for the Gershwin desktop
WWW=		https://github.com/gershwin-os/ghostbsd-gershwin-settings

LICENSE=	BSD2CLAUSE

USES=		uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-os
GH_TAGNAME=	a30a073

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	# Install bin script
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gershwin-x11 ${STAGEDIR}${PREFIX}/bin/gershwin-x11

	# Install GTK settings
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gtk-2.0
	${INSTALL_DATA} ${WRKSRC}/etc/gtk-2.0/gtkrc ${STAGEDIR}${PREFIX}/etc/gtk-2.0/gtkrc

	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gtk-3.0
	${INSTALL_DATA} ${WRKSRC}/etc/gtk-3.0/settings.ini ${STAGEDIR}${PREFIX}/etc/gtk-3.0/settings.ini

	# Install sudoers snippets
	@${MKDIR} ${STAGEDIR}/etc/sudoers.d
	${INSTALL_DATA} ${WRKSRC}/etc/sudoers.d/10_gnustep_env_keep ${STAGEDIR}/etc/sudoers.d/
	${INSTALL_DATA} ${WRKSRC}/etc/sudoers.d/10_gnustep_secure_path ${STAGEDIR}/etc/sudoers.d/

	# Install X session desktop entry
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKSRC}/share/xsessions/gershwin.desktop ${STAGEDIR}${PREFIX}/share/xsessions/

.include <bsd.port.mk>

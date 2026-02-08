PORTNAME=	gershwin-components
DISTVERSION=	20260129
CATEGORIES=	deskutils gnustep

MAINTAINER=	jpm820@proton.me
COMMENT=	Gershwin desktop environment applications and preference panes
WWW=		https://github.com/gershwin-desktop/gershwin-components

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	gershwin-systempreferences>0:deskutils/gershwin-systempreferences

USES=		gershwin pkgconfig xorg
USE_GERSHWIN=	back build
USE_XORG=	x11 xau

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-desktop
GH_TAGNAME=	8bbf51f

# Components with GNUmakefile that can be built directly
# Excluding components that need PreferencePanes framework (Display, Keyboard, etc)
COMPONENTS=	DirectoryServices LoginWindow appwrap Console SudoAskPass Processes

# Components that need configure first
CONFIGURE_COMPONENTS=	Menu

do-build:
.for comp in ${CONFIGURE_COMPONENTS}
	@${ECHO_MSG} "===> Configuring ${comp}"
	cd ${WRKSRC}/${comp} && ${SETENV} ${CONFIGURE_ENV} ./configure
	@${ECHO_MSG} "===> Building ${comp}"
	cd ${WRKSRC}/${comp} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		CPPFLAGS="-DGNUSTEP_INSTALL_TYPE=SYSTEM" \
		${MAKE_ARGS} -j${MAKE_JOBS_NUMBER}
.endfor
.for comp in ${COMPONENTS}
	@${ECHO_MSG} "===> Building ${comp}"
	cd ${WRKSRC}/${comp} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		CPPFLAGS="-DGNUSTEP_INSTALL_TYPE=SYSTEM" \
		${MAKE_ARGS} -j${MAKE_JOBS_NUMBER}
.endfor

do-install:
# Menu requires manual install due to broken GNUstep install target
	@${ECHO_MSG} "===> Installing Menu"
	${MKDIR} ${STAGEDIR}/System/Library/CoreServices/Applications
	${CP} -R ${WRKSRC}/Menu/Menu.app ${STAGEDIR}/System/Library/CoreServices/Applications/
	${CP} ${WRKSRC}/Menu/Menu.png ${STAGEDIR}/System/Library/CoreServices/Applications/Menu.app/Resources/
# Create Menu symlink in Tools directory (like other apps)
	${MKDIR} ${STAGEDIR}/System/Library/Tools
	${LN} -sf ../CoreServices/Applications/Menu.app/Menu ${STAGEDIR}/System/Library/Tools/Menu
# Build and install Menu status item bundles
	cd ${WRKSRC}/Menu/StatusItems/SystemMonitor && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} all || true
	cd ${WRKSRC}/Menu/StatusItems/TimeDisplay && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} all || true
	${MKDIR} ${STAGEDIR}/System/Library/Menu/StatusItems
	-${CP} -R ${WRKSRC}/Menu/StatusItems/SystemMonitor/SystemMonitor.bundle ${STAGEDIR}/System/Library/Menu/StatusItems/
	-${CP} -R ${WRKSRC}/Menu/StatusItems/TimeDisplay/TimeDisplay.bundle ${STAGEDIR}/System/Library/Menu/StatusItems/
.for comp in ${COMPONENTS}
	@${ECHO_MSG} "===> Installing ${comp}"
	cd ${WRKSRC}/${comp} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS} DESTDIR=${STAGEDIR} install
.endfor

.include <bsd.port.mk>

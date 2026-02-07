PORTNAME=	gershwin-assets
DISTVERSION=	20260129
CATEGORIES=	misc

MAINTAINER=	jpm820@proton.me
COMMENT=	Gershwin desktop assets including fonts and wallpapers
WWW=		https://github.com/gershwin-desktop/gershwin-assets

LICENSE=	OFL11

BUILD_DEPENDS=	gershwin-tools-make>0:devel/gershwin-tools-make \
		gmake:devel/gmake

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-desktop
GH_TAGNAME=	9266b6e

NO_ARCH=	yes
NOPREFIX=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/bin/gmake -f GNUmakefile DESTDIR=${STAGEDIR} install

post-install:
	@${SED} -i '' 's|${STAGEDIR}||g' ${STAGEDIR}/System/Library/Receipts/Assets.stamp

.include <bsd.port.mk>

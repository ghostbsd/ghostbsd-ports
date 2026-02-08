PORTNAME=	gershwin-system
DISTVERSION=	20260129
CATEGORIES=	misc

MAINTAINER=	jpm820@proton.me
COMMENT=	Gershwin global defaults for GNUstep under /System
WWW=		https://github.com/gershwin-desktop/gershwin-system

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	gershwin-tools-make>0:devel/gershwin-tools-make \
		gmake:devel/gmake

USE_GITHUB=	yes
GH_ACCOUNT=	gershwin-desktop
GH_TAGNAME=	a016dc7

NO_ARCH=	yes
NOPREFIX=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/bin/gmake -f GNUmakefile DESTDIR=${STAGEDIR} install

post-install:
	@${SED} -i '' 's|${STAGEDIR}||g' ${STAGEDIR}/System/Library/Receipts/System.stamp

.include <bsd.port.mk>

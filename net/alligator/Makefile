PORTNAME=	alligator
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Kirigami-based RSS reader
WWW=		https://apps.kde.org/alligator/

LICENSE=	GPLv2

BUILD_DEPENDS=	kirigami-addons-qt5>=0:x11-toolkits/kirigami-addons-qt5
RUN_DEPENDS=	kirigami-addons-qt5>=0:x11-toolkits/kirigami-addons-qt5

USES=		cmake desktop-file-utils kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons ecm:build i18n syndication
USE_QT=		core declarative gui network quickcontrols2 sql testlib \
		widgets xml \
		buildtools:build qmake:build

.include <bsd.port.mk>

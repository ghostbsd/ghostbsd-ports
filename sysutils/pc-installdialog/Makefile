# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pc-installdialog
PORTVERSION=	2019070400
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	TrueOS Text Installer

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/bin/jq:textproc/jq

USES=		pkgconfig tar:xz
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

PLIST_FILES+=	sbin/pc-installdialog

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	pc-installdialog
GH_TAGNAME=	2209b715f33aeb2f51aa11c4fb4e6b435bd52da9

.include <bsd.port.mk>

# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pc-sysinstall
PORTVERSION=	2020092700
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	TrueOS install backend

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	cpdup:sysutils/cpdup

USES=		pkgconfig tar:xz
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	ghostbsd
GH_PROJECT=	pc-sysinstall
GH_TAGNAME=	59f8ac7ba0c5fb1791737eafd02a33bf95153a42

.include <bsd.port.mk>

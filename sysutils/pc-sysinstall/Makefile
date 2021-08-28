# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pc-sysinstall
PORTVERSION=	2021082800
PORTEPOCH=	1
CATEGORIES=	sysutils

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	TrueOS install backend

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	cpdup:sysutils/cpdup \
		ghostbsd-refind>=0.1:sysutils/ghostbsd-refind

USES=		pkgconfig tar:xz
MAKE_ARGS=	PREFIX=${STAGEDIR}${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	ghostbsd
GH_PROJECT=	pc-sysinstall
GH_TAGNAME=	acf83bcb77d275c8cf7c56fc59d127409d4a4587

.include <bsd.port.mk>

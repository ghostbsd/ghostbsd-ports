# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pc-sysinstall
PORTVERSION=	2021012000
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
GH_TAGNAME=	0a4707dd27832386f4f5d73566048a21c71a4fcb

.include <bsd.port.mk>

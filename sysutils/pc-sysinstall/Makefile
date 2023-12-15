PORTNAME=	pc-sysinstall
PORTVERSION=	2023121500
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
GH_TAGNAME=	e40fe923b6121accdb7ced8b86fbd413685f654a

.include <bsd.port.mk>

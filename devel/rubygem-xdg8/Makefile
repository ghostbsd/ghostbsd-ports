PORTNAME=	xdg
PORTVERSION=	8.10.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	8

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XDG Base Directory Standard Library for Ruby
WWW=		https://alchemists.io/projects/xdg \
		https://github.com/bkuhlmann/xdg

LICENSE=	HIPPOCRATIC
LICENSE_NAME=	Hippocratic License 2.1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.adoc
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

BROKEN_RUBY32=	yes

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.

.include <bsd.port.mk>

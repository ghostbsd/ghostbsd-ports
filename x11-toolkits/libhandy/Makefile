PORTNAME=	libhandy
PORTVERSION=	1.6.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library with GTK widgets for mobile phones
WWW=		https://gitlab.gnome.org/GNOME/libhandy/

LICENSE=	LGPL21

LIB_DEPENDS=	libfribidi.so:converters/fribidi
BUILD_DEPENDS=	/usr/local/lib/libgladeui-2.so:devel/glade
USES=		compiler:c11 gettext gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	cairo gdkpixbuf gtk30 introspection:build

USE_LDCONFIG=	yes
MESON_ARGS=	-Dtests=false
NINJA_ARGS=	-C _build/run glade

.include <bsd.port.mk>

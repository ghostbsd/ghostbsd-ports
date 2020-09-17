# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glib
PORTVERSION=	2.64.3
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/glib/commit/
PATCHFILES+=	5f38ae5ffca3213addc5b279a46d537792d031db.diff:-p1

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Some useful routines of C programming (current stable version)

LICENSE=	LGPL20

USES=		tar:xz
PORTSCOUT=	limitw:1,even

.if !defined(REFERENCE_PORT)

LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libffi.so:devel/libffi

USE_LDCONFIG=	yes
# iconv:wchar_t - our iconv in base doesn't support utf-8 -> wchar_t (boooo)
# (wchar_t is used by glibmm, rawtherapee triggered this)
USES+=		compiler:c11 gettext gnome iconv:wchar_t localbase:ldflags \
		meson pkgconfig python:3.4+ shebangfix
MESON_ARGS=	-Diconv=external

MESON_ARGS+=	-Ddefault_library=both \
		-Dselinux=disabled \
		-Dlibmount=disabled \
		-Dgtk_doc=false \
		-Dxattr=false \
		-Dfam=false \
		-Dinstalled_tests=false

BINARY_ALIAS=	python3=${PYTHON_CMD}
python_OLD_CMD=	"/usr/bin/env @PYTHON@"
SHEBANG_FILES=	gio/gdbus-2.0/codegen/gdbus-codegen.in \
		glib/gtester-report.in \
		gobject/glib-genmarshal.in \
		gobject/glib-mkenums.in

LIBVERSION=	0.6400.3
PLIST_SUB+=	LIBVERSION=${LIBVERSION}
CODEGENDIR=	${PREFIX}/share/glib-2.0/codegen

glib_MAN=	gtester.1 gtester-report.1 glib-gettextize.1
gio_MAN=	gdbus.1 gsettings.1 gio-querymodules.1 gio.1 \
		glib-compile-schemas.1 gapplication.1 \
		glib-compile-resources.1 gresource.1 gdbus-codegen.1
gobject_MAN=	glib-genmarshal.1 glib-mkenums.1 gobject-query.1

OPTIONS_DEFINE=	MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=		docbook-xml>4.1.2:textproc/docbook-xml \
				docbook-xsl>0:textproc/docbook-xsl
MANPAGES_USE=			GNOME=libxslt:build
MANPAGES_MESON_TRUE=		man

.include <bsd.port.pre.mk>

# doesn't build yet
MESON_ARGS+=		-Ddtrace=false

.if ${ARCH} == powerpc64
EXTRA_PATCHES+=	${FILESDIR}/extra-arch-powerpc64
.endif

# -Wl,--no-undefined seems to be causing issues: undefined reference to environ
#  both with lld and newer binutils
#
post-configure:
	@${REINPLACE_CMD} -e 's/-Wl,--no-undefined//g' ${WRKSRC}/_build/build.ninja

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/gio/xdgmime/xdgmime.c
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|g' \
		${WRKSRC}/gio/tests/desktop-app-info.c \
		${WRKSRC}/glib/gcharset.c
	@${REINPLACE_CMD} -e 's|:/usr/bin|:${LOCALBASE}/bin:/usr/bin|' \
		-e 's|/etc/xdg|${LOCALBASE}/etc/xdg|' \
		${WRKSRC}/glib/gspawn.c \
		${WRKSRC}/glib/gutils.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/docs/reference/gio/glib-compile-schemas.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/GConf/gsettings
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/gio/modules
	# generates .py[co] files for installed modules
	# if that's not done, ${PYTHON_SITELIBDIR}/gps will be polluted
	# with these files when module is imported from root user
	@${FIND} ${STAGEDIR}${PREFIX} -name \*.pyc -delete
	(cd ${STAGEDIR}${PREFIX} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${CODEGENDIR} -f ${CODEGENDIR:S;${PREFIX}/;;} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${CODEGENDIR} -f ${CODEGENDIR:S;${PREFIX}/;;})
	# nstall bash completion regardless if bash is present
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_SCRIPT} ${WRKSRC}/gio/completion/* ${STAGEDIR}${PREFIX}/share/bash-completion/completions


.include <bsd.port.post.mk>

.endif

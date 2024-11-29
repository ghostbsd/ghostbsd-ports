PORTNAME=	automount
DISTVERSION=	1.7.9
PORTREVISION=	1
CATEGORIES=	filesystems sysutils

MAINTAINER=	vermaden@interia.pl
COMMENT=	FreeBSD's devd(8) based automount solution
WWW=		https://github.com/vermaden/automount/

LICENSE=	BSD2CLAUSE

CONFLICTS_INSTALL=	devd-mount	# Competing devd rules

PLIST_FILES=	sbin/automount \
		etc/devd/automount_devd.conf \
		etc/devd/automount_devd_localdisks.conf \
		etc/automount.conf.sample

SUB_FILES=	pkg-install
NO_BUILD=	yes

OPTIONS_DEFINE=		NTFS3G EXT4 EXFAT HFS
OPTIONS_DEFAULT=	NTFS3G EXT4 EXFAT HFS
NTFS3G_DESC=		Enable NTFS write support with ntfs-3g over FUSE
NTFS3G_RUN_DEPENDS=	fusefs-ntfs>=0:filesystems/ntfs
EXT4_DESC=		Support EXT2/3/4 filesystem
EXT4_RUN_DEPENDS=	fusefs-lkl>=0:filesystems/lkl
HFS_DESC=		Support macOS HFS filesystem
HFS_RUN_DEPENDS=	fusefs-hfsfuse>=0:filesystems/hfsfuse
EXFAT_DESC=		Support Microsoft exFAT filesystem
EXFAT_RUN_DEPENDS=	fusefs-exfat>=0:filesystems/exfat \
			exfat-utils>=0:filesystems/exfat-utils

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/automount             ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA}   ${WRKSRC}/automount_devd.conf   ${STAGEDIR}${PREFIX}/etc/devd/automount_devd.conf
	${INSTALL_DATA}   ${WRKSRC}/automount_devd_localdisks.conf   ${STAGEDIR}${PREFIX}/etc/devd/automount_devd_localdisks.conf
	${INSTALL_DATA}   ${WRKSRC}/automount.conf        ${STAGEDIR}${PREFIX}/etc/automount.conf.sample

.include <bsd.port.mk>

# $FreeBSD$
#
# Support for OS ports.
#
# Feature:	os
# Usage:	USES=os
# Valid ARGS:	(none), flavors, noflavors, nozfs
#
#	- flavors  : Generates flavors for supported versions.
#	- noflavors: Prevents generation of flavor.
#	- generic  : Default FreeBSD build options
#	- nozfs	   : Build setting WITHOUT_ZFS
#

.if !defined(_INCLUDE_USES_OS_MK)

OS_Include_MAINTAINER=	kmoore@FreeBSD.org

_INCLUDE_USES_OS_MK=	yes

_OS_VALID_ARGS=	flavors generic noflavors nozfs

_OS_UNKNOWN_ARGS=
.for arg in ${os_ARGS}
.  if empty(_OS_VALID_ARGS:M${arg})
_OS_UNKNOWN_ARGS+=	${arg}
.  endif
.endfor
.if !empty(_OS_UNKNOWN_ARGS)
IGNORE=	has unknown USES=os arguments: ${_OS_UNKNOWN_ARGS}
.endif

.  if ${os_ARGS:Mnoflavors} && ${os_ARGS:Mflavors}
os_ARGS:=	${os_ARGS:Nflavors}
.  endif

_ALL_OS_FLAVORS=	generic nozfs

OS_DEFAULT_FLAVOR?=	generic

# Use the "default" os flavor as the first flavor, so that it
# gets to be the default.
_ALL_FLAVORS=	${OS_DEFAULT_FLAVOR} ${_ALL_OS_FLAVORS:N${OS_DEFAULT_FLAVOR}}

# If we want flavors, fill in FLAVORS with the allowed flavors, if some
# cannot be used, or all of them if they all can.
# Then if there is no flavor set, use the first one as the default.
.  if ${os_ARGS:Mflavors}
.    if empty(FLAVORS)
FLAVORS:=	${_ALL_FLAVORS}
.    endif
.    if empty(FLAVOR)
FLAVOR=	${FLAVORS:[1]}
.    endif
.  endif

# This variable is for dependencies lines, so you write:
# ${OS_PKGNAMEPREFIX}foo:os/userland-foo@${OS_FLAVOR}
OS_FLAVOR=	${FLAVOR}

# Set a few PKGNAME(PRE|SUF)FIX to be used in ports.
OS_PKGNAMEPREFIX=	os-${FLAVOR}-
OS_PKGNAMESUFFIX=	-os-${FLAVOR}

.  if ${FLAVOR} == "nozfs"
PORT_OPTIONS:=	${PORT_OPTIONS:NZFS}
.  endif
.  if ${FLAVOR} == "generic"
OS_KERNDIST=	/usr/dist/kernel.txz
OS_KERNDIST_DEBUG=	/usr/dist/kernel-debug.txz
OS_WORLDDIST=	/usr/dist/world.txz
.  else
OS_KERNDIST=	/usr/dist/kernel-${FLAVOR}.txz
OS_KERNDIST_DEBUG=	/usr/dist/kernel-${FLAVOR}-debug.txz
OS_WORLDDIST=	/usr/dist/world-${FLAVOR}.txz
.  endif
.endif

# $FreeBSD$
#
# Support for OS ports.
#
# Feature:	os
# Usage:	USES=os
# Valid ARGS:	(none), flavors, noflavors, generic, minimal, nozfs
#
#	- flavors  : Generates flavors for supported versions.
#	- noflavors: Prevents generation of flavor.
#	- generic  : Default FreeBSD build options
#	- minimal  : Build a stripped down version of FreeBSD world
#	- nozfs	   : Build without base ZFS
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

_ALL_OS_FLAVORS=	generic minimal nozfs

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

# Options for the ZOL flavor
.  if ${FLAVOR} == "nozfs"
PORT_OPTIONS:=	${PORT_OPTIONS:NZFS}
.  endif

# Options for the minimal flavor
.  if ${FLAVOR} == "minimal"
PORT_OPTIONS:=	${PORT_OPTIONS:NBSDINSTALL}
PORT_OPTIONS:=	${PORT_OPTIONS:NFTP}
PORT_OPTIONS:=	${PORT_OPTIONS:NGCOV}
PORT_OPTIONS:=	${PORT_OPTIONS:NGDB}
PORT_OPTIONS:=	${PORT_OPTIONS:NLPR}
PORT_OPTIONS:=	${PORT_OPTIONS:NMAIL}
PORT_OPTIONS:=	${PORT_OPTIONS:NNTP}
PORT_OPTIONS:=	${PORT_OPTIONS:NPC_SYSINSTALL}
PORT_OPTIONS:=	${PORT_OPTIONS:NPPP}
PORT_OPTIONS:=	${PORT_OPTIONS:NPORTSNAP}
PORT_OPTIONS:=	${PORT_OPTIONS:NSENDMAIL}
PORT_OPTIONS:=	${PORT_OPTIONS:NSVNLITE}
PORT_OPTIONS:=	${PORT_OPTIONS:NTELNET}
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

#!/bin/sh
# MAINTAINER: portmgr@FeeeBSD.org
# $FreeBSD$

[ -n "${DEBUG_MK_SCRIPTS}" -o -n "${DEBUG_MK_SCRIPTS_ACTUAL_PACKAGE_DEPENDS}" ] && set -x

if [ -z "${PKG_BIN}" ]; then
	echo "PKG_BIN required in environment." >&2
	exit 1
fi

resolv_symlink() {
	local file tgt
	file=${1}
	if [ ! -L ${file} ] ; then
		echo ${file}
		return
	fi

	tgt=$(readlink ${file})
	case $tgt in
	/*)
		echo $tgt
		return
		;;
	esac

	file=${file%/*}/${tgt}
	absolute_path ${file}
}

absolute_path() {
	local file myifs target
	file=$1

	myifs=${IFS}
	IFS='/'
	set -- ${file}
	IFS=${myifs}
	for el; do
		case $el in
		.) continue ;;
		'') continue ;;
		..) target=${target%/*} ;;
		*) target="${target}/${el}" ;;
		esac
	done
	echo ${target}
}

find_dep() {
	pattern=$1
	case ${pattern} in
	*\>*|*\<*|*=*)
		${PKG_BIN} info -Eg "${pattern}" 2>/dev/null ||
			echo "actual-package-depends: dependency on ${pattern} not registered" >&2
		return
		;;
	/*)
		searchfile=$pattern
		;;
	*)
		searchfile=$(/usr/bin/which ${pattern} 2>/dev/null)
		;;
	esac
	if [ -n "${searchfile}" ]; then
		${PKG_BIN} which -q ${searchfile} || ${PKG_BIN} which -q "$(resolv_symlink ${searchfile} 2>/dev/null)" ||
			echo "actual-package-depends: dependency on ${searchfile} not registered (normal if it belongs to base)" >&2
	fi
}

inject_base_dep() {
	ORIGIN="${1}"
	NAME=$(make -C ${PORTSDIR}/${ORIGIN} -V PKGBASE)
	VERSION=$(make -C ${PORTSDIR}/${ORIGIN} -V PKGVERSION)
	echo "\"${NAME}\": {origin: \"${ORIGIN}\", version: \"$VERSION\"}"
}

for lookup; do
	# Ugly, but currently we cannot install BASE packages into read-only poudriere base
	# This allows us to still inject depends on os/* packages
	case ${lookup} in
		/bin/sh)
			inject_base_dep "os/userland-base"
			continue
			;;
		/usr/lib/debug/bin/sh.debug)
			inject_base_dep "os/userland-debug"
			continue
			;;
		/usr/share/man/man1/sh.1.gz)
			inject_base_dep "os/userland-docs"
			continue
			;;
		/usr/lib32/libc.a)
			inject_base_dep "os/userland-lib32"
			continue
			;;
		/usr/tests/README)
			inject_base_dep "os/userland-tests"
			continue
			;;
		*) ;;
	esac
	${PKG_BIN} query "\"%n\": {origin: \"%o\", version: \"%v\"}" "$(find_dep ${lookup})" || :
done

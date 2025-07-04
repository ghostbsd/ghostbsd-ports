PORTNAME=	systeroid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.5
PORTREVISION=	5
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	More powerful alternative to sysctl(8) with a terminal user interface
WWW=		https://systeroid.cli.rs \
		https://github.com/orhun/systeroid

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	orhun

CARGO_CRATES=	adler2-2.0.0 \
		aho-corasick-1.1.3 \
		allocator-api2-0.2.21 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.6.18 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.6 \
		autocfg-1.4.0 \
		bitflags-1.3.2 \
		bitflags-2.6.0 \
		block-0.1.6 \
		bstr-1.11.0 \
		bumpalo-3.16.0 \
		byteorder-1.5.0 \
		cassowary-0.3.0 \
		castaway-0.2.3 \
		cc-1.2.3 \
		cfg-if-1.0.0 \
		chrono-0.4.39 \
		clipboard-win-3.1.1 \
		colorchoice-1.0.3 \
		compact_str-0.8.0 \
		console-0.15.8 \
		const-random-0.1.18 \
		const-random-macro-0.1.16 \
		copypasta-0.8.2 \
		copypasta-ext-0.4.4 \
		core-foundation-sys-0.8.7 \
		crc32fast-1.4.2 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		crunchy-0.2.2 \
		darling-0.20.10 \
		darling_core-0.20.10 \
		darling_macro-0.20.10 \
		diff-0.1.13 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		dlib-0.5.2 \
		dlv-list-0.5.2 \
		downcast-rs-1.2.1 \
		either-1.13.0 \
		encode_unicode-0.3.6 \
		enum-as-inner-0.6.1 \
		env_filter-0.1.2 \
		env_logger-0.11.5 \
		equivalent-1.0.1 \
		errno-0.3.10 \
		flate2-1.0.35 \
		fnv-1.0.7 \
		foldhash-0.1.3 \
		fxhash-0.2.1 \
		gethostname-0.2.3 \
		getopts-0.2.21 \
		getrandom-0.2.15 \
		globset-0.4.15 \
		globwalk-0.8.1 \
		hashbrown-0.14.5 \
		hashbrown-0.15.2 \
		heck-0.5.0 \
		hermit-abi-0.4.0 \
		home-0.5.9 \
		humantime-2.1.0 \
		iana-time-zone-0.1.61 \
		iana-time-zone-haiku-0.1.2 \
		ident_case-1.0.1 \
		ignore-0.4.23 \
		indoc-2.0.5 \
		insta-1.41.1 \
		instability-0.3.3 \
		is-terminal-0.4.13 \
		is_ci-1.2.0 \
		is_terminal_polyfill-1.70.1 \
		itertools-0.13.0 \
		itoa-1.0.14 \
		js-sys-0.3.76 \
		lazy-bytes-cast-5.0.1 \
		lazy_static-1.5.0 \
		libc-0.2.168 \
		libloading-0.8.6 \
		libredox-0.1.3 \
		linked-hash-map-0.5.6 \
		linux-raw-sys-0.4.14 \
		lock_api-0.4.12 \
		log-0.4.22 \
		lru-0.12.5 \
		malloc_buf-0.0.6 \
		memchr-2.7.4 \
		memmap2-0.5.10 \
		memoffset-0.6.5 \
		miniz_oxide-0.8.0 \
		nix-0.24.3 \
		num-traits-0.2.19 \
		numtoa-0.2.4 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		once_cell-1.20.2 \
		ordered-multimap-0.7.3 \
		owo-colors-4.1.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		parseit-0.1.2 \
		paste-1.0.15 \
		pkg-config-0.3.31 \
		pretty_assertions-1.4.1 \
		proc-macro2-1.0.92 \
		quote-1.0.37 \
		ratatui-0.29.0 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.5.8 \
		redox_termios-0.1.3 \
		redox_users-0.4.6 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rust-ini-0.21.1 \
		rustix-0.38.42 \
		rustversion-1.0.18 \
		ryu-1.0.18 \
		same-file-1.0.6 \
		scoped-tls-1.0.1 \
		scopeguard-1.2.0 \
		serde-1.0.216 \
		serde_derive-1.0.216 \
		serde_json-1.0.133 \
		shlex-1.3.0 \
		similar-2.6.0 \
		smallvec-1.13.2 \
		smithay-client-toolkit-0.16.1 \
		smithay-clipboard-0.6.6 \
		static_assertions-1.1.0 \
		strsim-0.11.1 \
		strum-0.26.3 \
		strum_macros-0.26.4 \
		supports-color-2.1.0 \
		supports-color-3.0.2 \
		syn-2.0.90 \
		sysctl-0.6.0 \
		termion-4.0.3 \
		thiserror-1.0.69 \
		thiserror-impl-1.0.69 \
		tiny-keccak-2.0.2 \
		trim-in-place-0.1.7 \
		tui-logger-0.14.0 \
		unicode-ident-1.0.14 \
		unicode-segmentation-1.12.0 \
		unicode-truncate-1.1.0 \
		unicode-width-0.1.14 \
		unicode-width-0.2.0 \
		utf8parse-0.2.2 \
		walkdir-2.5.0 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.99 \
		wasm-bindgen-backend-0.2.99 \
		wasm-bindgen-macro-0.2.99 \
		wasm-bindgen-macro-support-0.2.99 \
		wasm-bindgen-shared-0.2.99 \
		wayland-client-0.29.5 \
		wayland-commons-0.29.5 \
		wayland-cursor-0.29.5 \
		wayland-protocols-0.29.5 \
		wayland-scanner-0.29.5 \
		wayland-sys-0.29.5 \
		which-4.4.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.9 \
		winapi-wsapoll-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-core-0.52.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		x11-clipboard-0.7.1 \
		x11rb-0.10.1 \
		x11rb-protocol-0.10.0 \
		xcursor-0.3.8 \
		xml-rs-0.8.24 \
		yansi-1.0.1

PROGS=		${PORTNAME} \
		${PORTNAME}-tui

PLIST_FILES=	${PROGS:S/^/bin\//}

do-install:
	# binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
.for p in ${PROGS}
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${p} \
		${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>

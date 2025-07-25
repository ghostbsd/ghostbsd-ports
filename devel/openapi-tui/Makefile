PORTNAME=	openapi-tui
DISTVERSION=	0.10.2
CATEGORIES=	devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI to list, browse and run APIs defined with OpenAPI spec
WWW=		https://github.com/zaghaghi/openapi-tui

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libonig.so:devel/oniguruma

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	zaghaghi

CARGO_CRATES=	addr2line-0.21.0 \
		adler-1.0.2 \
		adler2-2.0.0 \
		aho-corasick-1.1.3 \
		allocator-api2-0.2.21 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.6.18 \
		anstyle-1.0.10 \
		anstyle-parse-0.2.6 \
		anstyle-query-1.1.2 \
		anstyle-wincon-3.0.7 \
		anyhow-1.0.97 \
		arraydeque-0.5.1 \
		async-trait-0.1.87 \
		atomic-waker-1.1.2 \
		autocfg-1.4.0 \
		backtrace-0.3.71 \
		base64-0.21.7 \
		base64-0.22.1 \
		better-panic-0.3.0 \
		bincode-1.3.3 \
		bitflags-1.3.2 \
		bitflags-2.9.0 \
		block-buffer-0.10.4 \
		bumpalo-3.17.0 \
		bytes-1.10.1 \
		camino-1.1.9 \
		cargo-platform-0.1.9 \
		cargo_metadata-0.19.2 \
		cassowary-0.3.0 \
		castaway-0.2.3 \
		cc-1.2.16 \
		cfg-if-1.0.0 \
		chrono-0.4.40 \
		clap-4.5.31 \
		clap_builder-4.5.31 \
		clap_derive-4.5.28 \
		clap_lex-0.7.4 \
		color-eyre-0.6.3 \
		color-spantrace-0.2.1 \
		colorchoice-1.0.3 \
		compact_str-0.8.1 \
		config-0.15.9 \
		console-0.15.11 \
		const-random-0.1.18 \
		const-random-macro-0.1.16 \
		convert_case-0.4.0 \
		convert_case-0.6.0 \
		core-foundation-0.9.4 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.2.17 \
		crc32fast-1.4.2 \
		crossterm-0.28.1 \
		crossterm_winapi-0.9.1 \
		crunchy-0.2.3 \
		crypto-common-0.1.6 \
		custom_error-1.9.2 \
		darling-0.20.10 \
		darling_core-0.20.10 \
		darling_macro-0.20.10 \
		deranged-0.3.11 \
		derive_builder-0.20.2 \
		derive_builder_core-0.20.2 \
		derive_builder_macro-0.20.2 \
		derive_deref-1.1.1 \
		derive_more-0.99.19 \
		diff-0.1.13 \
		digest-0.10.7 \
		directories-6.0.0 \
		dirs-sys-0.5.0 \
		displaydoc-0.2.5 \
		dlv-list-0.5.2 \
		either-1.15.0 \
		encode_unicode-1.0.0 \
		encoding_rs-0.8.35 \
		equivalent-1.0.2 \
		errno-0.3.10 \
		eyre-0.6.12 \
		fastrand-2.3.0 \
		flate2-1.1.0 \
		fnv-1.0.7 \
		foldhash-0.1.4 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		form_urlencoded-1.2.1 \
		futures-0.3.31 \
		futures-channel-0.3.31 \
		futures-core-0.3.31 \
		futures-executor-0.3.31 \
		futures-io-0.3.31 \
		futures-macro-0.3.31 \
		futures-sink-0.3.31 \
		futures-task-0.3.31 \
		futures-util-0.3.31 \
		generic-array-0.14.7 \
		getrandom-0.2.15 \
		getrandom-0.3.1 \
		gimli-0.28.1 \
		git2-0.20.0 \
		h2-0.4.8 \
		hashbrown-0.12.3 \
		hashbrown-0.14.5 \
		hashbrown-0.15.2 \
		hashlink-0.10.0 \
		heck-0.5.0 \
		hex-0.4.3 \
		http-1.2.0 \
		http-body-1.0.1 \
		http-body-util-0.1.2 \
		httparse-1.10.1 \
		human-panic-2.0.2 \
		humansize-2.1.3 \
		hyper-1.6.0 \
		hyper-rustls-0.27.5 \
		hyper-tls-0.6.0 \
		hyper-util-0.1.10 \
		iana-time-zone-0.1.61 \
		iana-time-zone-haiku-0.1.2 \
		icu_collections-1.5.0 \
		icu_locid-1.5.0 \
		icu_locid_transform-1.5.0 \
		icu_locid_transform_data-1.5.0 \
		icu_normalizer-1.5.0 \
		icu_normalizer_data-1.5.0 \
		icu_properties-1.5.1 \
		icu_properties_data-1.5.0 \
		icu_provider-1.5.0 \
		icu_provider_macros-1.5.0 \
		ident_case-1.0.1 \
		idna-1.0.3 \
		idna_adapter-1.2.0 \
		indenter-0.3.3 \
		indexmap-1.9.3 \
		indexmap-2.7.1 \
		indoc-2.0.6 \
		instability-0.3.7 \
		ipnet-2.11.0 \
		is_terminal_polyfill-1.70.1 \
		itertools-0.13.0 \
		itoa-1.0.15 \
		jobserver-0.1.32 \
		js-sys-0.3.77 \
		json5-0.4.1 \
		lazy_static-1.5.0 \
		libc-0.2.170 \
		libgit2-sys-0.18.0+1.9.0 \
		libm-0.2.11 \
		libredox-0.1.3 \
		libz-sys-1.1.21 \
		linked-hash-map-0.5.6 \
		linux-raw-sys-0.4.15 \
		linux-raw-sys-0.9.2 \
		litemap-0.7.5 \
		lock_api-0.4.12 \
		log-0.4.26 \
		lru-0.12.5 \
		matchers-0.1.0 \
		memchr-2.7.4 \
		mime-0.3.17 \
		miniz_oxide-0.7.4 \
		miniz_oxide-0.8.5 \
		mio-1.0.3 \
		native-tls-0.2.14 \
		nu-ansi-term-0.46.0 \
		num-conv-0.1.0 \
		num-traits-0.2.19 \
		num_threads-0.1.7 \
		object-0.32.2 \
		once_cell-1.20.3 \
		onig-6.4.0 \
		onig_sys-69.8.1 \
		openapi-31-0.4.0 \
		openssl-0.10.71 \
		openssl-macros-0.1.1 \
		openssl-probe-0.1.6 \
		openssl-src-300.4.2+3.4.1 \
		openssl-sys-0.9.106 \
		option-ext-0.2.0 \
		ordered-multimap-0.7.3 \
		os_info-3.10.0 \
		overload-0.1.1 \
		owo-colors-3.5.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		paste-1.0.15 \
		pathdiff-0.2.3 \
		percent-encoding-2.3.1 \
		pest-2.7.15 \
		pest_derive-2.7.15 \
		pest_generator-2.7.15 \
		pest_meta-2.7.15 \
		pin-project-lite-0.2.16 \
		pin-utils-0.1.0 \
		pkg-config-0.3.32 \
		plist-1.7.0 \
		powerfmt-0.2.0 \
		pretty_assertions-1.4.1 \
		proc-macro2-1.0.94 \
		quick-xml-0.32.0 \
		quote-1.0.39 \
		ratatui-0.29.0 \
		redox_syscall-0.5.10 \
		redox_users-0.5.0 \
		regex-1.11.1 \
		regex-automata-0.1.10 \
		regex-automata-0.4.9 \
		regex-syntax-0.6.29 \
		regex-syntax-0.8.5 \
		reqwest-0.12.12 \
		ring-0.17.13 \
		ron-0.8.1 \
		rust-ini-0.21.1 \
		rustc-demangle-0.1.24 \
		rustc_version-0.4.1 \
		rustix-0.38.44 \
		rustix-1.0.0 \
		rustls-0.23.23 \
		rustls-pemfile-2.2.0 \
		rustls-pki-types-1.11.0 \
		rustls-webpki-0.102.8 \
		rustversion-1.0.20 \
		ryu-1.0.20 \
		same-file-1.0.6 \
		schannel-0.1.27 \
		scopeguard-1.2.0 \
		security-framework-2.11.1 \
		security-framework-sys-2.14.0 \
		semver-1.0.26 \
		serde-1.0.218 \
		serde_derive-1.0.218 \
		serde_json-1.0.140 \
		serde_spanned-0.6.8 \
		serde_urlencoded-0.7.1 \
		serde_with-3.12.0 \
		serde_with_macros-3.12.0 \
		serde_yaml-0.9.34+deprecated \
		sha2-0.10.8 \
		sharded-slab-0.1.7 \
		shlex-1.3.0 \
		signal-hook-0.3.17 \
		signal-hook-mio-0.2.4 \
		signal-hook-registry-1.4.2 \
		slab-0.4.9 \
		smallvec-1.14.0 \
		socket2-0.5.8 \
		stable_deref_trait-1.2.0 \
		static_assertions-1.1.0 \
		strip-ansi-escapes-0.2.1 \
		strsim-0.11.1 \
		strum-0.26.3 \
		strum-0.27.1 \
		strum_macros-0.26.4 \
		strum_macros-0.27.1 \
		subtle-2.6.1 \
		syn-1.0.109 \
		syn-2.0.99 \
		sync_wrapper-1.0.2 \
		synstructure-0.13.1 \
		syntect-5.2.0 \
		syntect-tui-3.0.5 \
		system-configuration-0.6.1 \
		system-configuration-sys-0.6.0 \
		tempfile-3.18.0 \
		terminal_size-0.4.1 \
		thiserror-1.0.69 \
		thiserror-2.0.12 \
		thiserror-impl-1.0.69 \
		thiserror-impl-2.0.12 \
		thread_local-1.1.8 \
		time-0.3.39 \
		time-core-0.1.3 \
		time-macros-0.2.20 \
		tiny-keccak-2.0.2 \
		tinystr-0.7.6 \
		tokio-1.43.0 \
		tokio-macros-2.5.0 \
		tokio-native-tls-0.3.1 \
		tokio-rustls-0.26.2 \
		tokio-util-0.7.13 \
		toml-0.8.20 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.24 \
		tower-0.5.2 \
		tower-layer-0.3.3 \
		tower-service-0.3.3 \
		tracing-0.1.41 \
		tracing-attributes-0.1.28 \
		tracing-core-0.1.33 \
		tracing-error-0.2.1 \
		tracing-log-0.2.0 \
		tracing-subscriber-0.3.19 \
		trim-in-place-0.1.7 \
		try-lock-0.2.5 \
		tui-input-0.11.1 \
		tui-textarea-0.7.0 \
		typenum-1.18.0 \
		ucd-trie-0.1.7 \
		unicase-2.8.1 \
		unicode-ident-1.0.18 \
		unicode-segmentation-1.12.0 \
		unicode-truncate-1.1.0 \
		unicode-width-0.1.14 \
		unicode-width-0.2.0 \
		unsafe-libyaml-0.2.11 \
		untrusted-0.9.0 \
		url-2.5.4 \
		utf16_iter-1.0.5 \
		utf8_iter-1.0.4 \
		utf8parse-0.2.2 \
		uuid-1.15.1 \
		valuable-0.1.1 \
		vcpkg-0.2.15 \
		vergen-9.0.4 \
		vergen-git2-1.0.5 \
		vergen-lib-0.1.6 \
		version_check-0.9.5 \
		vte-0.14.1 \
		walkdir-2.5.0 \
		want-0.3.1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasi-0.13.3+wasi-0.2.2 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-futures-0.4.50 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		web-sys-0.3.77 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.9 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-core-0.52.0 \
		windows-link-0.1.0 \
		windows-registry-0.2.0 \
		windows-result-0.2.0 \
		windows-strings-0.1.0 \
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
		winnow-0.7.3 \
		wit-bindgen-rt-0.33.0 \
		write16-1.0.0 \
		writeable-0.5.5 \
		yaml-rust-0.4.5 \
		yaml-rust2-0.10.0 \
		yansi-1.0.1 \
		yoke-0.7.5 \
		yoke-derive-0.7.5 \
		zerofrom-0.1.6 \
		zerofrom-derive-0.1.6 \
		zeroize-1.8.1 \
		zerovec-0.10.4 \
		zerovec-derive-0.10.3
CARGO_ENV=	OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>

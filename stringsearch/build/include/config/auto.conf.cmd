deps_config := \
	/usr/src/apps/stringsearch/Config.uk \
	/usr/src/unikraft/unikraft/lib/Config.uk \
	/usr/src/unikraft/unikraft/lib//vfscore/Config.uk \
	/usr/src/unikraft/unikraft/lib//uktimeconv/Config.uk \
	/usr/src/unikraft/unikraft/lib//uktime/Config.uk \
	/usr/src/unikraft/unikraft/lib//uktest/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukswrand/Config.uk \
	/usr/src/unikraft/unikraft/lib//uksp/Config.uk \
	/usr/src/unikraft/unikraft/lib//uksignal/Config.uk \
	/usr/src/unikraft/unikraft/lib//uksglist/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukschedcoop/Config.uk \
	/usr/src/unikraft/unikraft/lib//uksched/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukrust/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukring/Config.uk \
	/usr/src/unikraft/unikraft/lib//uknetdev/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukmpi/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukmmap/Config.uk \
	/usr/src/unikraft/unikraft/lib//uklock/Config.uk \
	/usr/src/unikraft/unikraft/lib//uklibparam/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukfallocbuddy/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukfalloc/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukdebug/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukcpio/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukbus/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukboot/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukblkdev/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukargparse/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukallocregion/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukallocpool/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukallocbbuddy/Config.uk \
	/usr/src/unikraft/unikraft/lib//ukalloc/Config.uk \
	/usr/src/unikraft/unikraft/lib//uk9p/Config.uk \
	/usr/src/unikraft/unikraft/lib//ubsan/Config.uk \
	/usr/src/unikraft/unikraft/lib//syscall_shim/Config.uk \
	/usr/src/unikraft/unikraft/lib//ramfs/Config.uk \
	/usr/src/unikraft/unikraft/lib//posix-user/Config.uk \
	/usr/src/unikraft/unikraft/lib//posix-sysinfo/Config.uk \
	/usr/src/unikraft/unikraft/lib//posix-process/Config.uk \
	/usr/src/unikraft/unikraft/lib//posix-libdl/Config.uk \
	/usr/src/unikraft/unikraft/lib//nolibc/Config.uk \
	/usr/src/unikraft/unikraft/lib//isrlib/Config.uk \
	/usr/src/unikraft/unikraft/lib//fdt/Config.uk \
	/usr/src/unikraft/unikraft/lib//devfs/Config.uk \
	/usr/src/unikraft/unikraft/lib//9pfs/Config.uk \
	/usr/src/apps/stringsearch/build/kconfig/libs.uk \
	/usr/src/unikraft/unikraft/plat/Config.uk \
	/usr/src/unikraft/unikraft/plat//xen/Config.uk \
	/usr/src/unikraft/unikraft/plat//linuxu/Config.uk \
	/usr/src/unikraft/unikraft/plat//kvm/Config.uk \
	/usr/src/apps/stringsearch/build/kconfig/plat.uk \
	/usr/src/unikraft/unikraft/arch/arm/arm64/Config.uk \
	/usr/src/unikraft/unikraft/arch/arm/arm/Config.uk \
	/usr/src/unikraft/unikraft/arch/x86/x86_64/Config.uk \
	/usr/src/unikraft/unikraft/arch/Config.uk \
	/usr/src/unikraft/unikraft/Config.uk

/usr/src/apps/stringsearch/build/kconfig/auto.conf: \
	$(deps_config)

ifneq "$(UK_FULLVERSION)" "0.8.0~507b1e9"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(UK_CODENAME)" "Enceladus"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(UK_ARCH)" "arm64"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(UK_BASE)" "/usr/src/unikraft/unikraft"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(UK_APP)" "/usr/src/apps/stringsearch"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(UK_NAME)" "helloworld"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(CC)" "aarch64-linux-gnu-gcc"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(KCONFIG_PLAT_DIR)" "/usr/src/unikraft/unikraft/plat//kvm /usr/src/unikraft/unikraft/plat//linuxu /usr/src/unikraft/unikraft/plat//xen  /usr/src/unikraft/unikraft/plat/"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(KCONFIG_PLAT_IN)" "/usr/src/apps/stringsearch/build/kconfig/plat.uk"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(KCONFIG_LIB_DIR)" "/usr/src/unikraft/unikraft/lib//9pfs /usr/src/unikraft/unikraft/lib//devfs /usr/src/unikraft/unikraft/lib//fdt /usr/src/unikraft/unikraft/lib//isrlib /usr/src/unikraft/unikraft/lib//nolibc /usr/src/unikraft/unikraft/lib//posix-libdl /usr/src/unikraft/unikraft/lib//posix-process /usr/src/unikraft/unikraft/lib//posix-sysinfo /usr/src/unikraft/unikraft/lib//posix-user /usr/src/unikraft/unikraft/lib//ramfs /usr/src/unikraft/unikraft/lib//syscall_shim /usr/src/unikraft/unikraft/lib//ubsan /usr/src/unikraft/unikraft/lib//uk9p /usr/src/unikraft/unikraft/lib//ukalloc /usr/src/unikraft/unikraft/lib//ukallocbbuddy /usr/src/unikraft/unikraft/lib//ukallocpool /usr/src/unikraft/unikraft/lib//ukallocregion /usr/src/unikraft/unikraft/lib//ukargparse /usr/src/unikraft/unikraft/lib//ukblkdev /usr/src/unikraft/unikraft/lib//ukboot /usr/src/unikraft/unikraft/lib//ukbus /usr/src/unikraft/unikraft/lib//ukcpio /usr/src/unikraft/unikraft/lib//ukdebug /usr/src/unikraft/unikraft/lib//ukfalloc /usr/src/unikraft/unikraft/lib//ukfallocbuddy /usr/src/unikraft/unikraft/lib//uklibparam /usr/src/unikraft/unikraft/lib//uklock /usr/src/unikraft/unikraft/lib//ukmmap /usr/src/unikraft/unikraft/lib//ukmpi /usr/src/unikraft/unikraft/lib//uknetdev /usr/src/unikraft/unikraft/lib//ukring /usr/src/unikraft/unikraft/lib//ukrust /usr/src/unikraft/unikraft/lib//uksched /usr/src/unikraft/unikraft/lib//ukschedcoop /usr/src/unikraft/unikraft/lib//uksglist /usr/src/unikraft/unikraft/lib//uksignal /usr/src/unikraft/unikraft/lib//uksp /usr/src/unikraft/unikraft/lib//ukswrand /usr/src/unikraft/unikraft/lib//uktest /usr/src/unikraft/unikraft/lib//uktime /usr/src/unikraft/unikraft/lib//uktimeconv /usr/src/unikraft/unikraft/lib//vfscore /usr/src/unikraft/unikraft/lib "
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(KCONFIG_LIB_IN)" "/usr/src/apps/stringsearch/build/kconfig/libs.uk"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif
ifneq "$(KCONFIG_APP_DIR)" "/usr/src/apps/stringsearch"
/usr/src/apps/stringsearch/build/kconfig/auto.conf: FORCE
endif

$(deps_config): ;

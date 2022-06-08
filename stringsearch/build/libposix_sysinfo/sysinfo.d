cmd_/usr/src/apps/stringsearch/build/libposix_sysinfo/sysinfo.o := aarch64-linux-gnu-gcc -nostdlib -U __linux__ -U __FreeBSD__ -U __sun__ -fno-stack-protector -Wall -Wextra -D __Unikraft__ -DUK_CODENAME="Enceladus" -DUK_VERSION=0.8 -DUK_FULLVERSION=0.8.0~507b1e9 -fno-tree-sra -fno-split-stack -nostdinc -O2 -fno-omit-frame-pointer -fno-PIC   -I/usr/src/apps/stringsearch/build/include -I/usr/src/unikraft/unikraft/arch/arm/arm64/include -I/usr/src/unikraft/unikraft/include -I/usr/src/unikraft/unikraft/lib/devfs/include -I/usr/src/unikraft/unikraft/lib/fdt/include -I/usr/src/unikraft/unikraft/lib/nolibc/include -I/usr/src/unikraft/unikraft/lib/nolibc/arch/arm64 -I/usr/src/unikraft/unikraft/lib/nolibc/musl-imported/include -I/usr/src/unikraft/unikraft/lib/nolibc/musl-imported/arch/generic -I/usr/src/unikraft/unikraft/lib/posix-libdl/include -I/usr/src/unikraft/unikraft/lib/posix-process/include -I/usr/src/unikraft/unikraft/lib/posix-process/musl-imported/include -I/usr/src/unikraft/unikraft/lib/posix-process/musl-imported/arch/generic -I/usr/src/unikraft/unikraft/lib/posix-sysinfo/include -I/usr/src/unikraft/unikraft/lib/posix-user/include -I/usr/src/unikraft/unikraft/lib/posix-user/musl-imported/include -I/usr/src/unikraft/unikraft/lib/syscall_shim/include -I/usr/src/unikraft/unikraft/lib/ukalloc/include -I/usr/src/unikraft/unikraft/lib/ukallocbbuddy/include -I/usr/src/unikraft/unikraft/lib/ukargparse/include -I/usr/src/unikraft/unikraft/lib/ukboot/include -I/usr/src/unikraft/unikraft/lib/ukbus/include -I/usr/src/unikraft/unikraft/lib/ukdebug/include -I/usr/src/unikraft/unikraft/lib/uklibparam/include -I/usr/src/unikraft/unikraft/lib/uksglist/include -I/usr/src/unikraft/unikraft/lib/uksp/include -I/usr/src/unikraft/unikraft/lib/uktime/include -I/usr/src/unikraft/unikraft/lib/uktime/musl-imported/include -I/usr/src/unikraft/unikraft/lib/uktimeconv/include -I/usr/src/unikraft/unikraft/lib/vfscore/include     -D__ARM_64__ -mgeneral-regs-only -mfix-cortex-a53-835769 -mfix-cortex-a53-843419 -DCC_VERSION=9.2 -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-sprintf -fno-builtin-snprintf -fno-builtin-vprintf -fno-builtin-vfprintf -fno-builtin-vsprintf -fno-builtin-vsnprintf -fno-builtin-scanf -fno-builtin-fscanf -fno-builtin-sscanf -fno-builtin-vscanf -fno-builtin-vfscanf -fno-builtin-vsscanf -DCONFIG_UK_NETDEV_SCRATCH_SIZE=0       -g3 -D__LIBNAME__=libposix_sysinfo -D__BASENAME__=sysinfo.c -c /usr/src/unikraft/unikraft/lib/posix-sysinfo/sysinfo.c -o /usr/src/apps/stringsearch/build/libposix_sysinfo/sysinfo.o -Wp,-MD,/usr/src/apps/stringsearch/build/libposix_sysinfo/.sysinfo.o.d

source_/usr/src/apps/stringsearch/build/libposix_sysinfo/sysinfo.o := /usr/src/unikraft/unikraft/lib/posix-sysinfo/sysinfo.c

deps_/usr/src/apps/stringsearch/build/libposix_sysinfo/sysinfo.o := \
    $(wildcard include/config/libvfscore.h) \
    $(wildcard include/config/arch/x86/64.h) \
    $(wildcard include/config/arch/arm/64.h) \
    $(wildcard include/config/arch/arm/32.h) \
    $(wildcard include/config/libukalloc.h) \
  /usr/src/unikraft/unikraft/lib/nolibc/include/stddef.h \
  /usr/src/unikraft/unikraft/include/uk/arch/types.h \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/intsizes.h \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/types.h \
  /usr/src/unikraft/unikraft/lib/nolibc/include/nolibc-internal/shareddefs.h \
    $(wildcard include/config/have/time.h) \
  /usr/src/unikraft/unikraft/include/uk/config.h \
  /usr/src/unikraft/unikraft/lib/uktime/include/uk/time_types.h \
  /usr/src/unikraft/unikraft/include/uk/arch/limits.h \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/limits.h \
    $(wildcard include/config/stack/size/page/order.h) \
  /usr/src/unikraft/unikraft/lib/nolibc/include/unistd.h \
    $(wildcard include/config/libposix/sysinfo.h) \
    $(wildcard include/config/libposix/process.h) \
    $(wildcard include/config/libuksignal.h) \
  /usr/src/unikraft/unikraft/lib/nolibc/include/errno.h \
  /usr/src/unikraft/unikraft/lib/nolibc/include/string.h \
  /usr/src/unikraft/unikraft/lib/posix-sysinfo/include/sys/utsname.h \
  /usr/src/unikraft/unikraft/include/uk/essentials.h \
    $(wildcard include/config/libnewlibc.h) \
    $(wildcard include/config/have/sched.h) \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/compiler.h \
    $(wildcard include/config/arm64/feat/pauth.h) \
  /usr/src/unikraft/unikraft/lib/posix-sysinfo/include/sys/sysinfo.h \
  /usr/src/unikraft/unikraft/lib/syscall_shim/include/uk/syscall.h \
    $(wildcard include/config/libsyscall/shim.h) \
    $(wildcard include/config/libsyscall/shim/nowrapper.h) \
    $(wildcard include/config/libsyscall/shim/debug.h) \
    $(wildcard include/config/libukdebug/printd.h) \
  /usr/src/unikraft/unikraft/include/uk/errptr.h \
  /usr/src/unikraft/unikraft/lib/nolibc/include/stdarg.h \
  /usr/src/unikraft/unikraft/lib/ukdebug/include/uk/print.h \
    $(wildcard include/config/libukdebug/printk/crit.h) \
    $(wildcard include/config/libukdebug/printk/err.h) \
    $(wildcard include/config/libukdebug/printk/warn.h) \
    $(wildcard include/config/libukdebug/printk/info.h) \
    $(wildcard include/config/libukdebug/printk.h) \
  /usr/src/unikraft/unikraft/include/uk/arch/lcpu.h \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/lcpu.h \
  /usr/src/unikraft/unikraft/include/uk/asm.h \
  /usr/src/unikraft/unikraft/lib/nolibc/include/stdint.h \

/usr/src/apps/stringsearch/build/libposix_sysinfo/sysinfo.o: $(deps_/usr/src/apps/stringsearch/build/libposix_sysinfo/sysinfo.o)

$(deps_/usr/src/apps/stringsearch/build/libposix_sysinfo/sysinfo.o):

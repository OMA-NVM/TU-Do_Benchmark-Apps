cmd_/usr/src/apps/helloworld/build/libkvmgic/gic-common.o := aarch64-linux-gnu-gcc -nostdlib -U __linux__ -U __FreeBSD__ -U __sun__ -fno-stack-protector -Wall -Wextra -D __Unikraft__ -DUK_CODENAME="Enceladus" -DUK_VERSION=0.8 -DUK_FULLVERSION=0.8.0~507b1e9 -fno-tree-sra -fno-split-stack -nostdinc -O2 -fno-omit-frame-pointer -fno-PIC   -I/usr/src/apps/helloworld/build/include -I/usr/src/unikraft/unikraft/arch/arm/arm64/include -I/usr/src/unikraft/unikraft/include -I/usr/src/unikraft/unikraft/lib/devfs/include -I/usr/src/unikraft/unikraft/lib/fdt/include -I/usr/src/unikraft/unikraft/lib/nolibc/include -I/usr/src/unikraft/unikraft/lib/nolibc/arch/arm64 -I/usr/src/unikraft/unikraft/lib/nolibc/musl-imported/include -I/usr/src/unikraft/unikraft/lib/nolibc/musl-imported/arch/generic -I/usr/src/unikraft/unikraft/lib/posix-user/include -I/usr/src/unikraft/unikraft/lib/posix-user/musl-imported/include -I/usr/src/unikraft/unikraft/lib/syscall_shim/include -I/usr/src/unikraft/unikraft/lib/ukalloc/include -I/usr/src/unikraft/unikraft/lib/ukallocbbuddy/include -I/usr/src/unikraft/unikraft/lib/ukargparse/include -I/usr/src/unikraft/unikraft/lib/ukboot/include -I/usr/src/unikraft/unikraft/lib/ukbus/include -I/usr/src/unikraft/unikraft/lib/ukdebug/include -I/usr/src/unikraft/unikraft/lib/uklibparam/include -I/usr/src/unikraft/unikraft/lib/uksglist/include -I/usr/src/unikraft/unikraft/lib/uksp/include -I/usr/src/unikraft/unikraft/lib/uktime/include -I/usr/src/unikraft/unikraft/lib/uktime/musl-imported/include -I/usr/src/unikraft/unikraft/lib/uktimeconv/include -I/usr/src/unikraft/unikraft/lib/vfscore/include  -I/usr/src/unikraft/unikraft/plat/kvm/include -I/usr/src/unikraft/unikraft/plat/common/include -I/usr/src/unikraft/unikraft/plat/drivers/include   -D__ARM_64__ -mgeneral-regs-only -mfix-cortex-a53-835769 -mfix-cortex-a53-843419 -DCC_VERSION=9.2 -fno-builtin-printf -fno-builtin-fprintf -fno-builtin-sprintf -fno-builtin-snprintf -fno-builtin-vprintf -fno-builtin-vfprintf -fno-builtin-vsprintf -fno-builtin-vsnprintf -fno-builtin-scanf -fno-builtin-fscanf -fno-builtin-sscanf -fno-builtin-vscanf -fno-builtin-vfscanf -fno-builtin-vsscanf -DCONFIG_UK_NETDEV_SCRATCH_SIZE=0       -g3 -D__LIBNAME__=libkvmgic -D__BASENAME__=gic-common.c -c /usr/src/unikraft/unikraft/plat/drivers/gic/gic-common.c -o /usr/src/apps/helloworld/build/libkvmgic/gic-common.o -Wp,-MD,/usr/src/apps/helloworld/build/libkvmgic/.gic-common.o.d

source_/usr/src/apps/helloworld/build/libkvmgic/gic-common.o := /usr/src/unikraft/unikraft/plat/drivers/gic/gic-common.c

deps_/usr/src/apps/helloworld/build/libkvmgic/gic-common.o := \
    $(wildcard include/config/libgicv2.h) \
    $(wildcard include/config/libgicv3.h) \
  /usr/src/unikraft/unikraft/lib/nolibc/include/string.h \
  /usr/src/unikraft/unikraft/lib/nolibc/include/nolibc-internal/shareddefs.h \
    $(wildcard include/config/have/time.h) \
  /usr/src/unikraft/unikraft/include/uk/config.h \
  /usr/src/unikraft/unikraft/include/uk/arch/types.h \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/intsizes.h \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/types.h \
  /usr/src/unikraft/unikraft/lib/uktime/include/uk/time_types.h \
  /usr/src/unikraft/unikraft/lib/nolibc/include/errno.h \
  /usr/src/unikraft/unikraft/lib/ukdebug/include/uk/assert.h \
    $(wildcard include/config/libukdebug/enable/assert.h) \
  /usr/src/unikraft/unikraft/include/uk/plat/bootstrap.h \
  /usr/src/unikraft/unikraft/include/uk/essentials.h \
    $(wildcard include/config/libnewlibc.h) \
    $(wildcard include/config/have/sched.h) \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/compiler.h \
    $(wildcard include/config/arm64/feat/pauth.h) \
  /usr/src/unikraft/unikraft/include/uk/arch/lcpu.h \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/lcpu.h \
  /usr/src/unikraft/unikraft/include/uk/asm.h \
  /usr/src/unikraft/unikraft/lib/nolibc/include/stdint.h \
  /usr/src/unikraft/unikraft/include/uk/arch/limits.h \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/limits.h \
    $(wildcard include/config/stack/size/page/order.h) \
  /usr/src/unikraft/unikraft/lib/ukdebug/include/uk/print.h \
    $(wildcard include/config/libukdebug/printd.h) \
    $(wildcard include/config/libukdebug/printk/crit.h) \
    $(wildcard include/config/libukdebug/printk/err.h) \
    $(wildcard include/config/libukdebug/printk/warn.h) \
    $(wildcard include/config/libukdebug/printk/info.h) \
    $(wildcard include/config/libukdebug/printk.h) \
  /usr/src/unikraft/unikraft/lib/nolibc/include/stdarg.h \
  /usr/src/unikraft/unikraft/plat/drivers/include/gic/gic.h \
    $(wildcard include/config/have/smp.h) \
  /usr/src/unikraft/unikraft/include/uk/plat/spinlock.h \
  /usr/src/unikraft/unikraft/include/uk/arch/spinlock.h \
  /usr/src/unikraft/unikraft/include/uk/plat/lcpu.h \
  /usr/src/unikraft/unikraft/include/uk/arch/time.h \
  /usr/src/unikraft/unikraft/plat/common/include/uk/plat/common/irq.h \
  /usr/src/unikraft/unikraft/include/uk/plat/irq.h \
  /usr/src/unikraft/unikraft/plat/common/include/arm/irq.h \
  /usr/src/unikraft/unikraft/plat/common/include/arm/arm64/irq.h \
  /usr/src/unikraft/unikraft/plat/drivers/include/gic/gic-v2.h \
  /usr/src/unikraft/unikraft/plat/drivers/include/gic/gic-v3.h \

/usr/src/apps/helloworld/build/libkvmgic/gic-common.o: $(deps_/usr/src/apps/helloworld/build/libkvmgic/gic-common.o)

$(deps_/usr/src/apps/helloworld/build/libkvmgic/gic-common.o):

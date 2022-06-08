cmd_/usr/src/apps/stringsearch/build/libkvmplat/psci_arm64.common.o := aarch64-linux-gnu-gcc -nostdlib -U __linux__ -U __FreeBSD__ -U __sun__ -fno-stack-protector -Wall -Wextra -D __Unikraft__ -DUK_CODENAME="Enceladus" -DUK_VERSION=0.8 -DUK_FULLVERSION=0.8.0~507b1e9 -fno-tree-sra -fno-split-stack -nostdinc -O2 -fno-omit-frame-pointer -fno-PIC   -I/usr/src/apps/stringsearch/build/include -I/usr/src/unikraft/unikraft/arch/arm/arm64/include -I/usr/src/unikraft/unikraft/include -I/usr/src/unikraft/unikraft/lib/uklibparam/include  -I/usr/src/unikraft/unikraft/plat/kvm/include -I/usr/src/unikraft/unikraft/plat/common/include   -D__ARM_64__ -mgeneral-regs-only -mfix-cortex-a53-835769 -mfix-cortex-a53-843419 -DCC_VERSION=9.2 -D__ASSEMBLY__   -DKVMPLAT     -g3 -D__LIBNAME__=libkvmplat -D__BASENAME__=psci_arm64.S -D__VARIANT__=common -c /usr/src/unikraft/unikraft/plat/common/arm/psci_arm64.S -o /usr/src/apps/stringsearch/build/libkvmplat/psci_arm64.common.o -Wp,-MD,/usr/src/apps/stringsearch/build/libkvmplat/.psci_arm64.common.o.d

source_/usr/src/apps/stringsearch/build/libkvmplat/psci_arm64.common.o := /usr/src/unikraft/unikraft/plat/common/arm/psci_arm64.S

deps_/usr/src/apps/stringsearch/build/libkvmplat/psci_arm64.common.o := \
  /usr/src/unikraft/unikraft/include/uk/asm.h \
  /usr/src/unikraft/unikraft/plat/common/include/arm/cpu_defs.h \
  /usr/src/unikraft/unikraft/plat/common/include/arm/arm64/cpu_defs.h \

/usr/src/apps/stringsearch/build/libkvmplat/psci_arm64.common.o: $(deps_/usr/src/apps/stringsearch/build/libkvmplat/psci_arm64.common.o)

$(deps_/usr/src/apps/stringsearch/build/libkvmplat/psci_arm64.common.o):

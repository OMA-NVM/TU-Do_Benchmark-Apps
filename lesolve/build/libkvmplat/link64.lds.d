cmd_/usr/src/apps/lesolve/build/libkvmplat/link64.lds := aarch64-linux-gnu-gcc -E -P -x assembler-with-cpp -nostdlib -U __linux__ -U __FreeBSD__ -U __sun__ -fno-stack-protector -Wall -Wextra -D __Unikraft__ -DUK_CODENAME="Enceladus" -DUK_VERSION=0.8 -DUK_FULLVERSION=0.8.0~507b1e9 -fno-tree-sra -fno-split-stack -nostdinc -O2 -fno-omit-frame-pointer -fno-PIC -I/usr/src/apps/lesolve/build/include -I/usr/src/unikraft/unikraft/arch/arm/arm64/include -I/usr/src/unikraft/unikraft/include -I/usr/src/unikraft/unikraft/lib/uklibparam/include  -I/usr/src/unikraft/unikraft/plat/kvm/include -I/usr/src/unikraft/unikraft/plat/common/include   -D__ARM_64__ -mfix-cortex-a53-835769 -mfix-cortex-a53-843419 -DCC_VERSION=9.2 -D__ASSEMBLY__   -DKVMPLAT    /usr/src/unikraft/unikraft/plat/kvm/arm/link64.lds.S -o /usr/src/apps/lesolve/build/libkvmplat/link64.lds -Wp,-MD,/usr/src/apps/lesolve/build/libkvmplat/.link64.lds.d

source_/usr/src/apps/lesolve/build/libkvmplat/link64.lds := /usr/src/unikraft/unikraft/plat/kvm/arm/link64.lds.S

deps_/usr/src/apps/lesolve/build/libkvmplat/link64.lds := \
  /usr/src/unikraft/unikraft/include/uk/arch/limits.h \
  /usr/src/unikraft/unikraft/include/uk/config.h \
  /usr/src/unikraft/unikraft/arch/arm/arm64/include/uk/asm/limits.h \
    $(wildcard include/config/stack/size/page/order.h) \
  /usr/src/unikraft/unikraft/plat/common/include/uk/plat/common/common.lds.h \

/usr/src/apps/lesolve/build/libkvmplat/link64.lds: $(deps_/usr/src/apps/lesolve/build/libkvmplat/link64.lds)

$(deps_/usr/src/apps/lesolve/build/libkvmplat/link64.lds):

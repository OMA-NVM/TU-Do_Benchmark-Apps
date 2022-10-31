OUTPUT_ARCH(aarch64)
SECTIONS {
	.apptext :
	{
        . = ALIGN(0x8);
        __apptext_start = .;
		*(.text)
		*(.text.*)
        . = ALIGN(0x8);
        __apptext_end = .;
	}

	.approdata :
	{
        . = ALIGN(0x8);
        __approdata_start = .;
		*(.rodata)
		*(.rodata.*)
        . = ALIGN(0x8);
        __approdata_end = .;
	}

	.preinit_array : {
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP (*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);
	}

	.init_array : {
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
		KEEP (*(.init_array .ctors))
		PROVIDE_HIDDEN (__init_array_end = .);
	}
	.appdata :
	{
        . = ALIGN(0x8);
        __appdata_start = .;
		*(.data)
		*(.data.*)
        . = ALIGN(0x8);
        __appdata_end = .;
	}
	.appbss :
	{
        . = ALIGN(0x8);
        __appbss_start = .;
		*(.bss)
		*(.bss.*)
		*(COMMON)
        . = ALIGN(0x8);
        __appbss_end = .;
	}

    .appstack :
	{
        . = ALIGN(0x8);
        __appstack_start = .;
		. += 0x10000;
        . = ALIGN(0x8);
        __appstack_end = .;
	}

    .appheap :
	{
        . = ALIGN(0x8);
        __appheap_start = .;
		. += 0x80000;
        . = ALIGN(0x8);
        __appheap_end = .;
	}
    
}
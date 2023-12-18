global start
extern kmain

section .text					; start of the text (code) section
	align 4						; the code must be 4 byte aligned
	dd 0x1BADB002				; write the magic number to the machine code,
	dd 0x0						; the flags,
	dd - (0x1BADB002 + 0x0)		; and the checksum

	start:						; the loader label (defined as entry point in linker script)
		call kmain				; call the function, the result will be in eax

	.loop:
		jmp .loop				; loop forever

section .bss
	align 4						; align at 4 bytes
	kernel_stack:				; label points to beginning of memory
	resb 4096					; reserve stack for the kernel
	.file	"p3_60.c"
	.text
	.globl	_loop
	.def	_loop;	.scl	2;	.type	32;	.endef
_loop:
LFB0:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %esi
	movl	16(%esp), %ecx
	movl	$1, %edx
	movl	$0, %eax
	jmp	L2
L3:
	movl	%edx, %ebx
	andl	%esi, %ebx
	orl	%ebx, %eax
	sall	%cl, %edx
L2:
	testl	%edx, %edx
	jne	L3
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (GNU) 5.3.0"

	.file	"p3_58.c"
	.text
	.globl	_decode2
	.def	_decode2;	.scl	2;	.type	32;	.endef
_decode2:
LFB0:
	.cfi_startproc
	movl	8(%esp), %edx
	subl	12(%esp), %edx
	movl	%edx, %eax
	imull	4(%esp), %eax
	sall	$31, %edx
	sarl	$31, %edx
	xorl	%edx, %eax
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (GNU) 5.3.0"

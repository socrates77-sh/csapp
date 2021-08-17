	.file	"p3_61.c"
	.text
	.globl	_cread_alt
	.def	_cread_alt;	.scl	2;	.type	32;	.endef
_cread_alt:
LFB0:
	.cfi_startproc
	movl	4(%esp), %eax
	testl	%eax, %eax
	je	L3
	movl	(%eax), %eax
	ret
L3:
	movl	$0, %eax
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (GNU) 5.3.0"

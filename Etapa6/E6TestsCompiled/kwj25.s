	.file	"programa.c"
	.text
	.comm	x,4
	.globl	f
	.type	f, @function
	.globl	main
	.type	main, @function
.L25:
	movl	$1024, %RBP
.L24:
	movl	$1024, %rsp
.L23:
	movl	$24, %rip
.L22:
	jmp	.L9
.L0:
.L1:
	movq	%rsp, %RBP
.L8:
	addq	$4, %rsp
.L2:
.L3:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L4:
	leave
	ret
.L7:
.L9:
	movq	%rsp, %RBP
.L21:
	addq	$8, %rsp
.L11:
.L13:
.L16:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L18:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L20:
	leave
	ret

	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L12:
	movl	$1024, %RBP
.L11:
	movl	$1024, %rsp
.L10:
	movl	$11, %rip
.L9:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L8:
	addq	$0, %rsp
.L3:
.L4:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L5:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L7:
	leave
	ret

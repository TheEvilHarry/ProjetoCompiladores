	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	main
	.type	main, @function
.L31:
	movl	$1024, %RBP
.L30:
	movl	$1024, %rsp
.L29:
	movl	$28, %rip
.L28:
	jmp	.L12
.L0:
.L1:
	movq	%rsp, %RBP
.L11:
	addq	$0, %rsp
.L3:
	subq	$4, %rsp
	movl	$9, (%rsp)
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
.L10:
.L12:
	movq	%rsp, %RBP
.L27:
	addq	$4, %rsp
.L15:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L16:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L17:
.L19:
.L22:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L24:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L25:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L26:
	leave
	ret

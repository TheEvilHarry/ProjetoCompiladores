	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L27:
	movl	$1024, %RBP
.L26:
	movl	$1024, %rsp
.L25:
	movl	$25, %rip
.L24:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L23:
	addq	$0, %rsp
.L4:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L6:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L8:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	subq	$4, %rsp
	movl	$0, (%rsp)
.L10:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.L16
.L15:
.L11:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L19:
	jmp	.L17
.L16:
.L13:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L14:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L17:
.L20:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L21:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L22:
	leave
	ret

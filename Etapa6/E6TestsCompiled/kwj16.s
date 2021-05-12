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
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L6:
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L8:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
.L10:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.L16
.L15:
.L11:
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L19:
	jmp	.L17
.L16:
.L13:
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

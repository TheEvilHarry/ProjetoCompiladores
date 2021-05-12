	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L29:
	movl	$1024, %RBP
.L28:
	movl	$1024, %rsp
.L27:
	movl	$27, %rip
.L26:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L25:
	addq	$0, %rsp
.L4:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L5:
	subq	$4, %rsp
	movl	$0, (%rsp)
.L6:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	subl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L8:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L9:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L10:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	subq	$4, %rsp
	movl	$0, (%rsp)
.L12:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.L18
.L17:
.L13:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L14:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L21:
	jmp	.L19
.L18:
.L15:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L16:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L19:
.L22:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L24:
	leave
	ret

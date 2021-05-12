	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L28:
	movl	$1024, %RBP
.L27:
	movl	$1024, %rsp
.L26:
	movl	$25, %rip
.L25:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L24:
	addq	$0, %rsp
.L5:
	subq	$4, %rsp
	movl	$75, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L7:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L9:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L13:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	subq	$4, %rsp
	movl	$5, (%rsp)
.L15:
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L17:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L18:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L19:
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L21:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L23:
	leave
	ret

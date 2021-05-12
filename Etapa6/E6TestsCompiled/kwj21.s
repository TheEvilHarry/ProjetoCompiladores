	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
	movl	$1024, (%rbp)
	movl	$1024, (%rsp)
	movl	$27, (%rip)
	jmp	.L1
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
	addq	$0, %rsp
	subq	$4, %rsp
	movl	$3, (%rsp)
	subq	$4, %rsp
	movl	$0, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	subl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
	subq	$4, %rsp
	movl	$2, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	subq	$4, %rsp
	movl	$0, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.L18
	subq	$4, %rsp
	movl	$3, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
	jmp	.L19
	subq	$4, %rsp
	movl	$4, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	leave
	ret

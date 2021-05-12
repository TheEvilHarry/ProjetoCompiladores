	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	main
	.type	main, @function
	movl	$1024, (%rbp)
	movl	$1024, (%rsp)
	movl	$30, (%rip)
	jmp	.L12
f:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
	addq	$0, %rsp
	subq	$4, %rsp
	movl	$9, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	leave
	ret
main:
	endbr64
	pushq	%rbp
.L12:
	movq	%rsp, %rbp
	addq	$4, %rsp
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	subq	$4, %rsp
	movl	$1, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	leave
	ret

	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
	movl	$1024, (%rbp)
	movl	$1024, (%rsp)
	movl	$19, (%rip)
	jmp	.L1
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
	addq	$0, %rsp
	subq	$4, %rsp
	movl	$2, (%rsp)
	subq	$4, %rsp
	movl	$4, (%rsp)
	subq	$4, %rsp
	movl	$2, (%rsp)
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
	subq	$4, %rsp
	movl	$4, (%rsp)
	subq	$4, %rsp
	movl	$4, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
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

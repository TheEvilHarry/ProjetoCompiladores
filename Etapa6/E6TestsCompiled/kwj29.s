	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
	movl	$1024, (%rbp)
	movl	$1024, (%rsp)
	movl	$98, (%rip)
	jmp	.L79
f:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
	addq	$0, %rsp
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	leave
	ret
mult:
	endbr64
	pushq	%rbp
.L14:
	movq	%rsp, %rbp
	addq	$4, %rsp
	movl	28(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%rbp)
	movl	32(%rbp), %eax 
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
	movl	%eax, 32(%rbp)
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%rbp)
	movl	36(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	subq	$4, %rsp
	movl	$3, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%rbp)
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%rbp)
	movl	40(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	subq	$4, %rsp
	movl	$2, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%rbp)
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 44(%rbp)
	movl	44(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	subq	$4, %rsp
	movl	$4, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 44(%rbp)
	movl	32(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
	movl	36(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 48(%rbp)
	movl	40(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
	movl	44(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 52(%rbp)
	movl	48(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	52(%rbp), %eax 
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
	movl	%eax, 56(%rbp)
	movl	56(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	leave
	ret
main:
	endbr64
	pushq	%rbp
.L79:
	movq	%rsp, %rbp
	addq	$8, %rsp
	subq	$4, %rsp
	movl	$7, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
	subq	$4, %rsp
	movl	$3, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rsp)
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rsp)
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

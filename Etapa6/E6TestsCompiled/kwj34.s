	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
	movl	$1024, (%rbp)
	movl	$1024, (%rsp)
	movl	$25, (%rip)
	jmp	.L1
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
	addq	$0, %rsp
	subq	$4, %rsp
	movl	$1, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
	subq	$4, %rsp
	movl	$6, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jge	.L17
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
	jmp	.L15
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
	movl	(%rsp), %eax
	addq	$4, %rsp
	leave
	ret

	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L12:
	movl	$1024, (%rbp)
.L11:
	movl	$1024, (%rsp)
.L10:
	movl	$11, (%rip)
.L9:
	jmp	.L1
.L0:
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L8:
	addq	$0, %rsp
.L3:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L4:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L5:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L7:
	leave
	ret

	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L26:
	movl	$1024, (%rbp)
.L25:
	movl	$1024, (%rsp)
.L24:
	movl	$23, (%rip)
.L23:
	jmp	.L1
.L0:
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L22:
	addq	$0, %rsp
.L5:
	subq	$4, %rsp
	movl	$15, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L7:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L9:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L13:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	subq	$4, %rsp
	movl	$10, (%rsp)
.L17:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L18:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L19:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L21:
	leave
	ret

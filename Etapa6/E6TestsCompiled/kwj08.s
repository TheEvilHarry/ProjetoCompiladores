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
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L13:
	subq	$4, %rsp
	movl	$20, (%rsp)
.L14:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L16:
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
	subq	$4, %rsp
	movl	%eax, (%rsp)
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
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L21:
	leave
	ret

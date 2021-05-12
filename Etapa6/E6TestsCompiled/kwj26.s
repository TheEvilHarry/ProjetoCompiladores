	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	main
	.type	main, @function
.L32:
	movl	$1024, (%rbp)
.L31:
	movl	$1024, (%rsp)
.L30:
	movl	$30, (%rip)
.L29:
	jmp	.L12
.L0:
.L1:
	movq	%rsp, %rbp
.L11:
	addq	$0, %rsp
.L3:
.L4:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L5:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L7:
	leave
	ret
.L10:
.L12:
	movq	%rsp, %rbp
.L28:
	addq	$4, %rsp
.L14:
.L16:
.L19:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L21:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
.L23:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L24:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L25:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L26:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L27:
	leave
	ret

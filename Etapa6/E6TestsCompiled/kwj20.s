	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L37:
	movl	$1024, (%rbp)
.L36:
	movl	$1024, (%rsp)
.L35:
	movl	$33, (%rip)
.L34:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %rbp
.L33:
	addq	$0, %rsp
.L6:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rbp)
.L8:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L9:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L10:
	subq	$4, %rsp
	movl	$9, (%rsp)
.L11:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L12:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L13:
	subq	$4, %rsp
	movl	$0, (%rsp)
.L14:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	subl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L16:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	subq	$4, %rsp
	movl	$0, (%rsp)
.L18:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.L26
.L25:
.L19:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L21:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
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
	movl	%eax, 20(%rbp)
.L29:
	jmp	.L27
.L26:
.L27:
.L30:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L31:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L32:
	leave
	ret

	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L34:
	movl	$1024, (%rbp)
.L33:
	movl	$1024, (%rsp)
.L32:
	movl	$31, (%rip)
.L31:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %rbp
.L30:
	addq	$0, %rsp
.L5:
	subq	$4, %rsp
	movl	$10, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L7:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L9:
	subq	$4, %rsp
	movl	$0, (%rsp)
.L10:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L22:
.L11:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	subq	$4, %rsp
	movl	$5, (%rsp)
.L13:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.L24
.L23:
.L14:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L16:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	subl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L18:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L20:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L21:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L26:
	jmp	.L22
.L24:
.L27:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L28:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L29:
	leave
	ret

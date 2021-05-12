	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L42:
	movl	$1024, (%rbp)
.L41:
	movl	$1024, (%rsp)
.L40:
	movl	$39, (%rip)
.L39:
	jmp	.L1
.L0:
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
.L38:
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
	movl	$0, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L9:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L10:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L30:
.L11:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L13:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jne	.(null)
.L21:
.L19:
.L14:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	subq	$4, %rsp
	movl	$5, (%rsp)
.L16:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.(null)
.L18:
.L33:
.L31:
.L22:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L24:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	subl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L25:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L26:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L27:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L28:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L29:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L34:
	jmp	.L30
.L32:
.L35:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L36:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L37:
	leave
	ret

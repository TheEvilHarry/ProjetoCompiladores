	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L42:
	movl	$1024, (%rbp)
.L41:
	movl	$1024, (%rsp)
.L40:
	movl	$37, (%rip)
.L39:
	jmp	.L1
.L0:
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
.L38:
	addq	$0, %rsp
.L7:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L9:
	subq	$4, %rsp
	movl	$0, (%rsp)
.L10:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L11:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L13:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L14:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rbp)
.L15:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jge	.(null)
.L25:
.L23:
.L18:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jge	.(null)
.L22:
.L33:
.L30:
.L26:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L27:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%rbp)
.L34:
	jmp	.L32
.L31:
.L28:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L29:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%rbp)
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

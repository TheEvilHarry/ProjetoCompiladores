	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	main
	.type	main, @function
.L31:
	movl	$1024, (%rbp)
.L30:
	movl	$1024, (%rsp)
.L29:
	movl	$28, (%rip)
.L28:
	jmp	.L12
.L0:
f:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
.L11:
	addq	$0, %rsp
.L3:
	subq	$4, %rsp
	movl	$9, (%rsp)
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
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
.L27:
	addq	$4, %rsp
.L15:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L16:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L17:
.L19:
.L22:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L24:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L25:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L26:
	leave
	ret

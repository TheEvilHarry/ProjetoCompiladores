	.file	"programa.c"
	.text
	.comm	x,4
	.globl	f
	.type	f, @function
	.globl	main
	.type	main, @function
.L25:
	movl	$1024, (%rbp)
.L24:
	movl	$1024, (%rsp)
.L23:
	movl	$24, (%rip)
.L22:
	jmp	.L9
.L0:
f:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L8:
	addq	$4, %rsp
.L2:
	subq	$4, %rsp
	movl	$9, (%rsp)
.L3:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L4:
	leave
	ret
.L7:
main:
	endbr64
	pushq	%rbp
.L9:
	movq	%rsp, %rbp
.L21:
	addq	$8, %rsp
.L11:
.L13:
.L16:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L18:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L20:
	leave
	ret

	.file	"programa.c"
	.text
	.comm	c,4
	.comm	b,4
	.comm	a,4
	.comm	z,4
	.globl	main
	.type	main, @function
.L17:
	movl	$1024, (%rbp)
.L16:
	movl	$1024, (%rsp)
.L15:
	movl	$17, (%rip)
.L14:
	jmp	.L1
.L0:
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L13:
	addq	$16, %rsp
.L2:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L3:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, b(%rip)
.L4:
	subq	$4, %rsp
	movl	$9, (%rsp)
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, z(%rip)
.L6:
	movl	c(%rip), %eax
 	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	c(%rip), %eax
 	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, a(%rip)
.L10:
	movl	c(%rip), %eax
 	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L12:
	leave
	ret

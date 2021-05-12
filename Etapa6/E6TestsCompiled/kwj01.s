	.file	"programa.c"
	.text
	.comm	z,4
	.globl	main
	.type	main, @function
.L21:
	movl	$1024, (%rbp)
.L20:
	movl	$1024, (%rsp)
.L19:
	movl	$17, (%rip)
.L18:
	jmp	.L1
.L0:
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L17:
	addq	$4, %rsp
.L6:
	subq	$4, %rsp
	movl	$9, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, z(%rip)
.L8:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L9:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L10:
	movl	z(%rip), %eax
 	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L13:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rbp)
.L14:
	movl	28(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L16:
	leave
	ret

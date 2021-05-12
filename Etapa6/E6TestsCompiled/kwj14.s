	.file	"programa.c"
	.text
	.comm	z,4
	.globl	main
	.type	main, @function
.L18:
	movl	$1024, (%rbp)
.L17:
	movl	$1024, (%rsp)
.L16:
	movl	$17, (%rip)
.L15:
	jmp	.L1
.L0:
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L14:
	addq	$4, %rsp
.L3:
	subq	$4, %rsp
	movl	$10, (%rsp)
.L4:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, z(%rip)
.L5:
	movl	z(%rip), %eax
 	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L7:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L9:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L11:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L13:
	leave
	ret

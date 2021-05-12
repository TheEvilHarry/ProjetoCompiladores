	.file	"programa.c"
	.text
	.comm	z,4
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
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L30:
	addq	$4, %rsp
.L5:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, z(%rip)
.L7:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L9:
	subq	$4, %rsp
	movl	$9, (%rsp)
.L10:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L11:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L13:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	subq	$4, %rsp
	movl	$0, (%rsp)
.L15:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.L23
.L22:
.L16:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L17:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L18:
	movl	z(%rip), %eax
 	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
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
	movl	%eax, 20(%rbp)
.L26:
	jmp	.L24
.L23:
.L24:
.L27:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L28:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L29:
	leave
	ret

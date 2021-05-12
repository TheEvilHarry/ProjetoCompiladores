	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L28:
	movl	$1024, (%rbp)
.L27:
	movl	$1024, (%rsp)
.L26:
	movl	$25, (%rip)
.L25:
	jmp	.L1
.L0:
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L24:
	addq	$0, %rsp
.L5:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L7:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L9:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L13:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L17:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L18:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L21:
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L23:
	leave
	ret

	.file	"programa.c"
	.text
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
.L39:
	movl	$1024, (%rbp)
.L38:
	movl	$1024, (%rsp)
.L37:
	movl	$36, (%rip)
.L36:
	jmp	.L14
.L0:
mult:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L13:
	addq	$0, %rsp
.L3:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L4:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L7:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L9:
	leave
	ret
.L12:
main:
	endbr64
	pushq	%rbp
.L14:
	movq	%rsp, %rbp
.L35:
	addq	$4, %rsp
.L17:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L18:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L20:
.L19:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L23:
.L26:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L27:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L28:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L29:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L30:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L31:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L32:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L33:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L34:
	leave
	ret

	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L27:
	movl	$1024, (%rbp)
.L26:
	movl	$1024, (%rsp)
.L25:
	movl	$25, (%rip)
.L24:
	jmp	.L1
.L0:
main:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L23:
	addq	$0, %rsp
.L4:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L6:
	subq	$4, %rsp
	movl	$6, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L15:
.L8:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jge	.L17
.L16:
.L11:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L13:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L19:
	jmp	.L15
.L17:
.L20:
	movl	16(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L21:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L22:
	leave
	ret

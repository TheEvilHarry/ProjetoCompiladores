	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L20:
	movl	$1024, (%rbp)
.L19:
	movl	$1024, (%rsp)
.L18:
	movl	$19, (%rip)
.L17:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %rbp
.L16:
	addq	$0, %rsp
.L3:
.L4:
.L5:
.L6:
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
.L9:
.L10:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L13:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L15:
	leave
	ret

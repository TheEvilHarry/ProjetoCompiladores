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
	subq	$4, %rsp
	movl	$2, (%rsp)
.L4:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L5:
	subq	$4, %rsp
	movl	$2, (%rsp)
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
	subq	$4, %rsp
	movl	$4, (%rsp)
.L9:
	subq	$4, %rsp
	movl	$4, (%rsp)
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

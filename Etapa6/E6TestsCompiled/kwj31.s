	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
.L94:
	movl	$1024, (%rbp)
.L93:
	movl	$1024, (%rsp)
.L92:
	movl	$86, (%rip)
.L91:
	jmp	.L53
.L0:
.L1:
	movq	%rsp, %rbp
.L10:
	addq	$0, %rsp
.L2:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L3:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L4:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L6:
	leave
	ret
.L9:
.L11:
	movq	%rsp, %rbp
.L52:
	addq	$4, %rsp
.L18:
.L16:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L17:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L21:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L22:
.L25:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L26:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%rbp)
.L29:
.L27:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L31:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L28:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L32:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L33:
.L36:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L37:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 44(%rbp)
.L38:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L39:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L40:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L41:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%rbp)
.L42:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L43:
.L44:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L45:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%rbp)
.L46:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L47:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L48:
	leave
	ret
.L51:
.L53:
	movq	%rsp, %rbp
.L90:
	addq	$8, %rsp
.L58:
.L59:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L60:
.L61:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L62:
.L63:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rbp)
.L76:
.L64:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L65:
.L66:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L78:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L67:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L68:
.L69:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L79:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L70:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L71:
.L72:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L80:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rsp)
.L73:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L74:
.L75:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L81:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rsp)
.L82:
.L85:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L86:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L87:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L88:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L89:
	leave
	ret

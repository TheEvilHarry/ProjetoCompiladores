	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
.L110:
	movl	$1024, (%rbp)
.L109:
	movl	$1024, (%rsp)
.L108:
	movl	$102, (%rip)
.L107:
	jmp	.L69
.L0:
f:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
.L13:
	addq	$0, %rsp
.L3:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L4:
	movl	rfp(%rbp), %eax 
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
	movl	%eax, 24(%rbp)
.L7:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L9:
	leave
	ret
.L12:
mult:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
.L68:
	addq	$4, %rsp
.L20:
.L18:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L19:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L24:
.L27:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L28:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%rbp)
.L31:
.L29:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L33:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L30:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L34:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L35:
.L38:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L39:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%rbp)
.L42:
.L40:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L44:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L41:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L45:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L46:
.L49:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L52:
.L50:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L54:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L51:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L55:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L56:
.L59:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L60:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L61:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%rbp)
.L62:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L63:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L64:
	leave
	ret
.L67:
main:
	endbr64
	pushq	%rbp
	movq	%rsp, %rbp
.L106:
	addq	$8, %rsp
.L74:
	subq	$4, %rsp
	movl	$2019, (%rsp)
.L75:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L76:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L77:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L78:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L79:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rbp)
.L92:
.L80:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L81:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L82:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L94:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L83:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L84:
	subq	$4, %rsp
	movl	$4, (%rsp)
.L85:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L95:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L86:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L87:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L88:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L96:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rsp)
.L89:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L90:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L91:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L97:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rsp)
.L98:
.L101:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L102:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rbp)
.L103:
	movl	rfp(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L104:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L105:
	leave
	ret

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
f:
	endbr64
	pushq	%rbp
.L1:
	movq	%rsp, %rbp
.L10:
	addq	$0, %rsp
.L2:
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L3:
	movl	16(%rbp), %eax 
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
mult:
	endbr64
	pushq	%rbp
.L11:
	movq	%rsp, %rbp
.L52:
	addq	$4, %rsp
.L18:
.L16:
	movl	28(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L17:
	movl	24(%rbp), %eax 
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
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L31:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L28:
	movl	16(%rbp), %eax 
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
	movl	40(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L39:
	movl	44(%rbp), %eax 
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
	movl	32(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L43:
	subq	$4, %rsp
	movl	$1, (%rsp)
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
	movl	36(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L47:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L48:
	leave
	ret
.L51:
main:
	endbr64
	pushq	%rbp
.L53:
	movq	%rsp, %rbp
.L90:
	addq	$8, %rsp
.L58:
	subq	$4, %rsp
	movl	$2018, (%rsp)
.L59:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rbp)
.L60:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L61:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rbp)
.L62:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L63:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rbp)
.L76:
.L64:
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L65:
	subq	$4, %rsp
	movl	$3, (%rsp)
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
	movl	24(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L68:
	subq	$4, %rsp
	movl	$3, (%rsp)
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
	movl	28(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L71:
	subq	$4, %rsp
	movl	$2, (%rsp)
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
	movl	28(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L74:
	subq	$4, %rsp
	movl	$2, (%rsp)
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
	movl	20(%rbp), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L88:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L89:
	leave
	ret

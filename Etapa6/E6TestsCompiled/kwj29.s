	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
.L109:
	movl	$1024, %RBP
.L108:
	movl	$1024, %rsp
.L107:
	movl	$98, %rip
.L106:
	jmp	.L79
.L0:
.L1:
	movq	%rsp, %RBP
.L13:
	addq	$0, %rsp
.L3:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L4:
	movl	rfp(%RBP), %eax 
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
	movl	%eax, 24(%RBP)
.L7:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L9:
	leave
	ret
.L12:
.L14:
	movq	%rsp, %RBP
.L78:
	addq	$4, %rsp
.L22:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%RBP)
.L24:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L25:
	subq	$4, %rsp
	movl	$1, (%rsp)
.L26:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L27:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%RBP)
.L28:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L29:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%RBP)
.L30:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L31:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L32:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L33:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%RBP)
.L34:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L35:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%RBP)
.L36:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L37:
	subq	$4, %rsp
	movl	$2, (%rsp)
.L38:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L39:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%RBP)
.L40:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L41:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 44(%RBP)
.L42:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L43:
	subq	$4, %rsp
	movl	$4, (%rsp)
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
	movl	%eax, 44(%RBP)
.L48:
.L46:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L50:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L47:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L51:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L52:
.L55:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L56:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 48(%RBP)
.L59:
.L57:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L61:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L58:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L62:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L63:
.L66:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L67:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 52(%RBP)
.L68:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L69:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L70:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L71:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 56(%RBP)
.L72:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L73:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L74:
	leave
	ret
.L77:
.L79:
	movq	%rsp, %RBP
.L105:
	addq	$8, %rsp
.L83:
	subq	$4, %rsp
	movl	$7, (%rsp)
.L84:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L85:
	subq	$4, %rsp
	movl	$3, (%rsp)
.L86:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L91:
.L87:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L93:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L88:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L94:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L89:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L95:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rsp)
.L90:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L96:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rsp)
.L97:
.L100:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L101:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L102:
	movl	rfp(%RBP), %eax 
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L103:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L104:
	leave
	ret

L42: loadI 1024 => rfp
L41: loadI 1024 => rsp
L40: loadI 37 => rbss
L39: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L38: addI rsp, 0 => rsp
L7: loadI 1 => r0
L8: storeAI r0 => rfp, 16
L9: loadI 0 => r1
L10: storeAI r1 => rfp, 20
L11: loadI 2 => r2
L12: storeAI r2 => rfp, 24
L13: loadI 3 => r3
L14: storeAI r3 => rfp, 28
L15: loadAI rfp, 16 => r4
L16: loadAI rfp, 20 => r5
L17: cmp_LT r4, r5 => r6
L24: i2i r6 => r10
L25: cbr r10 => L23, L22
L23: 
L18: loadAI rfp, 24 => r7
L19: loadAI rfp, 28 => r8
L20: cmp_LT r7, r8 => r9
L21: and r6, r9 => r10
L22: 
L33: cbr r10 => L30, L31
L30: 
L26: loadI 2 => r11
L27: storeAI r11 => rfp, 32
L34: jumpI  => L32
L31: 
L28: loadI 3 => r12
L29: storeAI r12 => rfp, 32
L32: 
L35: loadAI rfp, 32 => r13
L36: storeAI r13 => rfp, 4
L37: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L42:
	movl	(null)(%), %RBP
.L41:
	movl	(null)(%), %rsp
.L40:
	movl	(null)(%), %rip
.L39:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L38:
	addq	$0, %rsp
.L7:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L9:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L11:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L13:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%RBP)
.L15:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jge	.(null)
.L25:
.L23:
.L18:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jge	.(null)
.L22:
.L33:
.L30:
.L26:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L27:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%RBP)
.L34:
	jmp	.L32
.L31:
.L28:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L29:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%RBP)
.L32:
.L35:
	movl	32(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L36:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L37:
	leave
	ret

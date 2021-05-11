L37: loadI 1024 => rfp
L36: loadI 1024 => rsp
L35: loadI 33 => rbss
L34: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L33: addI rsp, 0 => rsp
L6: loadI 2 => r0
L7: storeAI r0 => rfp, 28
L8: loadI 4 => r1
L9: storeAI r1 => rfp, 20
L10: loadI 9 => r2
L11: storeAI r2 => rfp, 24
L12: loadI 4 => r3
L13: loadI 0 => r5
L14: sub r5, r3 => r4
L15: storeAI r4 => rfp, 16
L16: loadAI rfp, 16 => r6
L17: loadI 0 => r7
L18: cmp_GT r6, r7 => r8
L28: cbr r8 => L25, L26
L25: 
L19: loadI 1 => r9
L20: storeAI r9 => rfp, 24
L21: loadAI rfp, 28 => r10
L22: loadAI rfp, 24 => r11
L23: add r10, r11 => r12
L24: storeAI r12 => rfp, 20
L29: jumpI  => L27
L26: 
L27: 
L30: loadAI rfp, 20 => r13
L31: storeAI r13 => rfp, 4
L32: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L37:
	movl	(null)(%), %RBP
.L36:
	movl	(null)(%), %rsp
.L35:
	movl	(null)(%), %rip
.L34:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L33:
	addq	$0, %rsp
.L6:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%RBP)
.L8:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L10:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L12:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L13:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	subl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L16:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L18:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.L26
.L25:
.L19:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L21:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L24:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L29:
	jmp	.L27
.L26:
.L27:
.L30:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L31:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L32:
	leave
	ret

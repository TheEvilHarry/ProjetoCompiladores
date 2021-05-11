L35: loadI 1024 => rfp
L34: loadI 1024 => rsp
L33: loadI 33 => rbss
L32: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L31: addI rsp, 4 => rsp
L4: loadI 0 => r0
L5: storeAI r0 => rfp, 20
L6: loadI 0 => r1
L7: storeAI r1 => rfp, 16
L23: 
L8: loadAI rfp, 16 => r2
L9: loadI 24 => r3
L10: cmp_LT r2, r3 => r4
L26: cbr r4 => L24, L25
L24: 
L15: loadAI rfp, 20 => r8
L16: loadI 1 => r9
L17: add r8, r9 => r10
L18: storeAI r10 => rfp, 20
L19: loadAI rfp, 20 => r11
L20: loadAI rfp, 16 => r12
L21: add r11, r12 => r13
L22: storeAI r13 => rbss, 0
L11: loadAI rfp, 16 => r5
L12: loadI 2 => r6
L13: add r5, r6 => r7
L14: storeAI r7 => rfp, 16
L27: jumpI  => L23
L25: 
L28: loadAI rbss, 0 => r14
L29: storeAI r14 => rfp, 4
L30: jumpI  => L0
	.file	"programa.c"
	.text
	.comm	c,4
	.globl	main
	.type	main, @function
.L35:
	movl	(null)(%), %RBP
.L34:
	movl	(null)(%), %rsp
.L33:
	movl	(null)(%), %rip
.L32:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L31:
	addq	$4, %rsp
.L4:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L6:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L23:
.L8:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jge	.L25
.L24:
.L15:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L18:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L19:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L21:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, c(%rip)
.L11:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
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
	movl	%eax, 16(%RBP)
.L27:
	jmp	.L23
.L25:
.L28:
	movl	c(%rip), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L29:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L30:
	leave
	ret

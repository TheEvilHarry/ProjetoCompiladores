L34: loadI 1024 => rfp
L33: loadI 1024 => rsp
L32: loadI 31 => rbss
L31: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L30: addI rsp, 4 => rsp
L5: loadI 2 => r0
L6: storeAI r0 => rbss, 0
L7: loadI 4 => r1
L8: storeAI r1 => rfp, 20
L9: loadI 9 => r2
L10: storeAI r2 => rfp, 24
L11: loadI 1 => r3
L12: storeAI r3 => rfp, 16
L13: loadAI rfp, 16 => r4
L14: loadI 0 => r5
L15: cmp_GT r4, r5 => r6
L25: cbr r6 => L22, L23
L22: 
L16: loadI 1 => r7
L17: storeAI r7 => rfp, 24
L18: loadAI rbss, 0 => r8
L19: loadAI rfp, 24 => r9
L20: add r8, r9 => r10
L21: storeAI r10 => rfp, 20
L26: jumpI  => L24
L23: 
L24: 
L27: loadAI rfp, 20 => r11
L28: storeAI r11 => rfp, 4
L29: jumpI  => L0
	.file	"programa.c"
	.text
	.comm	z,4
	.globl	main
	.type	main, @function
.L34:
	movl	(null)(%), %RBP
.L33:
	movl	(null)(%), %rsp
.L32:
	movl	(null)(%), %rip
.L31:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L30:
	addq	$4, %rsp
.L5:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, z(%rip)
.L7:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L9:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L11:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L13:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cmpl	%edx, %eax
	jle	.L23
.L22:
.L16:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L18:
	movl	z(%rip), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L21:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L26:
	jmp	.L24
.L23:
.L24:
.L27:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L28:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L29:
	leave
	ret

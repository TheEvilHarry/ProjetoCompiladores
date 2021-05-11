L27: loadI 1024 => rfp
L26: loadI 1024 => rsp
L25: loadI 25 => rbss
L24: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L23: addI rsp, 0 => rsp
L4: loadI 1 => r0
L5: storeAI r0 => rfp, 16
L6: loadI 2 => r1
L7: storeAI r1 => rfp, 20
L8: loadAI rfp, 16 => r2
L9: loadI 0 => r3
L10: cmp_GT r2, r3 => r4
L18: cbr r4 => L15, L16
L15: 
L11: loadI 3 => r5
L12: storeAI r5 => rfp, 20
L19: jumpI  => L17
L16: 
L13: loadI 4 => r6
L14: storeAI r6 => rfp, 20
L17: 
L20: loadAI rfp, 20 => r7
L21: storeAI r7 => rfp, 4
L22: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L27:
	movl	(null)(%), %RBP
.L26:
	movl	(null)(%), %rsp
.L25:
	movl	(null)(%), %rip
.L24:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L23:
	addq	$0, %rsp
.L4:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L6:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
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
	jle	.L16
.L15:
.L11:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L19:
	jmp	.L17
.L16:
.L13:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L17:
.L20:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L21:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L22:
	leave
	ret

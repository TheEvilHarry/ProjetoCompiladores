L25: loadI 1024 => rfp
L24: loadI 1024 => rsp
L23: loadI 24 => rbss
L22: jumpI  => L9
L0: halt  => 
L1: i2i rsp => rfp
L8: addI rsp, 4 => rsp
L2: loadI 9 => r0
L3: storeAI r0 => rfp, 4
L4: loadAI rfp, 0 => r1
L5: loadAI rfp, 12 => rsp
L6: loadAI rfp, 8 => rfp
L7: jump  => r1
L9: i2i rsp => rfp
L21: addI rsp, 8 => rsp
L11: storeAI rsp => rsp, 12
L12: storeAI rfp => rsp, 8
L13: addI rpc, 3 => r3
L14: storeAI r3 => rsp, 0
L15: jumpI  => L1
L16: loadAI rsp, 4 => r2
L17: storeAI r2 => rfp, 16
L18: loadAI rfp, 16 => r4
L19: storeAI r4 => rfp, 4
L20: jumpI  => L0
	.file	"programa.c"
	.text
	.comm	x,4
	.globl	f
	.type	f, @function
	.globl	main
	.type	main, @function
.L25:
	movl	(null)(%), %RBP
.L24:
	movl	(null)(%), %rsp
.L23:
	movl	(null)(%), %rip
.L22:
	jmp	.L9
.L0:
.L1:
	movq	%rsp, %RBP
.L8:
	addq	$4, %rsp
.L2:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L3:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L4:
	leave
	ret
.L7:
.L9:
	movq	%rsp, %RBP
.L21:
	addq	$8, %rsp
.L11:
.L13:
.L16:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L18:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L20:
	leave
	ret

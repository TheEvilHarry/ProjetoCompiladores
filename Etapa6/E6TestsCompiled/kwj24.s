L31: loadI 1024 => rfp
L30: loadI 1024 => rsp
L29: loadI 28 => rbss
L28: jumpI  => L12
L0: halt  => 
L1: i2i rsp => rfp
L11: addI rsp, 0 => rsp
L3: loadI 9 => r0
L4: storeAI r0 => rfp, 16
L5: loadAI rfp, 16 => r1
L6: storeAI r1 => rfp, 4
L7: loadAI rfp, 0 => r2
L8: loadAI rfp, 12 => rsp
L9: loadAI rfp, 8 => rfp
L10: jump  => r2
L12: i2i rsp => rfp
L27: addI rsp, 4 => rsp
L15: loadI 4 => r3
L16: storeAI r3 => rfp, 20
L17: storeAI rsp => rsp, 12
L18: storeAI rfp => rsp, 8
L19: addI rpc, 3 => r5
L20: storeAI r5 => rsp, 0
L21: jumpI  => L1
L22: loadAI rsp, 4 => r4
L23: storeAI r4 => rfp, 16
L24: loadAI rfp, 16 => r6
L25: storeAI r6 => rfp, 4
L26: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	main
	.type	main, @function
.L31:
	movl	(null)(%), %RBP
.L30:
	movl	(null)(%), %rsp
.L29:
	movl	(null)(%), %rip
.L28:
	jmp	.L12
.L0:
.L1:
	movq	%rsp, %RBP
.L11:
	addq	$0, %rsp
.L3:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L4:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L5:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L7:
	leave
	ret
.L10:
.L12:
	movq	%rsp, %RBP
.L27:
	addq	$4, %rsp
.L15:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L17:
.L19:
.L22:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L24:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L25:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L26:
	leave
	ret

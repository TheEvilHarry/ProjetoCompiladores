L32: loadI 1024 => rfp
L31: loadI 1024 => rsp
L30: loadI 30 => rbss
L29: jumpI  => L12
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
L28: addI rsp, 4 => rsp
L14: storeAI rsp => rsp, 12
L15: storeAI rfp => rsp, 8
L16: addI rpc, 3 => r4
L17: storeAI r4 => rsp, 0
L18: jumpI  => L1
L19: loadAI rsp, 4 => r3
L20: storeAI r3 => rfp, 16
L21: loadAI rfp, 16 => r5
L22: loadI 1 => r6
L23: add r5, r6 => r7
L24: storeAI r7 => rfp, 16
L25: loadAI rfp, 16 => r8
L26: storeAI r8 => rfp, 4
L27: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	main
	.type	main, @function
.L32:
	movl	(null)(%), %RBP
.L31:
	movl	(null)(%), %rsp
.L30:
	movl	(null)(%), %rip
.L29:
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
.L28:
	addq	$4, %rsp
.L14:
.L16:
.L19:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L21:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	(null)(%), %eax
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
	movl	%eax, 16(%RBP)
.L25:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L26:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L27:
	leave
	ret

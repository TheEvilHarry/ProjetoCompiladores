L25: loadI 1024 => rfp
L24: loadI 1024 => rsp
L23: loadI 23 => rbss
L22: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L21: addI rsp, 0 => rsp
L4: loadI 14 => r0
L5: storeAI r0 => rfp, 20
L6: loadAI rfp, 20 => r1
L7: loadI 1 => r2
L8: add r1, r2 => r3
L9: storeAI r3 => rfp, 16
L10: loadAI rfp, 16 => r4
L11: loadI 1 => r5
L12: add r4, r5 => r6
L13: storeAI r6 => rfp, 20
L14: loadAI rfp, 16 => r7
L15: loadAI rfp, 20 => r8
L16: add r7, r8 => r9
L17: storeAI r9 => rfp, 16
L18: loadAI rfp, 16 => r10
L19: storeAI r10 => rfp, 4
L20: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L25:
	movl	(null)(%), %RBP
.L24:
	movl	(null)(%), %rsp
.L23:
	movl	(null)(%), %rip
.L22:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L21:
	addq	$0, %rsp
.L4:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L6:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L10:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L13:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L14:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
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

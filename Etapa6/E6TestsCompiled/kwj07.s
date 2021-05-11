L28: loadI 1024 => rfp
L27: loadI 1024 => rsp
L26: loadI 25 => rbss
L25: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L24: addI rsp, 0 => rsp
L5: loadI 2 => r0
L6: storeAI r0 => rfp, 20
L7: loadI 3 => r1
L8: storeAI r1 => rfp, 24
L9: loadAI rfp, 20 => r2
L10: loadAI rfp, 24 => r3
L11: mult r2, r3 => r4
L12: storeAI r4 => rfp, 16
L13: loadAI rfp, 16 => r5
L14: loadAI rfp, 24 => r6
L15: mult r5, r6 => r7
L16: storeAI r7 => rfp, 20
L17: loadAI rfp, 16 => r8
L18: loadAI rfp, 20 => r9
L19: mult r8, r9 => r10
L20: storeAI r10 => rfp, 24
L21: loadAI rfp, 24 => r11
L22: storeAI r11 => rfp, 4
L23: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L28:
	movl	(null)(%), %RBP
.L27:
	movl	(null)(%), %rsp
.L26:
	movl	(null)(%), %rip
.L25:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L24:
	addq	$0, %rsp
.L5:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L7:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L9:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
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
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L17:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L18:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L21:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L23:
	leave
	ret

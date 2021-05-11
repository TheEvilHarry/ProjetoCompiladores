L26: loadI 1024 => rfp
L25: loadI 1024 => rsp
L24: loadI 23 => rbss
L23: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L22: addI rsp, 0 => rsp
L5: loadI 400 => r0
L6: storeAI r0 => rfp, 20
L7: loadI 2 => r1
L8: storeAI r1 => rfp, 24
L9: loadAI rfp, 20 => r2
L10: loadAI rfp, 24 => r3
L11: div r2, r3 => r4
L12: loadAI rfp, 20 => r5
L13: loadAI rfp, 24 => r6
L14: div r5, r6 => r7
L15: loadAI rfp, 24 => r8
L16: div r7, r8 => r9
L17: add r4, r9 => r10
L18: storeAI r10 => rfp, 16
L19: loadAI rfp, 16 => r11
L20: storeAI r11 => rfp, 4
L21: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L26:
	movl	(null)(%), %RBP
.L25:
	movl	(null)(%), %rsp
.L24:
	movl	(null)(%), %rip
.L23:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L22:
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
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L13:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
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
	movl	%eax, 16(%RBP)
.L19:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L21:
	leave
	ret

L34: loadI 1024 => rfp
L33: loadI 1024 => rsp
L32: loadI 31 => rbss
L31: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L30: addI rsp, 0 => rsp
L5: loadI 10 => r0
L6: storeAI r0 => rfp, 16
L7: loadI 2 => r1
L8: storeAI r1 => rfp, 20
L9: loadI 0 => r2
L10: storeAI r2 => rfp, 24
L22: 
L11: loadAI rfp, 16 => r3
L12: loadI 5 => r4
L13: cmp_GT r3, r4 => r5
L25: cbr r5 => L23, L24
L23: 
L14: loadAI rfp, 16 => r6
L15: loadI 1 => r7
L16: sub r6, r7 => r8
L17: storeAI r8 => rfp, 16
L18: loadAI rfp, 24 => r9
L19: loadI 1 => r10
L20: add r9, r10 => r11
L21: storeAI r11 => rfp, 24
L26: jumpI  => L22
L24: 
L27: loadAI rfp, 24 => r12
L28: storeAI r12 => rfp, 4
L29: jumpI  => L0
	.file	"programa.c"
	.text
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
	addq	$0, %rsp
.L5:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
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
.L22:
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
	cmpl	%edx, %eax
	jle	.L24
.L23:
.L14:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	subl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L17:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L18:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L19:
	movl	(null)(%), %eax
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
	movl	%eax, 24(%RBP)
.L26:
	jmp	.L22
.L24:
.L27:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L28:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L29:
	leave
	ret

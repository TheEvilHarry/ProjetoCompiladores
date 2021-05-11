L42: loadI 1024 => rfp
L41: loadI 1024 => rsp
L40: loadI 39 => rbss
L39: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L38: addI rsp, 0 => rsp
L5: loadI 10 => r0
L6: storeAI r0 => rfp, 16
L7: loadI 0 => r1
L8: storeAI r1 => rfp, 20
L9: loadI 2 => r2
L10: storeAI r2 => rfp, 24
L30: 
L11: loadAI rfp, 24 => r3
L12: loadI 2 => r4
L13: cmp_EQ r3, r4 => r5
L20: i2i r5 => r9
L21: cbr r9 => L19, L18
L19: 
L14: loadAI rfp, 16 => r6
L15: loadI 5 => r7
L16: cmp_GT r6, r7 => r8
L17: and r5, r8 => r9
L18: 
L33: cbr r9 => L31, L32
L31: 
L22: loadAI rfp, 16 => r10
L23: loadI 1 => r11
L24: sub r10, r11 => r12
L25: storeAI r12 => rfp, 16
L26: loadAI rfp, 20 => r13
L27: loadI 1 => r14
L28: add r13, r14 => r15
L29: storeAI r15 => rfp, 20
L34: jumpI  => L30
L32: 
L35: loadAI rfp, 20 => r16
L36: storeAI r16 => rfp, 4
L37: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L42:
	movl	(null)(%), %RBP
.L41:
	movl	(null)(%), %rsp
.L40:
	movl	(null)(%), %rip
.L39:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L38:
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
.L30:
.L11:
	movl	24(%RBP), %eax
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
	jne	.(null)
.L21:
.L19:
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
	cmpl	%edx, %eax
	jle	.(null)
.L18:
.L33:
.L31:
.L22:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L24:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	subl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L25:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L26:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L27:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L28:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L29:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L34:
	jmp	.L30
.L32:
.L35:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L36:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L37:
	leave
	ret

L29: loadI 1024 => rfp
L28: loadI 1024 => rsp
L27: loadI 27 => rbss
L26: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L25: addI rsp, 0 => rsp
L4: loadI 3 => r0
L5: loadI 0 => r2
L6: sub r2, r0 => r1
L7: storeAI r1 => rfp, 16
L8: loadI 2 => r3
L9: storeAI r3 => rfp, 20
L10: loadAI rfp, 16 => r4
L11: loadI 0 => r5
L12: cmp_GT r4, r5 => r6
L20: cbr r6 => L17, L18
L17: 
L13: loadI 3 => r7
L14: storeAI r7 => rfp, 20
L21: jumpI  => L19
L18: 
L15: loadI 4 => r8
L16: storeAI r8 => rfp, 20
L19: 
L22: loadAI rfp, 20 => r9
L23: storeAI r9 => rfp, 4
L24: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L29:
	movl	(null)(%), %RBP
.L28:
	movl	(null)(%), %rsp
.L27:
	movl	(null)(%), %rip
.L26:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L25:
	addq	$0, %rsp
.L4:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	subl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L8:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
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
	cmpl	%edx, %eax
	jle	.L18
.L17:
.L13:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L14:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L21:
	jmp	.L19
.L18:
.L15:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L16:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L19:
.L22:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L24:
	leave
	ret

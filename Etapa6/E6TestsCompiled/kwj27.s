L39: loadI 1024 => rfp
L38: loadI 1024 => rsp
L37: loadI 36 => rbss
L36: jumpI  => L14
L0: halt  => 
L1: i2i rsp => rfp
L13: addI rsp, 0 => rsp
L3: loadAI rfp, 16 => r0
L4: loadAI rfp, 16 => r1
L5: mult r0, r1 => r2
L6: storeAI r2 => rfp, 20
L7: loadAI rfp, 20 => r3
L8: storeAI r3 => rfp, 4
L9: loadAI rfp, 0 => r4
L10: loadAI rfp, 12 => rsp
L11: loadAI rfp, 8 => rfp
L12: jump  => r4
L14: i2i rsp => rfp
L35: addI rsp, 4 => rsp
L17: loadI 3 => r5
L18: storeAI r5 => rfp, 16
L20: storeAI rsp => rsp, 12
L21: storeAI rfp => rsp, 8
L19: loadAI rfp, 16 => r6
L22: storeAI r6 => rsp, 16
L23: addI rpc, 3 => r8
L24: storeAI r8 => rsp, 0
L25: jumpI  => L1
L26: loadAI rsp, 4 => r7
L27: storeAI r7 => rfp, 20
L28: loadAI rfp, 20 => r9
L29: loadAI rfp, 16 => r10
L30: add r9, r10 => r11
L31: storeAI r11 => rfp, 20
L32: loadAI rfp, 20 => r12
L33: storeAI r12 => rfp, 4
L34: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
.L39:
	movl	(null)(%), %RBP
.L38:
	movl	(null)(%), %rsp
.L37:
	movl	(null)(%), %rip
.L36:
	jmp	.L14
.L0:
.L1:
	movq	%rsp, %RBP
.L13:
	addq	$0, %rsp
.L3:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L4:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L7:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L9:
	leave
	ret
.L12:
.L14:
	movq	%rsp, %RBP
.L35:
	addq	$4, %rsp
.L17:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L18:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L20:
.L19:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L23:
.L26:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L27:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L28:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L29:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L30:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L31:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L32:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L33:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L34:
	leave
	ret

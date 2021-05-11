L21: loadI 1024 => rfp
L20: loadI 1024 => rsp
L19: loadI 17 => rbss
L18: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L17: addI rsp, 4 => rsp
L6: loadI 9 => r0
L7: storeAI r0 => rbss, 0
L8: loadI 4 => r1
L9: storeAI r1 => rfp, 24
L10: loadAI rbss, 0 => r2
L11: loadAI rfp, 24 => r3
L12: add r2, r3 => r4
L13: storeAI r4 => rfp, 28
L14: loadAI rfp, 28 => r5
L15: storeAI r5 => rfp, 4
L16: jumpI  => L0
	.file	"programa.c"
	.text
	.comm	z,4
	.globl	main
	.type	main, @function
.L21:
	movl	(null)(%), %RBP
.L20:
	movl	(null)(%), %rsp
.L19:
	movl	(null)(%), %rip
.L18:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L17:
	addq	$4, %rsp
.L6:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, z(%rip)
.L8:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L10:
	movl	z(%rip), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	24(%RBP), %eax
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
	movl	%eax, 28(%RBP)
.L14:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L15:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L16:
	leave
	ret

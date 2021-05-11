L18: loadI 1024 => rfp
L17: loadI 1024 => rsp
L16: loadI 17 => rbss
L15: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L14: addI rsp, 4 => rsp
L3: loadI 10 => r0
L4: storeAI r0 => rbss, 0
L5: loadAI rbss, 0 => r1
L6: storeAI r1 => rfp, 16
L7: loadAI rfp, 16 => r2
L8: loadI 1 => r3
L9: add r2, r3 => r4
L10: storeAI r4 => rfp, 16
L11: loadAI rfp, 16 => r5
L12: storeAI r5 => rfp, 4
L13: jumpI  => L0
	.file	"programa.c"
	.text
	.comm	z,4
	.globl	main
	.type	main, @function
.L18:
	movl	(null)(%), %RBP
.L17:
	movl	(null)(%), %rsp
.L16:
	movl	(null)(%), %rip
.L15:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L14:
	addq	$4, %rsp
.L3:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L4:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, z(%rip)
.L5:
	movl	z(%rip), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L7:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L11:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L12:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L13:
	leave
	ret

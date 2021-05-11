L12: loadI 1024 => rfp
L11: loadI 1024 => rsp
L10: loadI 11 => rbss
L9: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L8: addI rsp, 0 => rsp
L3: loadI 2 => r0
L4: storeAI r0 => rfp, 16
L5: loadAI rfp, 16 => r1
L6: storeAI r1 => rfp, 4
L7: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L12:
	movl	(null)(%), %RBP
.L11:
	movl	(null)(%), %rsp
.L10:
	movl	(null)(%), %rip
.L9:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L8:
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

L17: loadI 1024 => rfp
L16: loadI 1024 => rsp
L15: loadI 17 => rbss
L14: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L13: addI rsp, 16 => rsp
L2: loadI 4 => r0
L3: storeAI r0 => rbss, 4
L4: loadI 9 => r1
L5: storeAI r1 => rbss, 12
L6: loadAI rbss, 12 => r2
L7: loadAI rbss, 4 => r3
L8: add r2, r3 => r4
L9: storeAI r4 => rbss, 8
L10: loadAI rbss, 8 => r5
L11: storeAI r5 => rfp, 4
L12: jumpI  => L0
	.file	"programa.c"
	.text
	.comm	c,4
	.comm	b,4
	.comm	a,4
	.comm	z,4
	.globl	main
	.type	main, @function
.L17:
	movl	(null)(%), %RBP
.L16:
	movl	(null)(%), %rsp
.L15:
	movl	(null)(%), %rip
.L14:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L13:
	addq	$16, %rsp
.L2:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L3:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, b(%rip)
.L4:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, z(%rip)
.L6:
	movl	z(%rip), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	b(%rip), %eax
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
	movl	%eax, a(%rip)
.L10:
	movl	a(%rip), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L12:
	leave
	ret

L20: loadI 1024 => rfp
L19: loadI 1024 => rsp
L18: loadI 19 => rbss
L17: jumpI  => L1
L0: halt  => 
L1: i2i rsp => rfp
L16: addI rsp, 0 => rsp
L3: loadI 2 => r0
L4: loadI 4 => r1
L5: loadI 2 => r2
L6: div r1, r2 => r3
L7: add r0, r3 => r4
L8: loadI 4 => r5
L9: loadI 4 => r6
L10: mult r5, r6 => r7
L11: add r4, r7 => r8
L12: storeAI r8 => rfp, 16
L13: loadAI rfp, 16 => r9
L14: storeAI r9 => rfp, 4
L15: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	main
	.type	main, @function
.L20:
	movl	(null)(%), %RBP
.L19:
	movl	(null)(%), %rsp
.L18:
	movl	(null)(%), %rip
.L17:
	jmp	.L1
.L0:
.L1:
	movq	%rsp, %RBP
.L16:
	addq	$0, %rsp
.L3:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L4:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L6:
	movl	(%rsp), %ebx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	cdq
	idivl	%ebx
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L7:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L8:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L9:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L10:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L11:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
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
	movl	(%rsp), %eax
	addq	$4, %rsp
.L15:
	leave
	ret

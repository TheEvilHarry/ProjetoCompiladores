L94: loadI 1024 => rfp
L93: loadI 1024 => rsp
L92: loadI 86 => rbss
L91: jumpI  => L53
L0: halt  => 
L1: i2i rsp => rfp
L10: addI rsp, 0 => rsp
L2: loadAI rfp, 20 => r0
L3: loadAI rfp, 16 => r1
L4: mult r0, r1 => r2
L5: storeAI r2 => rfp, 4
L6: loadAI rfp, 0 => r3
L7: loadAI rfp, 12 => rsp
L8: loadAI rfp, 8 => rfp
L9: jump  => r3
L11: i2i rsp => rfp
L52: addI rsp, 4 => rsp
L18: storeAI rsp => rsp, 12
L19: storeAI rfp => rsp, 8
L16: loadAI rfp, 28 => r4
L20: storeAI r4 => rsp, 16
L17: loadAI rfp, 24 => r5
L21: storeAI r5 => rsp, 20
L22: addI rpc, 3 => r7
L23: storeAI r7 => rsp, 0
L24: jumpI  => L1
L25: loadAI rsp, 4 => r6
L26: storeAI r6 => rfp, 40
L29: storeAI rsp => rsp, 12
L30: storeAI rfp => rsp, 8
L27: loadAI rfp, 20 => r8
L31: storeAI r8 => rsp, 16
L28: loadAI rfp, 16 => r9
L32: storeAI r9 => rsp, 20
L33: addI rpc, 3 => r11
L34: storeAI r11 => rsp, 0
L35: jumpI  => L1
L36: loadAI rsp, 4 => r10
L37: storeAI r10 => rfp, 44
L38: loadAI rfp, 40 => r12
L39: loadAI rfp, 44 => r13
L40: add r12, r13 => r14
L41: storeAI r14 => rfp, 32
L42: loadAI rfp, 32 => r15
L43: loadI 1 => r16
L44: add r15, r16 => r17
L45: storeAI r17 => rfp, 36
L46: loadAI rfp, 36 => r18
L47: storeAI r18 => rfp, 4
L48: loadAI rfp, 0 => r19
L49: loadAI rfp, 12 => rsp
L50: loadAI rfp, 8 => rfp
L51: jump  => r19
L53: i2i rsp => rfp
L90: addI rsp, 8 => rsp
L58: loadI 2018 => r20
L59: storeAI r20 => rfp, 16
L60: loadI 2 => r21
L61: storeAI r21 => rfp, 24
L62: loadI 2 => r22
L63: storeAI r22 => rfp, 28
L76: storeAI rsp => rsp, 12
L77: storeAI rfp => rsp, 8
L64: loadAI rfp, 24 => r23
L65: loadI 3 => r24
L66: mult r23, r24 => r25
L78: storeAI r25 => rsp, 16
L67: loadAI rfp, 24 => r26
L68: loadI 3 => r27
L69: mult r26, r27 => r28
L79: storeAI r28 => rsp, 20
L70: loadAI rfp, 28 => r29
L71: loadI 2 => r30
L72: mult r29, r30 => r31
L80: storeAI r31 => rsp, 24
L73: loadAI rfp, 28 => r32
L74: loadI 2 => r33
L75: mult r32, r33 => r34
L81: storeAI r34 => rsp, 28
L82: addI rpc, 3 => r36
L83: storeAI r36 => rsp, 0
L84: jumpI  => L11
L85: loadAI rsp, 4 => r35
L86: storeAI r35 => rfp, 20
L87: loadAI rfp, 20 => r37
L88: storeAI r37 => rfp, 4
L89: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
.L94:
	movl	(null)(%), %RBP
.L93:
	movl	(null)(%), %rsp
.L92:
	movl	(null)(%), %rip
.L91:
	jmp	.L53
.L0:
.L1:
	movq	%rsp, %RBP
.L10:
	addq	$0, %rsp
.L2:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L3:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L4:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L5:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L6:
	leave
	ret
.L9:
.L11:
	movq	%rsp, %RBP
.L52:
	addq	$4, %rsp
.L18:
.L16:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L20:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L17:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L21:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L22:
.L25:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L26:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%RBP)
.L29:
.L27:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L31:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L28:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L32:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L33:
.L36:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L37:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 44(%RBP)
.L38:
	movl	40(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L39:
	movl	44(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L40:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L41:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%RBP)
.L42:
	movl	32(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L43:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L44:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L45:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%RBP)
.L46:
	movl	36(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L47:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L48:
	leave
	ret
.L51:
.L53:
	movq	%rsp, %RBP
.L90:
	addq	$8, %rsp
.L58:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L59:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L60:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L61:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L62:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L63:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%RBP)
.L76:
.L64:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L65:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L66:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L78:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L67:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L68:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L69:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L79:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L70:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L71:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L72:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L80:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rsp)
.L73:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L74:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L75:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L81:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rsp)
.L82:
.L85:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L86:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L87:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L88:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L89:
	leave
	ret

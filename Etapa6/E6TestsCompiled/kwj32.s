L104: loadI 1024 => rfp
L103: loadI 1024 => rsp
L102: loadI 98 => rbss
L101: jumpI  => L63
L0: halt  => 
L1: i2i rsp => rfp
L13: addI rsp, 0 => rsp
L3: loadAI rfp, 20 => r0
L4: loadAI rfp, 16 => r1
L5: mult r0, r1 => r2
L6: storeAI r2 => rfp, 24
L7: loadAI rfp, 24 => r3
L8: storeAI r3 => rfp, 4
L9: loadAI rfp, 0 => r4
L10: loadAI rfp, 12 => rsp
L11: loadAI rfp, 8 => rfp
L12: jump  => r4
L14: i2i rsp => rfp
L62: addI rsp, 4 => rsp
L27: storeAI rsp => rsp, 12
L28: storeAI rfp => rsp, 8
L18: storeAI rsp => rsp, 12
L19: storeAI rfp => rsp, 8
L16: loadAI rfp, 28 => r5
L20: storeAI r5 => rsp, 16
L17: loadAI rfp, 28 => r6
L21: storeAI r6 => rsp, 20
L22: addI rpc, 3 => r8
L23: storeAI r8 => rsp, 0
L24: jumpI  => L1
L25: loadAI rsp, 4 => r7
L29: storeAI r7 => rsp, 16
L26: loadAI rfp, 24 => r9
L30: storeAI r9 => rsp, 20
L31: addI rpc, 3 => r11
L32: storeAI r11 => rsp, 0
L33: jumpI  => L1
L34: loadAI rsp, 4 => r10
L46: storeAI rsp => rsp, 12
L47: storeAI rfp => rsp, 8
L35: loadAI rfp, 20 => r12
L48: storeAI r12 => rsp, 16
L38: storeAI rsp => rsp, 12
L39: storeAI rfp => rsp, 8
L36: loadAI rfp, 16 => r13
L40: storeAI r13 => rsp, 16
L37: loadAI rfp, 16 => r14
L41: storeAI r14 => rsp, 20
L42: addI rpc, 3 => r16
L43: storeAI r16 => rsp, 0
L44: jumpI  => L1
L45: loadAI rsp, 4 => r15
L49: storeAI r15 => rsp, 20
L50: addI rpc, 3 => r18
L51: storeAI r18 => rsp, 0
L52: jumpI  => L1
L53: loadAI rsp, 4 => r17
L54: add r10, r17 => r19
L55: storeAI r19 => rfp, 32
L56: loadAI rfp, 32 => r20
L57: storeAI r20 => rfp, 4
L58: loadAI rfp, 0 => r21
L59: loadAI rfp, 12 => rsp
L60: loadAI rfp, 8 => rfp
L61: jump  => r21
L63: i2i rsp => rfp
L100: addI rsp, 8 => rsp
L68: loadI 2019 => r22
L69: storeAI r22 => rfp, 16
L70: loadI 2 => r23
L71: storeAI r23 => rfp, 24
L72: loadI 2 => r24
L73: storeAI r24 => rfp, 28
L86: storeAI rsp => rsp, 12
L87: storeAI rfp => rsp, 8
L74: loadAI rfp, 24 => r25
L75: loadI 3 => r26
L76: mult r25, r26 => r27
L88: storeAI r27 => rsp, 16
L77: loadAI rfp, 24 => r28
L78: loadI 4 => r29
L79: mult r28, r29 => r30
L89: storeAI r30 => rsp, 20
L80: loadAI rfp, 28 => r31
L81: loadI 2 => r32
L82: mult r31, r32 => r33
L90: storeAI r33 => rsp, 24
L83: loadAI rfp, 28 => r34
L84: loadI 2 => r35
L85: mult r34, r35 => r36
L91: storeAI r36 => rsp, 28
L92: addI rpc, 3 => r38
L93: storeAI r38 => rsp, 0
L94: jumpI  => L14
L95: loadAI rsp, 4 => r37
L96: storeAI r37 => rfp, 20
L97: loadAI rfp, 20 => r39
L98: storeAI r39 => rfp, 4
L99: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
.L104:
	movl	(null)(%), %RBP
.L103:
	movl	(null)(%), %rsp
.L102:
	movl	(null)(%), %rip
.L101:
	jmp	.L63
.L0:
.L1:
	movq	%rsp, %RBP
.L13:
	addq	$0, %rsp
.L3:
	movl	20(%RBP), %eax
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
	movl	%eax, 24(%RBP)
.L7:
	movl	24(%RBP), %eax
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
.L62:
	addq	$4, %rsp
.L27:
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
	movl	28(%RBP), %eax
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
.L29:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L26:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L30:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L31:
.L34:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L46:
.L35:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L48:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L38:
.L36:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L40:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L37:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L41:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L42:
.L45:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L49:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L50:
.L53:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L54:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L55:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%RBP)
.L56:
	movl	32(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L57:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L58:
	leave
	ret
.L61:
.L63:
	movq	%rsp, %RBP
.L100:
	addq	$8, %rsp
.L68:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L69:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L70:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L71:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L72:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L73:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%RBP)
.L86:
.L74:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L75:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L76:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L88:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L77:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L78:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L79:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L89:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L80:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L81:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L82:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L90:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rsp)
.L83:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L84:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L85:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L91:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rsp)
.L92:
.L95:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L96:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L97:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L98:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L99:
	leave
	ret

L109: loadI 1024 => rfp
L108: loadI 1024 => rsp
L107: loadI 98 => rbss
L106: jumpI  => L79
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
L78: addI rsp, 4 => rsp
L22: loadAI rfp, 28 => r5
L23: storeAI r5 => rfp, 32
L24: loadAI rfp, 32 => r6
L25: loadI 1 => r7
L26: add r6, r7 => r8
L27: storeAI r8 => rfp, 32
L28: loadAI rfp, 24 => r9
L29: storeAI r9 => rfp, 36
L30: loadAI rfp, 36 => r10
L31: loadI 3 => r11
L32: add r10, r11 => r12
L33: storeAI r12 => rfp, 36
L34: loadAI rfp, 20 => r13
L35: storeAI r13 => rfp, 40
L36: loadAI rfp, 40 => r14
L37: loadI 2 => r15
L38: add r14, r15 => r16
L39: storeAI r16 => rfp, 40
L40: loadAI rfp, 16 => r17
L41: storeAI r17 => rfp, 44
L42: loadAI rfp, 44 => r18
L43: loadI 4 => r19
L44: add r18, r19 => r20
L45: storeAI r20 => rfp, 44
L48: storeAI rsp => rsp, 12
L49: storeAI rfp => rsp, 8
L46: loadAI rfp, 32 => r21
L50: storeAI r21 => rsp, 16
L47: loadAI rfp, 36 => r22
L51: storeAI r22 => rsp, 20
L52: addI rpc, 3 => r24
L53: storeAI r24 => rsp, 0
L54: jumpI  => L1
L55: loadAI rsp, 4 => r23
L56: storeAI r23 => rfp, 48
L59: storeAI rsp => rsp, 12
L60: storeAI rfp => rsp, 8
L57: loadAI rfp, 40 => r25
L61: storeAI r25 => rsp, 16
L58: loadAI rfp, 44 => r26
L62: storeAI r26 => rsp, 20
L63: addI rpc, 3 => r28
L64: storeAI r28 => rsp, 0
L65: jumpI  => L1
L66: loadAI rsp, 4 => r27
L67: storeAI r27 => rfp, 52
L68: loadAI rfp, 48 => r29
L69: loadAI rfp, 52 => r30
L70: add r29, r30 => r31
L71: storeAI r31 => rfp, 56
L72: loadAI rfp, 56 => r32
L73: storeAI r32 => rfp, 4
L74: loadAI rfp, 0 => r33
L75: loadAI rfp, 12 => rsp
L76: loadAI rfp, 8 => rfp
L77: jump  => r33
L79: i2i rsp => rfp
L105: addI rsp, 8 => rsp
L83: loadI 7 => r34
L84: storeAI r34 => rfp, 20
L85: loadI 3 => r35
L86: storeAI r35 => rfp, 24
L91: storeAI rsp => rsp, 12
L92: storeAI rfp => rsp, 8
L87: loadAI rfp, 20 => r36
L93: storeAI r36 => rsp, 16
L88: loadAI rfp, 20 => r37
L94: storeAI r37 => rsp, 20
L89: loadAI rfp, 24 => r38
L95: storeAI r38 => rsp, 24
L90: loadAI rfp, 24 => r39
L96: storeAI r39 => rsp, 28
L97: addI rpc, 3 => r41
L98: storeAI r41 => rsp, 0
L99: jumpI  => L14
L100: loadAI rsp, 4 => r40
L101: storeAI r40 => rfp, 16
L102: loadAI rfp, 16 => r42
L103: storeAI r42 => rfp, 4
L104: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
.L109:
	movl	(null)(%), %RBP
.L108:
	movl	(null)(%), %rsp
.L107:
	movl	(null)(%), %rip
.L106:
	jmp	.L79
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
.L78:
	addq	$4, %rsp
.L22:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%RBP)
.L24:
	movl	32(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L25:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L26:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L27:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%RBP)
.L28:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L29:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%RBP)
.L30:
	movl	36(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L31:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L32:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L33:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%RBP)
.L34:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L35:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%RBP)
.L36:
	movl	40(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L37:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L38:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L39:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%RBP)
.L40:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L41:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 44(%RBP)
.L42:
	movl	44(%RBP), %eax
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
	movl	%eax, 44(%RBP)
.L48:
.L46:
	movl	32(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L50:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L47:
	movl	36(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L51:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L52:
.L55:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L56:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 48(%RBP)
.L59:
.L57:
	movl	40(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L61:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L58:
	movl	44(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L62:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L63:
.L66:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L67:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 52(%RBP)
.L68:
	movl	48(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L69:
	movl	52(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L70:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L71:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 56(%RBP)
.L72:
	movl	56(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L73:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L74:
	leave
	ret
.L77:
.L79:
	movq	%rsp, %RBP
.L105:
	addq	$8, %rsp
.L83:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L84:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L85:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L86:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L91:
.L87:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L93:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L88:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L94:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L89:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L95:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rsp)
.L90:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L96:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rsp)
.L97:
.L100:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L101:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L102:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L103:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L104:
	leave
	ret

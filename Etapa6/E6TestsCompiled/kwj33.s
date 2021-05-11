L110: loadI 1024 => rfp
L109: loadI 1024 => rsp
L108: loadI 102 => rbss
L107: jumpI  => L69
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
L68: addI rsp, 4 => rsp
L20: storeAI rsp => rsp, 12
L21: storeAI rfp => rsp, 8
L18: loadAI rfp, 28 => r5
L22: storeAI r5 => rsp, 16
L19: loadAI rfp, 28 => r6
L23: storeAI r6 => rsp, 20
L24: addI rpc, 3 => r8
L25: storeAI r8 => rsp, 0
L26: jumpI  => L1
L27: loadAI rsp, 4 => r7
L28: storeAI r7 => rfp, 36
L31: storeAI rsp => rsp, 12
L32: storeAI rfp => rsp, 8
L29: loadAI rfp, 16 => r9
L33: storeAI r9 => rsp, 16
L30: loadAI rfp, 16 => r10
L34: storeAI r10 => rsp, 20
L35: addI rpc, 3 => r12
L36: storeAI r12 => rsp, 0
L37: jumpI  => L1
L38: loadAI rsp, 4 => r11
L39: storeAI r11 => rfp, 40
L42: storeAI rsp => rsp, 12
L43: storeAI rfp => rsp, 8
L40: loadAI rfp, 36 => r13
L44: storeAI r13 => rsp, 16
L41: loadAI rfp, 24 => r14
L45: storeAI r14 => rsp, 20
L46: addI rpc, 3 => r16
L47: storeAI r16 => rsp, 0
L48: jumpI  => L1
L49: loadAI rsp, 4 => r15
L52: storeAI rsp => rsp, 12
L53: storeAI rfp => rsp, 8
L50: loadAI rfp, 20 => r17
L54: storeAI r17 => rsp, 16
L51: loadAI rfp, 40 => r18
L55: storeAI r18 => rsp, 20
L56: addI rpc, 3 => r20
L57: storeAI r20 => rsp, 0
L58: jumpI  => L1
L59: loadAI rsp, 4 => r19
L60: add r15, r19 => r21
L61: storeAI r21 => rfp, 32
L62: loadAI rfp, 32 => r22
L63: storeAI r22 => rfp, 4
L64: loadAI rfp, 0 => r23
L65: loadAI rfp, 12 => rsp
L66: loadAI rfp, 8 => rfp
L67: jump  => r23
L69: i2i rsp => rfp
L106: addI rsp, 8 => rsp
L74: loadI 2019 => r24
L75: storeAI r24 => rfp, 16
L76: loadI 2 => r25
L77: storeAI r25 => rfp, 24
L78: loadI 2 => r26
L79: storeAI r26 => rfp, 28
L92: storeAI rsp => rsp, 12
L93: storeAI rfp => rsp, 8
L80: loadAI rfp, 24 => r27
L81: loadI 3 => r28
L82: mult r27, r28 => r29
L94: storeAI r29 => rsp, 16
L83: loadAI rfp, 24 => r30
L84: loadI 4 => r31
L85: mult r30, r31 => r32
L95: storeAI r32 => rsp, 20
L86: loadAI rfp, 28 => r33
L87: loadI 2 => r34
L88: mult r33, r34 => r35
L96: storeAI r35 => rsp, 24
L89: loadAI rfp, 28 => r36
L90: loadI 2 => r37
L91: mult r36, r37 => r38
L97: storeAI r38 => rsp, 28
L98: addI rpc, 3 => r40
L99: storeAI r40 => rsp, 0
L100: jumpI  => L14
L101: loadAI rsp, 4 => r39
L102: storeAI r39 => rfp, 20
L103: loadAI rfp, 20 => r41
L104: storeAI r41 => rfp, 4
L105: jumpI  => L0
	.file	"programa.c"
	.text
	.globl	f
	.type	f, @function
	.globl	mult
	.type	mult, @function
	.globl	main
	.type	main, @function
.L110:
	movl	(null)(%), %RBP
.L109:
	movl	(null)(%), %rsp
.L108:
	movl	(null)(%), %rip
.L107:
	jmp	.L69
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
.L68:
	addq	$4, %rsp
.L20:
.L18:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L22:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L19:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L23:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L24:
.L27:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L28:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 36(%RBP)
.L31:
.L29:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L33:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L30:
	movl	16(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L34:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L35:
.L38:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L39:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 40(%RBP)
.L42:
.L40:
	movl	36(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L44:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L41:
	movl	24(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L45:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L46:
.L49:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L52:
.L50:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L54:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L51:
	movl	40(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L55:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L56:
.L59:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L60:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	addl	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L61:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 32(%RBP)
.L62:
	movl	32(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L63:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L64:
	leave
	ret
.L67:
.L69:
	movq	%rsp, %RBP
.L106:
	addq	$8, %rsp
.L74:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L75:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%RBP)
.L76:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L77:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%RBP)
.L78:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L79:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%RBP)
.L92:
.L80:
	movl	24(%RBP), %eax
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
.L94:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 16(%rsp)
.L83:
	movl	24(%RBP), %eax
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
.L95:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%rsp)
.L86:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L87:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L88:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L96:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 24(%rsp)
.L89:
	movl	28(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L90:
	movl	(null)(%), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L91:
	movl	(%rsp), %edx
	addq	$4, %rsp
	movl	(%rsp), %eax
	addq	$4, %rsp
	imull	%edx, %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L97:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 28(%rsp)
.L98:
.L101:
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L102:
	movl	(%rsp), %eax
	addq	$4, %rsp
	movl	%eax, 20(%RBP)
.L103:
	movl	20(%RBP), %eax
	subq	$4, %rsp
	movl	%eax, (%rsp)
.L104:
	movl	(%rsp), %eax
	addq	$4, %rsp
.L105:
	leave
	ret

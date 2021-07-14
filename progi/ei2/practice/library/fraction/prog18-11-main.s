	.file	"prog18-11-main.c"
	.text
	.section	.rodata
.LC0:
	.string	"a: "
.LC1:
	.string	"b: "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$791293227, -33(%rbp)
	movb	$0, -29(%rbp)
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	call	getFraction
	movq	%rax, -12(%rbp)
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	call	getFraction
	movq	%rax, -20(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	movzbl	-33(%rbp,%rax), %eax
	movsbl	%al, %eax
	movq	-20(%rbp), %rdx
	movq	-12(%rbp), %rcx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	frcPrintOperation
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cltq
	movzbl	-33(%rbp,%rax), %eax
	testb	%al, %al
	jne	.L3
	movl	$10, %edi
	call	putchar
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.string	"%c: \346\274\224\347\256\227\345\255\220\343\201\214\344\270\215\346\255\243\343\201\247\343\201\231\343\200\202\n"
.LC3:
	.string	" %c "
.LC4:
	.string	" = "
	.text
	.globl	frcPrintOperation
	.type	frcPrintOperation, @function
frcPrintOperation:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, %eax
	movq	%rsi, -28(%rbp)
	movq	%rdx, -36(%rbp)
	movb	%al, -20(%rbp)
	movsbl	-20(%rbp), %eax
	cmpl	$43, %eax
	je	.L6
	cmpl	$43, %eax
	jg	.L7
	cmpl	$42, %eax
	je	.L8
	jmp	.L9
.L7:
	cmpl	$45, %eax
	je	.L10
	cmpl	$47, %eax
	je	.L11
	jmp	.L9
.L6:
	movq	-36(%rbp), %rdx
	movq	-28(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	frcAdd
	movq	%rax, -8(%rbp)
	jmp	.L12
.L10:
	movq	-36(%rbp), %rdx
	movq	-28(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	frcSub
	movq	%rax, -8(%rbp)
	jmp	.L12
.L8:
	movq	-36(%rbp), %rdx
	movq	-28(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	frcMul
	movq	%rax, -8(%rbp)
	jmp	.L12
.L11:
	movq	-36(%rbp), %rdx
	movq	-28(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	frcDiv
	movq	%rax, -8(%rbp)
	jmp	.L12
.L9:
	movsbl	-20(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L5
.L12:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	frcReduction
	movq	%rax, -8(%rbp)
	movq	-28(%rbp), %rax
	movq	%rax, %rdi
	call	frcPrint
	movsbl	-20(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movq	-36(%rbp), %rax
	movq	%rax, %rdi
	call	frcPrint
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	frcPrint
	movl	$10, %edi
	call	putchar
	nop
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	frcPrintOperation, .-frcPrintOperation
	.ident	"GCC: (GNU) 8.4.1 20200928 (Red Hat 8.4.1-1)"
	.section	.note.GNU-stack,"",@progbits

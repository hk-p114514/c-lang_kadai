	.file	"date.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d/%d/%d"
	.text
	.globl	getDate
	.type	getDate, @function
getDate:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	stdin(%rip), %rdx
	leaq	-27(%rbp), %rax
	movl	$15, %esi
	movq	%rax, %rdi
	call	fgets
	leaq	-40(%rbp), %rax
	leaq	8(%rax), %rsi
	leaq	-40(%rbp), %rax
	leaq	4(%rax), %rcx
	leaq	-40(%rbp), %rdx
	leaq	-27(%rbp), %rax
	movq	%rsi, %r8
	movl	$.LC0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf
	movq	-40(%rbp), %rax
	movq	%rax, -12(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, -4(%rbp)
	movq	-12(%rbp), %rax
	movl	-4(%rbp), %ecx
	movq	%rcx, %rdx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	getDate, .-getDate
	.section	.rodata
.LC1:
	.string	"%4d/%02d/%02d"
	.text
	.globl	printDate
	.type	printDate, @function
printDate:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, %rdx
	movl	%esi, %eax
	movq	%rdx, -16(%rbp)
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	printDate, .-printDate
	.globl	laterDate
	.type	laterDate, @function
laterDate:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdx, %rax
	movq	%rcx, %rdx
	movq	%rdi, -32(%rbp)
	movl	%esi, -24(%rbp)
	movq	%rax, -48(%rbp)
	movl	-40(%rbp), %eax
	andl	$0, %eax
	orl	%edx, %eax
	movl	%eax, -40(%rbp)
	movl	-32(%rbp), %edx
	movl	-48(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L6
	movq	-32(%rbp), %rax
	movq	%rax, -12(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L7
.L6:
	movl	-32(%rbp), %edx
	movl	-48(%rbp), %eax
	cmpl	%eax, %edx
	jge	.L8
	movq	-48(%rbp), %rax
	movq	%rax, -12(%rbp)
	movl	-40(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L7
.L8:
	movl	-28(%rbp), %edx
	movl	-44(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L9
	movq	-32(%rbp), %rax
	movq	%rax, -12(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L7
.L9:
	movl	-28(%rbp), %edx
	movl	-44(%rbp), %eax
	cmpl	%eax, %edx
	jge	.L10
	movq	-48(%rbp), %rax
	movq	%rax, -12(%rbp)
	movl	-40(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L7
.L10:
	movl	-24(%rbp), %edx
	movl	-40(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L11
	movq	-32(%rbp), %rax
	movq	%rax, -12(%rbp)
	movl	-24(%rbp), %eax
	movl	%eax, -4(%rbp)
	jmp	.L7
.L11:
	movq	-48(%rbp), %rax
	movq	%rax, -12(%rbp)
	movl	-40(%rbp), %eax
	movl	%eax, -4(%rbp)
.L7:
	movq	-12(%rbp), %rax
	movl	-4(%rbp), %ecx
	movq	%rcx, %rdx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	laterDate, .-laterDate
	.ident	"GCC: (GNU) 8.4.1 20200928 (Red Hat 8.4.1-1)"
	.section	.note.GNU-stack,"",@progbits

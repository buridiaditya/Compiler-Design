	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
	movq	$9, -8(%rbp)
	movq	$18, -16(%rbp)
	movq	$18, -24(%rbp)
	movq	$18, -48(%rbp)
	movq	$1, -72(%rbp)
	movq	$1, -80(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	negq	rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	-8(%rbp), %rdx
	subq	rdx, rax
	movq	rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-8(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-8(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-8(%rbp), %rcx
	cqto
	idivq	rcx
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-8(%rbp), %rcx
	cqto
	idivq	rcx
	movq	%rdx, -8(%rbp)
	movq	-8(%rbp), %rax
	cmpq	%rax, -16(%rbp)
	jg	.L0
	jmp	.L1
.L0:
	movq	-16(%rbp), %rax
	movq	-72(%rbp), %rdx
	subq	rdx, rax
	movq	rax, -16(%rbp)
	jmp	.L2
.L1:
	movq	-16(%rbp), %rax
	movq	-80(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -16(%rbp)
.L2:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	shrq	rdx, rax
	movq	rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	orq	%rdx, %rax
	movq	%rax, -8(%rbp)
.LFE0:
	.size	main, .-main

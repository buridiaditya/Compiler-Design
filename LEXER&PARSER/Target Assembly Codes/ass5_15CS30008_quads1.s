	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$72, %rsp
	movq	$0, -8(%rbp)
	movq	$10, -16(%rbp)
	movq	$10, -24(%rbp)
	movq	$1, -32(%rbp)
	movq	$1, -56(%rbp)
	movq	$1, -72(%rbp)
.L2:
	movq	-8(%rbp), %rax
	cmpq	%rax, -16(%rbp)
	jl	.L0
	jmp	.L1
	movq	-8(%rbp), %rax
	movq	-56(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)
	jmp	.L2
.L0:
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	-64(%rbp), %rdx
	movq	%rdx, (%rax)
.L1:
	addq	$72, %rsp
	movq	-72(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	leave
	ret
.LFE0:
	.size	main, .-main

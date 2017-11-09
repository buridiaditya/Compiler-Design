	.text
	.globl	add
	.type	add, @function
add:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movq	32(%rbp), %rax
	movq	24(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)
	addq	32, %rsp
	movq	-8(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	ret
.LFE0:
	.size	add, .-add
	.globl	main
	.type	main, @function
main:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$104, %rsp
	movq	-8(%rbp), %rax
	pushq	%rax
	movq	-16(%rbp), %rax
	pushq	%rax
	subq	8, %rsp
	call	add
	movq	(%rsp), %rax
	movq	%rax, -24(%rbp)
	addq	$24, %rsp
	movq	-24(%rbp), %rax
	cmpq	%rax, -32(%rbp)
	jl	.L0
	jmp	.L1
.L0:
	movq	-24(%rbp), %rax
	movq	-48(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rdx, (%rax)
.L1:
	movq	-24(%rbp), %rax
	cmpq	%rax, -64(%rbp)
	jge	.L2
	jmp	.L3
.L2:
	movq	-24(%rbp), %rax
	movq	-80(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rdx, (%rax)
.L3:
	addq	104, %rsp
	movq	-96(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	ret
.LFE1:
	.size	main, .-main

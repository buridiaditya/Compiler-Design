	.text
	.globl	fib
	.type	fib, @function
fib:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$80, %rsp
	movq	$1, -8(%rbp)
	movq	$0, -24(%rbp)
	movq	$1, -32(%rbp)
	movq	$2, -48(%rbp)
	movq	24(%rbp), %rax
	cmpq	%rax, -8(%rbp)
	jle	.L0
	jmp	.L1
.L0:
	addq	$80, %rsp
	movq	-24(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	leave
	ret
.L1:
	movq	24(%rbp), %rax
	movq	-32(%rbp), %rdx
	subq	%rdx, %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	pushq	%rax
	movq	24(%rbp), %rax
	movq	-48(%rbp), %rdx
	subq	%rdx, %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	pushq	%rax
	subq	$8, %rsp
	call	fib
	movq	(%rsp), %rax
	movq	%rax, -64(%rbp)
	addq	$16, %rsp
	subq	$8, %rsp
	call	fib
	movq	(%rsp), %rax
	movq	%rax, -72(%rbp)
	addq	$16, %rsp
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -80(%rbp)
	addq	$80, %rsp
	movq	-80(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	leave
	ret
.LFE0:
	.size	fib, .-fib
	.globl	mul
	.type	mul, @function
mul:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp
	movq	32(%rbp), %rax
	movq	24(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, -8(%rbp)
	addq	$8, %rsp
	movq	-8(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	leave
	ret
.LFE1:
	.size	mul, .-mul
	.globl	main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$104, %rsp
	movq	$3, -8(%rbp)
	movq	$4, -16(%rbp)
	movq	$1, -32(%rbp)
	movq	$1, -48(%rbp)
	movq	$0, -104(%rbp)
	movq	-8(%rbp), %rax
	pushq	%rax
	movq	-16(%rbp), %rax
	pushq	%rax
	movq	-16(%rbp), %rax
	pushq	%rax
	movq	8(%rbp), %rax
	pushq	%rax
	subq	$8, %rsp
	call	mul
	movq	(%rsp), %rax
	movq	%rax, -24(%rbp)
	addq	$24, %rsp
	movq	-24(%rbp), %rax
	movq	-32(%rbp), %rdx
	subq	%rdx, %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
	pushq	%rax
	movq	-24(%rbp), %rax
	movq	-48(%rbp), %rdx
	subq	%rdx, %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	pushq	%rax
	movq	8(%rbp), %rax
	pushq	%rax
	subq	$8, %rsp
	call	fib
	movq	(%rsp), %rax
	movq	%rax, -64(%rbp)
	addq	$16, %rsp
	subq	$8, %rsp
	call	fib
	movq	(%rsp), %rax
	movq	%rax, -72(%rbp)
	addq	$16, %rsp
	movq	-64(%rbp), %rax
	movq	-72(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, -88(%rbp)
	movq	-88(%rbp), %rax
	movq	-80(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-88(%rbp), %rax
	pushq	%rax
	subq	$8, %rsp
	call	fib
	movq	(%rsp), %rax
	movq	%rax, -96(%rbp)
	addq	$16, %rsp
	addq	$104, %rsp
	movq	-104(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	leave
	ret
.LFE2:
	.size	main, .-main

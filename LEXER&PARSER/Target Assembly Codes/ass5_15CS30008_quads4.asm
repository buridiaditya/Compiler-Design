	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$112, %rsp
	movq	$9, -8(%rbp)
	movq	$8, -16(%rbp)
	movq	$11, -24(%rbp)
	movq	$2, -32(%rbp)
	movq	$2, -48(%rbp)
	movq	$0, -104(%rbp)
	movq	$27, -112(%rbp)
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	shlq	$0, %rax
	movq	%rax, -40(%rbp)
	movq	-8(%rbp), %rax
	movq	-48(%rbp), %rdx
	shrq	$0, %rax
	movq	%rax, -56(%rbp)
	movq	-40(%rbp), %rax
	movq	-56(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	-64(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, -72(%rbp)
	movq	-8(%rbp), %rax
	movq	-72(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -80(%rbp)
	movq	-80(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	-80(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, -88(%rbp)
	movq	-8(%rbp), %rax
	movq	-88(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	-96(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	subq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	-104(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -24(%rbp)
	movq	-104(%rbp), %rax
	movq	-104(%rbp), %rdx
	imulq	%rdx, %rax
	movq	%rax, -104(%rbp)
	movq	-112(%rbp), %rax
	movq	-8(%rbp), %rcx
	cqto
	idivq	%rcx
	movq	%rax, -112(%rbp)
	movq	-112(%rbp), %rax
	movq	-112(%rbp), %rcx
	cqto
	idivq	%rcx
	movq	%rdx, -112(%rbp)
	addq	$112, %rsp
	popq	%rbp
	ret
.LFE0:
	.size	main, .-main

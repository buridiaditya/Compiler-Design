	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$24, %rsp
	movq	$10, -8(%rbp)
	movq	$20, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	addq	$24, %rsp
	movq	-8(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	leave
	ret
.LFE0:
	.size	main, .-main

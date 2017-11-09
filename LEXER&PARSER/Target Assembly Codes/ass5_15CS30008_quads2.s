	.text
	.globl	add
	.type	add, @function
add:
.LFB1:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$8, %rsp
	movq	32(%rbp), %rax
	movq	24(%rbp), %rdx
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)
	addq	$8, %rsp
	movq	-8(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	leave
	ret
.LFE0:
	.size	add, .-add
	.globl	main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$40, %rsp
	movq	$9, -8(%rbp)
	movq	$18, -16(%rbp)
	movq	-8(%rbp), %rax
	pushq	%rax
	movq	-16(%rbp), %rax
	pushq	%rax
	subq	$8, %rsp
	call	add
	movq	(%rsp), %rax
	movq	%rax, -24(%rbp)
	addq	$24, %rsp
	movq	-8(%rbp), %rax
	pushq	%rax
	subq	$8, %rsp
	call	printInt
	movq	(%rsp), %rax
	movq	%rax, -8(%rbp)
	addq	$16, %rsp
	addq	$40, %rsp
	movq	-40(%rbp), %rax
	movq	%rax, 16(%rbp)
	popq	%rbp
	leave
	ret
.LFE1:
	.size	main, .-main

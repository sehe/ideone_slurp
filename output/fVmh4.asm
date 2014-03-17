// error:	OK
// langId:	45
// langName:	Assembler
// langVersion:	gcc-4.8.1
// time:	0
// date:	2012-02-29 03:02:45
// status:	0
// result:	11
// memory:	0
// signal:	0
// public:	false
// ------------------------------------------------
	.file	"test.cpp"
	.section	.text._Z3fooIiEiv,"axG",@progbits,_Z3fooIiEiv,comdat
	.p2align 4,,15
	.weak	_Z3fooIiEiv
	.type	_Z3fooIiEiv, @function
_Z3fooIiEiv:
.LFB2:
	.cfi_startproc
	movl	$42, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	_Z3fooIiEiv, .-_Z3fooIiEiv
	.section	.text._Z3fooIjEiv,"axG",@progbits,_Z3fooIjEiv,comdat
	.p2align 4,,15
	.weak	_Z3fooIjEiv
	.type	_Z3fooIjEiv, @function
_Z3fooIjEiv:
.LFB3:
	.cfi_startproc
	movl	$42, %eax
	ret
	.cfi_endproc
.LFE3:
	.size	_Z3fooIjEiv, .-_Z3fooIjEiv
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	movl	$_Z3fooIiEiv, %eax
	cmpq	$_Z3fooIjEiv, %rax
	setne	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.6.0-3~ppa1) 4.6.1 20110409 (prerelease)"
	.section	.note.GNU-stack,"",@progbits

// ------------------------------------------------
#if 0 // stdin

#endif
#if 0 // stdout

#endif
#if 0 // stderr

#endif
#if 0 // cmpinfo
prog.s: Assembler messages:
prog.s:34: Error: bad register name `%rax'

#endif

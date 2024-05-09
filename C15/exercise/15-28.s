	.file	"15-28.cpp"
	.text
	.section	.text$_ZN1XD2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1XD2Ev
	.def	_ZN1XD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1XD2Ev
_ZN1XD2Ev:
.LFB1:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV1X(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN1XD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1XD1Ev
	.def	_ZN1XD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1XD1Ev
_ZN1XD1Ev:
.LFB2:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV1X(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN1XD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1XD0Ev
	.def	_ZN1XD0Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1XD0Ev
_ZN1XD0Ev:
.LFB3:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	call	_ZN1XD1Ev
	movl	$8, %edx
	movq	16(%rbp), %rcx
	call	_ZdlPvy
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	16+_ZTV1Y(%rip), %rax
	movq	%rax, -8(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN1YD1Ev
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZTV1Y
	.section	.rdata$_ZTV1Y,"dr"
	.linkonce same_size
	.align 8
_ZTV1Y:
	.quad	0
	.quad	_ZTI1Y
	.quad	_ZN1YD1Ev
	.quad	_ZN1YD0Ev
	.section	.text$_ZN1YD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1YD1Ev
	.def	_ZN1YD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1YD1Ev
_ZN1YD1Ev:
.LFB13:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV1Y(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN1XD2Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN1YD0Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1YD0Ev
	.def	_ZN1YD0Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1YD0Ev
_ZN1YD0Ev:
.LFB14:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	call	_ZN1YD1Ev
	movl	$8, %edx
	movq	16(%rbp), %rcx
	call	_ZdlPvy
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZTV1X
	.section	.rdata$_ZTV1X,"dr"
	.linkonce same_size
	.align 8
_ZTV1X:
	.quad	0
	.quad	_ZTI1X
	.quad	_ZN1XD1Ev
	.quad	_ZN1XD0Ev
	.globl	_ZTI1Y
	.section	.rdata$_ZTI1Y,"dr"
	.linkonce same_size
	.align 8
_ZTI1Y:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS1Y
	.quad	_ZTI1X
	.globl	_ZTS1Y
	.section	.rdata$_ZTS1Y,"dr"
	.linkonce same_size
_ZTS1Y:
	.ascii "1Y\0"
	.globl	_ZTI1X
	.section	.rdata$_ZTI1X,"dr"
	.linkonce same_size
	.align 8
_ZTI1X:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS1X
	.globl	_ZTS1X
	.section	.rdata$_ZTS1X,"dr"
	.linkonce same_size
_ZTS1X:
	.ascii "1X\0"
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef

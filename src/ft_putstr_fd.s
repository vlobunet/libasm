%define CHAR		rbp+4
%define FD			rbp+8
%define CALL(n)		0x2000000 | n
%define WRITE		4
%define READ		3

global	_ft_putstr_fd
extern	_ft_strlen

section	.text

_ft_putstr_fd:
	push	rdi
	call	_ft_strlen

	mov		rdx, rax
	mov		rdi, rsi
	pop		rsi
	mov		rax, CALL(WRITE)
	syscall

	ret
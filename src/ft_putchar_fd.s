%define CALL(n)		0x2000000 | n
%define WRITE		4

global	_ft_putchar_fd

section	.text

_ft_putchar_fd:
	push	rdi

	mov		rdx, 1					; указываем размер массива
	mov		rdi, rsi				; [FD]
	mov		rsi, rsp				; [CHAR]
	mov		rax, CALL(WRITE)
	syscall

	pop		rax
	ret
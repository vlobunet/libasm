section	.text
	global	_ft_isprint

_ft_isprint:
	push	rbp         ; сохраняем указатель в стеке
	mov		rbp, rsp    ; устанавливаем вершину стека

	cmp		rdi, 32		; сравниваем символ с spase
	jl		_ko			; выходим с ошибкой
	cmp		rdi, 127	; иначе сравниваем с ~
	jle		_ok			; если меньше ~ то выходим без ошибки
	jmp		_ko			; иначе ошибка

_ko:
	xor		rax, rax	; 0

	mov     rsp, rbp    ; leave
	pop     rbp 
	ret					; rax

_ok:
	mov		rax, 1		; 1

	mov     rsp, rbp    ; leave
	pop     rbp 
	ret					; rax
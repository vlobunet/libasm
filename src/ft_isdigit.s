section	.text
	global	_ft_isdigit

_ft_isdigit:
	push	rbp         ; сохраняем указатель в стеке
	mov		rbp, rsp    ; устанавливаем вершину стека
	cmp		rdi, 48		; сравниваем символ с 0
	jl		_ko			; выходим с ошибкой
	cmp		rdi, 57		; иначе сравниваем с 9
	jle		_ok			; если меньше 9 то выходим без ошибки
	jmp		_ko			; иначе ошибка

_ko:
	xor		rax, rax	; 0
	mov     rsp, rbp    ; leave
	pop     rbp 
	ret					; return rax

_ok:
	mov		rax, 1		; initialize rax to 1
	mov     rsp, rbp    ; leave
	pop     rbp 
	ret					; return rax
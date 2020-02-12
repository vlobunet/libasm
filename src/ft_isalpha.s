
; <==== KO ====> 'A' <=== OK ===> 'Z' <==== KO ====> 'a' <=== OK ===> 'z' <==== KO ====>

section	.text
	global	_ft_isalpha

_ft_isalpha:
	push	rbp         ; сохраняем указатель в стеке
	mov		rbp, rsp    ; устанавливаем вершину стека

	cmp		rdi, 'A'	; сравниваем символ с А
	jl		_ko			; выходим с ошибкой
	cmp		rdi, 'Z'	; иначе сравниваем с Z
	jle		_ok			; если меньше Z то выходим без ошибки
	cmp		rdi, 'a'	; иначе если меньше чем a
	jl		_ko			; выходим с ошибкой
	cmp		rdi, 'z'	; иначе сравниваем с 'z'
	jle		_ok			; выходим без ошибки
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
section	.text
	global	_ft_tolower

_ft_tolower:
	push	rbp         ; сохраняем указатель в стеке
	mov		rbp, rsp    ; устанавливаем вершину стека

	cmp		rdi, 'A'
	jl		_ret
	cmp		rdi, 'Z'
	jle		_tolower
	jmp		_ret

_tolower:
	add		rdi, 32
	jmp		_ret
_ret:
	mov		rax, rdi
	mov     rsp, rbp    ; leave
	pop     rbp 
	ret					; rax
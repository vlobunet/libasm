section	.text
	global	_ft_toupper

_ft_toupper:
	push	rbp         ; сохраняем указатель в стеке
	mov		rbp, rsp    ; устанавливаем вершину стека

	cmp		rdi, 'a'
	jl		_ret
	cmp		rdi, 'z'
	jle		_toupper
	jmp		_ret

_toupper:
	sub		rdi, 32
	jmp		_ret
_ret:
	mov		rax, rdi
	mov     rsp, rbp    ; leave
	pop     rbp 
	ret					; rax
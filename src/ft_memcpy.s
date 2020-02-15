section .text
    global  _ft_memcpy

_ft_memcpy:
	push	rbp
	mov		rbp, rsp

	push	rdi
	mov		rcx, rdx	; устанавливаем счетчик на rdx
	cld					; направление
	rep		movsb		; repeat 
	pop		rax

	mov		rsp, rbp	; leave
	pop		rbp 
	ret					; rax
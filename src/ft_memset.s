section .text
	global _ft_memset

_ft_memset:
	push	rbp
	mov		rbp, rsp

	mov		rcx, rdx
	mov		rdx, rdi	;backup 1st arg
	mov		ax, si		;setting the source char in al
	rep stosb
	mov		rax, rdx	;return 1st arg

	mov		rsp, rbp	; leave
	pop		rbp 
	ret					; rax
section .text
	global  _ft_isalnum
	extern  _ft_isalpha
	extern  _ft_isdigit

_ft_isalnum:
		push	rbp
		mov		rbp, rsp

		call	_ft_isalpha 
		cmp		rax, 0
		jne		_ret 
		call	_ft_isdigit
		cmp		rax, 0x0
		jne		_ret

_ret:
		mov     rsp, rbp
		pop     rbp
		ret
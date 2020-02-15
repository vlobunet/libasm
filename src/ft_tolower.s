;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_tolower.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:30:32 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:30:33 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

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

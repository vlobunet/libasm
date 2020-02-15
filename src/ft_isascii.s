;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_isascii.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:24:33 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:24:35 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

;<==== OK ====> 0 <==== OK ====> 127 <==== KO ====>

section	.text
	global	_ft_isascii

_ft_isascii:
	push	rbp         ; сохраняем указатель в стеке
	mov		rbp, rsp    ; устанавливаем вершину стека
	cmp		rdi, 0		; сравниваем символ с 0
	jl		_ko			; выходим с ошибкой
	cmp		rdi, 127	; иначе сравниваем с 127
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

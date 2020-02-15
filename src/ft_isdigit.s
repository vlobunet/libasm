;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_isdigit.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:24:49 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:24:51 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

; <==== KO ====> 0 <==== OK ====> 9 <==== KO ====>

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

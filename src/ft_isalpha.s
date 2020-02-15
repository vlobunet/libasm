;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_isalpha.s                                       :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:24:23 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:24:25 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #


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

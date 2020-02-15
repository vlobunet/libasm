;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_memalloc.s                                      :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 16:23:24 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 16:23:26 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

section .text
	global _ft_memalloc
	extern _ft_bzero
	extern _malloc

_ft_memalloc:
	push	rbp
	mov		rbp, rsp

	test	rdi, rdi
	jz		_ret
	push	rdi
	sub		rsp, 8		; для локальной переменной

	call	_malloc	
	test	rax, rax	; усли ошибка выделения памяти
	jz		_ret		; выходим

	add		rsp, 8			; устанавливаем указатель
	pop		rsi
	mov		rdi, rax
	push	rax
	sub		rsp, 8
	call	_ft_bzero
	add		rsp, 8
	pop		rax
	mov		rsp, rbp
	pop		rbp
	ret

_ret:
	mov		rax, 0
	mov		rsp, rbp
	pop		rbp
	ret

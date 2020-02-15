;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_strdup.s                                        :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:29:37 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:29:38 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

section .text
	global _ft_strdup
	extern _ft_strlen
	extern _ft_memcpy
	extern _malloc

_ft_strdup:
	push	rbp			; сохраням в стек адрес возврата
	mov		rbp, rsp	; вершина стека
	push	rdi			; сохраняем rdi
	sub		rsp, 8		; выделяем 8 байт под локальную переменную

	call	_ft_strlen	; определяем размер строки а результат записываем в rax
	add		rsp, 8		; переводим указатель на переменную
	inc		rax			; инкрементируем rax для дополнительного /0
	push	rax			; сохраняем значение в стек
	mov		rdi, rax	; записываем размер нужной памяти в rdi
	call	_malloc		; вызываем malloc
	pop		rdx			; возвращаем размер строки в rdx
	pop		rsi			; возвращаем указатель на вершину стека
	test	rax, rax	; сравниваем с 0
	jz		_return		; если 0 то возвращаем 0
	mov		rdi, rax	; иначе передаем указатель в rdi
	call	_ft_memcpy	; вызываем копирование строки

_return:
	mov     rsp, rbp	; leave
	pop     rbp
	ret					; rax

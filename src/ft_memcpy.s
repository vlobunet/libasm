;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_memcpy.s                                        :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:25:19 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:25:21 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

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

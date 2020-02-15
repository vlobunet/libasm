;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_strlen.s                                        :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:29:49 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:29:51 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

global	_ft_strlen

section	.text

_ft_strlen:
	cmp		rdi, 0x0
	je		_ret_null

_ft_strlen_cnt:
	cmp		rdi, 0x0
	je		_ret
	mov		rax, 0x0
	mov		rcx, -1

	cld
	repnz	scasb

	not		rcx
	lea		rax, [rcx - 1]

_ret:
	ret

_ret_null:
	mov		rax, 0x0
	ret

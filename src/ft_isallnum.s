;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_isallnum.s                                      :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:24:11 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:24:12 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

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

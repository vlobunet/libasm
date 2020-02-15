;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_puts.s                                          :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:26:05 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:26:07 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

section .data
	null_str db "(null)", 0x0

section .text
	extern _ft_putstr_fd
	global _ft_puts

_ft_puts:
	push	rbp
	mov		rbp, rsp
	push	rdi
	cmp		rdi, 0
	jne		_ok
	lea		rdi, [rel null_str]
_ok:
	push	rsi
	mov		rsi, 1
	call	_ft_putstr_fd
	pop		rsi
	push	rax
	push	10
	mov		rdi, rsp
	push	rsi
	mov		rsi, 1
	call	_ft_putstr_fd
	pop		rsi
	pop		rax
	pop		rax
	pop		rdi
	mov     rsp, rbp
	pop     rbp
	ret

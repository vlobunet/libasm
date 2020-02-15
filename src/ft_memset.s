;# **************************************************************************** #
;#                                                                              #
;#                                                         :::      ::::::::    #
;#    ft_memset.s                                        :+:      :+:    :+:    #
;#                                                     +:+ +:+         +:+      #
;#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
;#                                                 +#+#+#+#+#+   +#+            #
;#    Created: 2020/02/15 12:25:30 by vlobunet          #+#    #+#              #
;#    Updated: 2020/02/15 12:25:32 by vlobunet         ###   ########.fr        #
;#                                                                              #
;# **************************************************************************** #

section .text
	global _ft_memset

_ft_memset:
	push	rbp
	mov		rbp, rsp

	mov		rcx, rdx
	mov		rdx, rdi	;backup 1st arg
	mov		ax, si		;setting the source char in al
	rep stosb
	mov		rax, rdx	;return 1st arg

	mov		rsp, rbp	; leave
	pop		rbp 
	ret					; rax

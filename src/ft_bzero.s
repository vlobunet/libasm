section .text
	global  _ft_bzero

_ft_bzero:
	push	rbp             ; сохраням в стек адрес возврата
	mov		rbp, rsp        ; вершина стека
	push	rdi             ; сохраняем значение rdi
	
_loop:
	cmp		rsi, 0          ; сравниваем размер с 0
	jle		_return         ; если 0 то переходим на return
	mov		byte [rdi], 0   ; иначе заполняем массив 0
	inc		rdi             ; переходим к следующему индексу
	dec		rsi             ; уменьшаем требуемо колличество для заполнения
	jmp		_loop           ; повторяем

_return:
	pop     rdi             ; возвращаем rdi из стека
	mov     rax, rdi 
	mov     rsp, rbp        ; leave
	pop     rbp
	ret
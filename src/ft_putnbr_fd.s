section .data
	buff:    dd 10

global  _ft_putnbr_fd
extern  _ft_putchar_fd

section .text

_ft_putnbr_fd:
	push	rbp;
	mov		rbp, rsp;

	mov		rax, rdi		; заносим наше число как целое
	mov		rdx, 0			; ноль в остаче (не обязательно сейчас уточнять это)
	cmp		rax, 0			; сравниваем с нолем
	call	.body			; если значение больше ноля или равно то переходим дальше
	neg		rax				; иначе меняем знак числа
	mov		rcx, 45			; наш символ -
	call	_ft_putchar_fd	; выводим символ
	call	.body			; переходим дальше

.body:
	push	rax				; целое
	push	rdx				; остаток
	xor		rdx, rdx		; обнуление регистра
	div		dword [rel buff]; делим на 10 и записываем езультат в регистры
	test	rax, rax		; после деления я проверяю целое значение на 0
	je		.display		; если после деления имею 0 то перехожу на вывод
	call	.body	; иначе рекурсивно запускаю функцию

.display:
	add 	rdx, '0'
	;lea		rax, [rdx + '0']; получаю ефективный адрес
	mov		rax, rdx
	call	_ft_putchar_fd	; вывожу символ на екран
	pop		rdx				; возвращаю из стека значения регистров
	pop		rax				; которые были занесены
	ret						; выхожу из рекурсии или функции

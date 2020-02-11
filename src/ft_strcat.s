section .text
	global  _ft_strcat

_ft_strcat:
	push    rbp                     ;
	mov     rbp, rsp                ;
	push    rdi                     ; выгружаем в стек rdi
	test    rdi, rdi                ; сравниваем с 0
	jz      _ret                 	; если 0 выходим
	xor     al, al                  ; обнуляем регистр al
	mov     r9, 0                   ; устанавливаем 0
	mov     r10, 0                  ; устанавливаем 0

_loop:
	cmp     byte [rdi + r9], 0    	; если rdi[r9] == 0
	jle     _konkat                 ; переходим в _konkat
	inc     r9                      ; иначе инкрементируем r9
	jmp     _loop                   ; повторяем

_konkat:
	mov     al, byte [rsi + r10]    ; копируем rsi[r10]
	test    al, al                  ; проверяем на 0
	jz      _ret                 	; если 0 то выходим
	mov     byte [rdi + r9], al     ; иначе копируем в rdi[r9]
	inc     r9                      ; инкрементируем r9
	inc     r10                     ; инкрементируем r10
	jmp     _konkat                 ; повторяем

_ret:
	mov     byte [rdi + r9], 0    	; записываем 0 в конец
	pop     rax                     ; возвращаем указатель из стека
	mov     rsp, rbp        		; leave
	pop     rbp
	ret					            ; возвращаем rax
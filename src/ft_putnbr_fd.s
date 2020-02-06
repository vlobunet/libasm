section .data
    const10:    dd 10

global  _ft_putstr_fd
extern  _ft_putchar_fd

section .text

_ft_putnbr_fd:
    push    rax
    push    rdx
    xor     rdx, rdx          ;edx:eax = number
    div     dword [const10]  ;eax = quotient, edx = remainder
    test    rax, rax         ;Is quotient zero?
    je      .l1               ; yes, don't display it
    call    _ft_putnbr_fd     ;Display the quotient

.l1:
    lea rax,[rdx+'0']
    call _ft_putchar_fd  ;Display the remainder
    pop rdx
    pop rax
    ret
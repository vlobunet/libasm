#ifndef ASM_LIBFT_H
# define ASM_LIBFT_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar_fd(const char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(int nb, int fd);
void	ft_bzero (void * s, size_t n);
char    *ft_strcat(char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_puts(const char *s);

#endif

#ifndef ASM_LIBFT_H
# define ASM_LIBFT_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>


//void	ft_putstr_fd(const char *str, int fd);
//void	ft_putstr(const char *str);

void	ft_putchar_fd(const char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
int		ft_strlen(const char *s);

//void	ft_putnbr_fd(intmax_t n, int fd);
//void	ft_putnbr(intmax_t n,);

#endif

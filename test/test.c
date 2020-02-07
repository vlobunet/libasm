#define __FT_putnbr_fd
#define __FT_putstr_fd
#define __FT_putchar_fd
#define __FT_strlen

#include "../includes/asm_libft.h"

int	main(int c, char **v)
{
	int i = -1;
	if (!c || !v || !v[1])
		return (1);

	printf("\n%s : ", "ft_putchar_fd(const char c, int fd)\n");
	while (v[1][++i])
	{
		#ifdef __FT_putchar_fd
			ft_putchar_fd(v[1][i], 2);
		#endif // __FT_putchar_fd
	}
	printf("\n%s :", "ft_putstr_fd(const char *s, int fd)\n");
	#ifdef __FT_putstr_fd
			ft_putstr_fd(v[1], 2);
	#endif // __FT_putstr_fd
	printf("\n%s :", "ft_strlen(const char *s)");
	#ifdef __FT_strlen
			i = ft_strlen(v[2]);
			printf("\nsizeof(\"%s\") = %d", v[1], i);
	#endif // __FT_strlen
	printf("\nft_putnbr_fd(int nb, int fd) :\n");
	#ifndef __FT_putnbr_fd
		ft_putnbr_fd(-1234567890, 1);
	#endif // __FT_putnbr_fd
	return (0);
}

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

	printf("FT_PUTCHAR_FD:\n");
	while (v[1][++i])
	{
		#ifdef __FT_putchar_fd
			ft_putchar_fd(v[1][i], 1);
		#endif
	}
	printf("FT_PUTSTR_FD:\n");
	#ifdef __FT_putstr_fd
			ft_putstr_fd(v[1], 1);
	#endif
	printf("FT_STRLEN\n", );
	#ifdef __FT_strlen
			i = ft_strlen(v[1]);
			printf("sizeof(\"%s\") = %d\n", v[1], i);
	#endif
	printf("FT_PUTNBR_FD\n");
	#ifndef __FT_putnbr_fd
		ft_putnbr_fd(1234567890);
	#endif
	return (0);
}

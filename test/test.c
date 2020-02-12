#define __FT_putnbr_fd
#define __FT_putstr_fd
#define __FT_putchar_fd
#define __FT_strlen
#define __FT_bzero
#define __FT_strcat
#define __FT_isalpha
#define __FT_isdigit
#define __FT_isascii
#define __FT_isprint
#define __FT_isalnum

#include "../includes/asm_libft.h"
#include <stdio.h> 
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

#define C_RED		"\033[01;38;05;196m KO"
#define C_WHITE		"\033[01;38;05;15m"
#define C_YELLOW	"\033[01;38;05;226m OK"
#define C_RESET		"\033[0m"

#define KO write(1, C_RED, sizeof(C_RED));
#define WHITE write(1, C_WHITE, sizeof(C_WHITE));
#define OK write(1, C_YELLOW, sizeof(C_YELLOW));
#define RESET write(1, C_RESET, sizeof(C_RESET));

//====================================== FT_BZERO_TEST ========================
void	test_bzero_1(void)
{
	char	control[10];
	char	subject[] = "123456789";

	bzero(control, 10);
	ft_bzero(subject, 10);

	if (memcmp(subject, control, 10) == 0)
		OK
	else
		KO

	subject[0] = 'a';
	ft_bzero(subject, 0);
	if (strcmp(subject, "a") == 0)
		OK
	else
		KO
	RESET;
}

void	test_bzero_2(void)
{
	char	teststr[20];

	teststr[0] = 'b';
	teststr[1] = 'z';
	teststr[2] = 'e';
	teststr[3] = 'r';
	teststr[4] = 'o';
	teststr[5] = 'b';
	teststr[6] = 'z';
	teststr[7] = 'e';
	teststr[8] = 'r';
	teststr[9] = 'o';
	teststr[10] = 0;
	teststr[11] = 0;
	teststr[12] = 0;
	teststr[13] = 0;
	teststr[14] = 0;
	teststr[15] = 0;
	teststr[16] = 0;
	teststr[17] = 0;
	teststr[18] = 0;
	teststr[19] = 0;

	char	ref_str[20];

	ref_str[0] = 'b';
	ref_str[1] = 'z';
	ref_str[2] = 'e';
	ref_str[3] = 'r';
	ref_str[4] = 'o';
	ref_str[5] = 'b';
	ref_str[6] = 'z';
	ref_str[7] = 'e';
	ref_str[8] = 'r';
	ref_str[9] = 'o';
	ref_str[10] = 0;
	ref_str[11] = 0;
	ref_str[12] = 0;
	ref_str[13] = 0;
	ref_str[14] = 0;
	ref_str[15] = 0;
	ref_str[16] = 0;
	ref_str[17] = 0;
	ref_str[18] = 0;
	ref_str[19] = 0;

	ft_bzero(teststr + 5, (unsigned int) 4);
	bzero(ref_str + 5, (unsigned int) 4);

	
	if (memcmp(teststr, ref_str, 20) == 0)
		OK
	else
		KO
	RESET;
}

void	test_bzero_3(void)
{
	char	teststr[20];
	char	ref_str[20];


	teststr[0] = 'b';
	teststr[1] = 'z';
	teststr[2] = 'e';
	teststr[3] = 'r';
	teststr[4] = 'o';
	teststr[5] = 'b';
	teststr[6] = 'z';
	teststr[7] = 'e';
	teststr[8] = 'r';
	teststr[9] = 'o';
	teststr[10] = '0';
	teststr[11] = '0';
	teststr[12] = '0';
	teststr[13] = '0';
	teststr[14] = '0';
	teststr[15] = '0';
	teststr[16] = '0';
	teststr[17] = '0';
	teststr[18] = '0';
	teststr[19] = 0;


	ref_str[0] = 'b';
	ref_str[1] = 'z';
	ref_str[2] = 'e';
	ref_str[3] = 'r';
	ref_str[4] = 'o';
	ref_str[5] = 'b';
	ref_str[6] = 'z';
	ref_str[7] = 'e';
	ref_str[8] = 'r';
	ref_str[9] = 'o';
	ref_str[10] = '0';
	ref_str[11] = '0';
	ref_str[12] = '0';
	ref_str[13] = '0';
	ref_str[14] = '0';
	ref_str[15] = '0';
	ref_str[16] = '0';
	ref_str[17] = '0';
	ref_str[18] = '0';
	ref_str[19] = 0;

	ft_bzero(teststr, 17);
	bzero(ref_str, 17);

	if (memcmp(teststr, ref_str, 20) == 0)
		OK
	else
		KO
	RESET;
}

void test_bzero_4(void)
{
	char	control1[] = "123456789";
	char	subject1[] = "123456789";

	bzero(control1, 3);
	ft_bzero(subject1, 3);
	if (memcmp(subject1, control1, 10) == 0)
		OK
	else
		KO
	RESET;

}

void	test_bzero(void)
{
	WHITE;
	write(1, "ft_bzero   : ", 13);
	test_bzero_1();
	test_bzero_2();
	test_bzero_3();
	test_bzero_4();
	puts("");
}

//===================================== FT_STRLEN_TEST =========================

static void	test_strlen_1(void)
{
	if (ft_strlen("") == strlen(""))
		OK
	else
		KO
	RESET;
}

static void	test_strlen_2(void)
{
	if (ft_strlen("abcd\0abcd") == strlen("abcd\0abcd"))
		OK
	else
		KO
	RESET;
}

static void	test_strlen_3(void)
{
	if (ft_strlen("123456789123456789123456789123456789123456789") == strlen("123456789123456789123456789123456789123456789"))
		OK
	else
		KO
	RESET;
}

static void	test_strlen_4(void)
{
	if (ft_strlen(0) == 0)
		OK
	else
		KO
	RESET;
}

void	test_strlen(void)
{
	WHITE;
	write(1, "ft_strlen  : ", 12);
	test_strlen_1();
	test_strlen_2();
	test_strlen_3();
	test_strlen_4();
	puts("");
}
//==================================== FT_PUTSTR_FD_TEST =============================

static void test_putstr_1(void)
{
	write(1, "\n\t1. check if string is null : \n", strlen("\n\t1. check if string is null : \n"));
	char	*str = 0;
	write(1, "\t\tstr = 0 => ft_putstr_fd : ", strlen("\t\tstr = 0 => ft_putstr_fd : "));
	ft_putstr_fd(str, 1);
}

static void	test_putstr_2(void)
{
	write(2, "\n\t2. check when string length is equal to 0 : \n", strlen("\n\t2. check when string length is equal to 0 : \n"));
	char	*str = "";
	write(2, "\t\tstr = \"\" => ft_putstr_fd : [", strlen("\t\tstr = \"\" => ft_putstr_fd : ["));
	ft_putstr_fd(str, 2);
	write(2, "]", 2);
}

static void	test_putstr_3(void)
{
	write(1, "\n\t3. print string : \n", strlen("\n\t3. print string : \n"));
	char	*str = "abcabc\0abc\n";
	write(1, "\t\tstr = \"abcabc\\0abc\\n\" => ft_putstr_fd : [", strlen("\t\tstr = \"abcabc\\0abc\\n\" => ft_putstr_fd : ["));
	ft_putstr_fd(str, 1);
	write(1, "]\n", 2);
}

void	test_putstr_fd(void)
{
	WHITE;
	write(1, "ft_putstr_fd  : ", 16);
	test_putstr_1();
	test_putstr_2();
	test_putstr_3();
	RESET;
	puts("");
}
//==================================== FT_PUTCHAR_FD_TEST =============================
void	test_putchar_fd(void)
{
	WHITE;
	write(1, "ft_putchar_fd  : ", 17);
	char *str = strdup("Hello world");
	while (str && *str)
	{
		ft_putchar_fd(*str, 1);
		ft_putchar_fd(*str, 2);
		str++;
	}
	RESET;
	puts("");
}

//=================================== FT_STRCAT_TEST ===============================

void test_strcat_1(void)
{
	char	buf[9];

	bzero(buf, 9);
	ft_strcat(buf, "");
	ft_strcat(buf, "Bon");
	ft_strcat(buf, "j");
	ft_strcat(buf, "our.");
	ft_strcat(buf, "");

	if (strcmp(buf, "Bonjour.") == 0)
		OK
	else
		KO
	RESET;
}

void	test_strcat_2(void)
{
	char	buf1[20];

	bzero(buf1, 20);
	strcpy(buf1, "bzero");
	ft_strcat(buf1, "bzero");
	if (strcmp(buf1, "bzerobzero") == 0)
		OK
	else
		KO
	RESET;	
}

void	test_strcat(void)
{
	WHITE;
	write(1, "ft_strcat  : ", 13);
	test_strcat_1();
	test_strcat_2();
	RESET;
	puts("");
}

//========================================= FT_ISALPHA_TEST =====================
static void	test_isalpha_1(void)
{
	int i = 'a';
	int ok = 1;

	while (i <= 'z')
	{
		if (ft_isalpha(i) == 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;	
}

static void	test_isalpha_2(void)
{
	int i = 'A';
	int ok = 1;

	while (i <= 'Z')
	{
		if (ft_isalpha(i) == 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;
}

static void	test_isalpha_3(void)
{
	int i = 0;
	int ok = 1;

	while (i < 'A')
	{
		if (ft_isalpha(i) != 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;	
}

static void	test_isalpha_4(void)
{
	int i = 123;
	int ok = 1;

	while (i <= 1000)
	{
		if (ft_isalpha(i) != 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;
}

static void	test_isalpha_5(void)
{
	int i = 64;
	int ok = 1;

	while (i >= -1000)
	{
		if (ft_isalpha(i) != 0)
			ok = 0;
		i--;
	}
	if (ok)
		OK
	else
		KO
	RESET;
}

void	test_isalpha(void)
{
	WHITE;
	write(1, "ft_isalpha : ", 13);
	test_isalpha_1();
	test_isalpha_2();
	test_isalpha_3();
	test_isalpha_4();
	test_isalpha_5();
	RESET;
	puts("");
}

//========================================= FT_ISALPHA_TEST =====================

void	test_isdigit_1(void)
{
	int i = '0';
	int ok = 1;

	while (i <= '9')
	{
		if (ft_isdigit(i) == 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;	
}

void	test_isdigit_2(void)
{
	int i = 47;
	int ok = 1;

	while (i >= -1000)
	{
		if (ft_isdigit(i) != 0)
			ok = 0;
		i--;
	}
	if (ok)
		OK
	else
		KO
	RESET;
}

void	test_isdigit_3(void)
{
	int i = 58;
	int ok = 1;

	while (i <= 1000)
	{
		if (ft_isdigit(i) != 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;	
}

void	test_isdigit(void)
{
	WHITE;
	write(1, "ft_isdigit : ", 14);
	test_isdigit_1();
	test_isdigit_2();
	test_isdigit_3();
	RESET;
	puts("");
}

//========================================== FT_ISASCII_TEST ======================
void 	test_isascii_1(void)
{
	int i = 0;
	int ok = 1;

	while (i <= 127)
	{
		if (ft_isascii(i) == 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;	
}

void 	test_isascii_2(void)
{
	int i = -1;
	int ok = 1;

	while (i >= -1000)
	{
		if (ft_isascii(i) != 0)
			ok = 0;
		i--;
	}
	if (ok)
		OK
	else
		KO
	RESET;		
}

void 	test_isascii_3(void)
{
	int i = 128;
	int ok = 1;

	while (i <= 1000)
	{
		if (ft_isascii(i) != 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;		
}

void	test_isascii(void)
{
	WHITE;
	write(1, "ft_isascii : ", 13);
	test_isascii_1();
	test_isascii_2();
	test_isascii_3();
	RESET;
	puts("");
}

//============================= FT_ISALNUM_TEST ==============================
void	test_isalnum_1(void)
{
	int i = 47;
	int ok = 1;

	while (i >= -10000)
	{
		if (ft_isalnum(i) != 0)
			ok = 0;
		i--;
	}
	if (ok)
		OK
	else
		KO
	RESET;		
}

void	test_isalnum_2(void)
{
	int i = '0';
	int ok = 1;

	while (i <= '9')
	{
		if (ft_isalnum(i) == 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;		
}

void	test_isalnum_3(void)
{
	int i = 'A';
	int ok = 1;

	while (i <= 'Z')
	{
		if (ft_isalnum(i) == 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;	
}

void	test_isalnum_4(void)
{
	int i = 123;
	int ok = 1;

	while (i <= 10000)
	{
		if (ft_isalnum(i) != 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;	
}

void	test_isalnum_5(void)
{
	int i = 58;
	int ok = 1;

	while (i <= 64)
	{
		if (ft_isalnum(i) != 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;	
}

void	test_isalnum_6(void)
{
	int i = 91;
	int ok = 1;

	while (i <= 96)
	{
		if (ft_isalnum(i) != 0)
			ok = 0;
		i++;
	}
	if (ok)
		OK
	else
		KO
	RESET;	
}

void	test_isalnum(void)
{
	WHITE;
	write(1, "ft_isalnum : ", 14);
	test_isalnum_1();
	test_isalnum_2();
	test_isalnum_3();
	test_isalnum_4();
	test_isalnum_5();
	test_isalnum_6();
	RESET;
	puts("");
}

int	main(int c, char **v)
{
	if (!c || !v || !v[1])
		;
	printf("================ Part 1 - Simple libc functions =============\n");
	#ifdef __FT_bzero
		test_bzero();
	#endif
	#ifdef __FT_strcat
		test_strcat();
	#endif
	#ifdef __FT_isalpha
		test_isalpha();
	#endif
	#ifdef __FT_isdigit
		test_isdigit();
	#endif
	#ifdef __FT_isascii
		test_isascii();
	#endif
	#ifdef __FT_isalnum
		test_isalnum();
	#endif	
	printf("================ Part 1 - Simple libc functions =============\n");
	#ifdef __FT_strlen
		test_strlen();
	#endif
	printf("================  Part 3 - Cat ==============================\n");

	printf("================  Bonus part ================================\n");	
	#ifdef __FT_putstr_fd
		test_putstr_fd();
	#endif
	#ifdef __FT_putchar_fd
		test_putchar_fd();
	#endif
	#ifdef __FT_isprint_fd
	#endif
	return (0);
}

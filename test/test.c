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
#define __FT_toupper
#define __FT_tolower
#define __FT_puts
#define __FT_memcpy
#define __FT_memset
#define __FT_strdup
#define __FT_cat

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

#define KO write(1, C_RED, sizeof(C_RED))
#define WHITE write(1, C_WHITE, sizeof(C_WHITE));
#define OK write(1, C_YELLOW, sizeof(C_YELLOW))
#define RESET write(1, C_RESET, sizeof(C_RESET));

//====================================== FT_BZERO_TEST ========================
void	test_bzero_1(void)
{
	char	control[10];
	char	subject[] = "123456789";

	bzero(control, 10);
	ft_bzero(subject, 10);

	memcmp(subject, control, 10) == 0 ? OK : KO;
	subject[0] = 'a';
	ft_bzero(subject, 0);
	strcmp(subject, "a") == 0 ? OK : KO;
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

	memcmp(teststr, ref_str, 20) == 0 ? OK : KO;
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

	memcmp(teststr, ref_str, 20) == 0 ? OK : KO;
	RESET;
}

void test_bzero_4(void)
{
	char	control1[] = "123456789";
	char	subject1[] = "123456789";

	bzero(control1, 3);
	ft_bzero(subject1, 3);
	memcmp(subject1, control1, 10) == 0 ? OK : KO;
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
	ft_strlen("") == strlen("") ? OK : KO;
	RESET;
}

static void	test_strlen_2(void)
{
	ft_strlen("abcd\0abcd") == strlen("abcd\0abcd") ? OK : KO;
	RESET;
}

static void	test_strlen_3(void)
{
	ft_strlen("123456789123456789123456789123456789123456789") ==
	strlen("123456789123456789123456789123456789123456789") ? OK : KO;
	RESET;
}

static void	test_strlen_4(void)
{
	ft_strlen(0) == 0 ? OK : KO;
	RESET;
}

void	test_strlen(void)
{
	WHITE;
	write(1, "ft_strlen  : ", 14);
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

	strcmp(buf, "Bonjour.") == 0 ? OK : KO;
	RESET;
}

void	test_strcat_2(void)
{
	char	buf1[20];

	bzero(buf1, 20);
	strcpy(buf1, "bzero");
	ft_strcat(buf1, "bzero");
	strcmp(buf1, "bzerobzero") == 0 ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
	ok ? OK : KO;
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
//======================================== FT_ISPRINT_TEST ======================================

void 	test_isprint_1(void)
{
	int i = 32;
	int ok = 1;

	while (i <= 126)
	{
		if (ft_isprint(i) == 0)
			ok = 0;
		i++;
	}
	ok ? OK : KO;
	RESET;		
}

void 	test_isprint_2(void)
{
	int i = 31;
	int ok = 1;

	while (i >= -1000)
	{
		if (ft_isprint(i) != 0)
			ok = 0;
		i--;
	}
	ok ? OK : KO;
	RESET;	
}

void 	test_isprint_3(void)
{
	int i = 127;
	int ok = 1;

	while (i <= 1000)
	{
		if (ft_isprint(i) != 0)
			ok = 0;
		i++;
	}
	ok ? OK : KO;
	RESET;	
}

void	test_isprint(void)
{
	WHITE;
	write(1, "ft_isprint : ", 14);
	test_isprint_1();
	test_isprint_2();
	test_isprint_3();
	RESET;
	puts("");
}

// ====================================== FT_TOUPPER_TEST ================================
void 	test_toupper_1(void)
{
	int i = 'A';
	int ok = 1;

	while (i <= 'z')
	{
		if (ft_toupper(i) != toupper(i))
			ok = 0;
		i++;
	}
	ok ? OK : KO;
	RESET;		
}

void 	test_toupper_2(void)
{
	int i = -1000;
	int ok = 1;

	while (i <= 1000)
	{
		if (ft_toupper(i) != toupper(i))
			ok = 0;
		i++;
	}
	ok ? OK : KO;
	RESET;		
}

void	test_toupper(void)
{
	WHITE;
	write(1, "ft_toupper : ", 14);
	test_toupper_1();
	test_toupper_2();
	RESET;
	puts("");
}

// ================================== FT_TOLOWER_TEST =======================================
void 	test_tolower_1(void)
{
	int i = 'A';
	int ok = 1;

	while (i <= 'z')
	{
		if (ft_tolower(i) != tolower(i))
			ok = 0;
		i++;
	}
	ok ? OK : KO;
	RESET;		
}

void 	test_tolower_2(void)
{
	int i = -1000;
	int ok = 1;

	while (i <= 1000)
	{
		if (ft_tolower(i) != tolower(i))
			ok = 0;
		i++;
	}
	ok ? OK : KO;
	RESET;
}

void	test_tolower(void)
{
	WHITE;
	write(1, "ft_tolower : ", 14);
	test_tolower_1();
	test_tolower_2();
	RESET;
	puts("");
}

static void test_puts_1(void)
{
	write(1, "\n\t1. check if string is null : \n", strlen("\n\t1. check if string is null : \n"));
	char	*str = 0;
	write(1, "\t\tstr = 0 => ft_puts : ", strlen("\t\tstr = 0 => ft_puts : "));
	ft_puts(str);
}

static void	test_puts_2(void)
{
	write(1, "\n\t2. check when string length is equal to 0 : \n", strlen("\n\t2. check when string length is equal to 0 : \n"));
	char	*str = "";
	write(1, "\t\tstr = \"\" => ft_puts : [", strlen("\t\tstr = \"\" => ft_puts : ["));
	ft_puts(str);
	write(1, "]\n", 2);
}

static void	test_puts_3(void)
{
	write(1, "\n\t3. print string : \n", strlen("\n\t3. print string : \n"));
	char	*str = "abcabc\0abc\n";
	write(1, "\t\tstr = \"abcabc\\0abc\\n\" => ft_puts : [", strlen("\t\tstr = \"abcabc\\0abc\\n\" => ft_puts : ["));
	ft_puts(str);
	write(1, "]\n", 2);
}

void	test_puts(void)
{
	WHITE;
	write(1, "ft_puts    : ", 14);
	test_puts_1();
	test_puts_2();
	test_puts_3();
	RESET;
	puts("");
}
// ================================================ FT_PUTNBR_FD_TEST ===============================
void test_putnbr_fd(void)
{
	WHITE;
	write(1, "ft_putnbr  : \n", 15);
	write(1, "\tft_putnbr_fd(\"-2, 2\")          : ", strlen("\tft_putnbr_fd(\"-2, 2\")          : "));
	ft_putnbr_fd(-2, 2);
	write(1, "\n", 1);
	write(1, "\tft_putnbr_fd(\"2147483647, 2\")  : ", strlen("\tft_putnbr_fd(\"2147483647, 2\")  : "));
	ft_putnbr_fd(2147483647, 2);
	write(1, "\n", 1);
	write(1, "\tft_putnbr_fd(\"1, 2\")           : ", strlen("\tft_putnbr_fd(\"1, 2\")           : "));
	ft_putnbr_fd(1, 2);
	write(1, "\n", 1);
	write(1, "\tft_putnbr_fd(\"2020, 2\")        : ", strlen("\tft_putnbr_fd(\"2020, 2\")        : "));
	ft_putnbr_fd(2020, 2);
	write(1, "\n", 1);
	write(1, "\tft_putnbr_fd(\"-2147483648, 2\") : ", strlen("\tft_putnbr_fd(\"-2147483648, 2\") : "));
	ft_putnbr_fd(-2147483648, 2);
	write(1, "\n", 1);
}
//================================== FT_MEMCPY_TEST =============================================

static void test_memcpy_3(void)
{
	char memcpy_test[][10] = {{"qwerty"}, {"ZXCVB"}, {"asdfg"}};
	char ft_memcpy_test[][10] = {{"qwerty"}, {"ZXCVB"}, {"asdfg"}};
	int j = 0;
	int k = 0;

	memcpy(memcpy_test[2], memcpy_test[2], 3);
	ft_memcpy(ft_memcpy_test[2], ft_memcpy_test[2], 3);
	while (j < 5)
	{
		if (memcpy_test[2][j] != ft_memcpy_test[2][j])
		k++;
		j++;
	}
	j = 0;
	k == 0 ? OK : KO;
	RESET;
}


static void test_memcpy_2(void)
{
	char memcpy_test[][10] = {{"qwerty"}, {"ZXCVB"}, {"asdfg"}};
	char ft_memcpy_test[][10] = {{"qwerty"}, {"ZXCVB"}, {"asdfg"}};
	int j = 0;
	int k = 0;

	memcpy(memcpy_test[1], memcpy_test[1], 3);
	ft_memcpy(ft_memcpy_test[1], ft_memcpy_test[1], 3);
	while (j < 5)
	{
		if (memcpy_test[1][j] != ft_memcpy_test[1][j])
		k++;
		j++;
	}
	j = 0;
	k == 0 ? OK : KO;
	RESET;
}

static void test_memcpy_1(void)
{
	char memcpy_test[][10] = {{"qwerty"}, {"ZXCVB"}, {"asdfg"}};
	char ft_memcpy_test[][10] = {{"qwerty"}, {"ZXCVB"}, {"asdfg"}};
	int j = 0;
	int k = 0;

	memcpy(memcpy_test[0], memcpy_test[0], 3);
	ft_memcpy(ft_memcpy_test[0], ft_memcpy_test[0], 3);
	while (j < 5)
	{
		if (memcpy_test[0][j] != ft_memcpy_test[0][j])
		k++;
		j++;
	}
	j = 0;
	k == 0 ? OK : KO;
	RESET;
}

void	test_memcpy(void)
{
	WHITE;
	write(1, "ft_memcpy  : ", 14);
	test_memcpy_1();
	test_memcpy_2();
	test_memcpy_3();
	RESET;
	puts("");
}
// ======================================== FT_MEMSET_TEST ===================================
static void	test_memset_1(void)
{
	char	b1[100], b2[100];

	ft_memset(b1, 42, 100);
	memset(b2, 42, 100);
	memcmp(b1, b2, 100) == 0 ? OK : KO;
	RESET;

}

static void	test_memset_2(void)
{
	memcmp(ft_memset(strdup("abcd"), 'A', 5), memset(strdup("abcd"), 'A', 5), 5) == 0 ? OK : KO;
	RESET;
}

static void	test_memset_3(void)
{
	memcmp(ft_memset(strdup("abcd"), 0, 0), memset(strdup("abcd"), 0, 0), 5) == 0 ? OK : KO;
	RESET;
}

void	test_memset(void)
{
	WHITE;
	write(1, "ft_memset  :  ", 13);
	test_memset_1();
	test_memset_2();
	test_memset_3();
	RESET;
	puts("");	
}

//=========================================== FT_STRDUP_TEST ===================================

void	test_strdup(void)
{
	WHITE;
	write(1, "ft_strdup  : ", 13);
	strcmp(ft_strdup("aaaaa"), "aaaaa") == 0 ? OK : KO;
	RESET;
	strcmp(ft_strdup(""), "") == 0 ? OK : KO;
	RESET;
	strcmp(ft_strdup("ok\0null"), "ok\0null") == 0 ? OK : KO;
	RESET;
	puts("");
}

//=========================================== FT_CAT_TEST =====================================

void test_ft_cat(char *v, int fd)
{
	if (!v)
		ft_cat(0);
	else
	{
		if ((fd = open(v, O_RDONLY)) > 0)
			ft_cat(fd);
		else
			perror("open");
	}
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
	#ifdef __FT_isprint
		test_isprint();
	#endif
	#ifdef __FT_toupper
		test_toupper();
	#endif
	#ifdef __FT_tolower
		test_tolower();
	#endif
	#ifdef __FT_puts
		test_puts();
	#endif
	printf("========= Part 2 - A little less simple libc functions ======\n");
	#ifdef __FT_strlen
		test_strlen();
	#endif
	#ifdef __FT_memcpy
		test_memcpy();
	#endif
	#ifdef __FT_memset
		test_memset();
	#endif
	#ifdef __FT_strdup
		test_strdup();
	#endif
	printf("================  Part 3 - Cat ==============================\n");
	#ifdef __FT_cat
		test_ft_cat(v[1], 0);
	#endif
	printf("================  Bonus part ================================\n");	
	#ifdef __FT_putstr_fd
		test_putstr_fd();
	#endif
	#ifdef __FT_putchar_fd
		test_putchar_fd();
	#endif
	#ifdef __FT_putnbr_fd
		test_putnbr_fd();
	#endif	
	return (0);
}

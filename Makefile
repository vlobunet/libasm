NAME = libfts.a

SRC =	ft_putchar_fd.s \
		ft_putstr_fd.s \
		ft_strlen.s \
		ft_putnbr_fd.s \
		ft_bzero.s \
		ft_strcat.s \
		ft_isalpha.s \
		ft_isdigit.s \
		ft_isascii.s \
		ft_isprint.s \
		ft_isallnum.s \
		ft_toupper.s \
		ft_tolower.s \
		ft_puts.s \
		ft_memcpy.s \
		ft_memset.s \
		ft_strdup.s \
		ft_cat.s \
		ft_putendl.s \
		ft_strnew.s \
		ft_memalloc.s

OBJDIR = objs

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.s=.o))

AS = nasm

ASFLAGS = -f macho64 -g

CC = clang

CFLAGS = -Wall -Wextra -fsanitize=address,undefined -g

all: ${NAME}
	@echo ${G}Success"   "[${NAME}]${X}

${NAME}: ${OBJ}
	@ar rcs ${NAME} ${OBJ}

${OBJDIR}/%.o : ./src/%.s
	@/bin/mkdir -p ${OBJDIR}
	@${AS} ${ASFLAGS} -o $@ $<

ctest: all
	@${CC} ${CFLAGS} -L. -lfts -Iincludes test/test.c

test:
	@/bin/mkdir -p ${OBJDIR}
	@${AS} ${ASFLAGS} test/test.s -o ${OBJDIR}/test.o
	@ld ${OBJDIR}/test.o -macosx_version_min 10.8 -lSystem -L. -lfts

clean:
	@echo ${R}Cleaning"  "[${OBJDIR}]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo ${R}Cleaning"  "[${NAME}]...${X}
	@/bin/rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

#gcc test/test.c -L. -lfts -o ret

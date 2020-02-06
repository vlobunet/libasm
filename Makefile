NAME = libfts.a

SRC =	ft_putchar_fd.s \
		ft_putstr_fd.s \
		ft_strlen.s \
		ft_putnbr_fd.s

OBJDIR = objs

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.s=.o))

AS = /usr/local/Cellar/nasm/2.14.02/bin/nasm

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
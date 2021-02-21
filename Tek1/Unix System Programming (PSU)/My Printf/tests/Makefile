##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile that compiles your mibmy
##

SRC	=	../main.c 	\
		../check_if_h.c 	\
		../flags_1.c 		\
		../flags_2.c 		\
		../flags_3.c		\
		../lib/my/my_put_nbr_base.c \
		../lib/my/my_put_nbr.c 	\
		../lib/my/my_putchar.c 	\
		../lib/my/my_putstr.c 		\
		../lib/my/my_strlen.c 		\
		../lib/my/my_unsignednbr.c

LIBMY	=	libmy.a

INCLUDE	=	include

MY	=	my.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(LIBMY) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	rm -f *.c.html

fclean:	clean
	rm -f $(LIBMY)
	rm -f $(TEST_NAME)

re:	fclean all

SRC_TEST = 	test_my_printf.c


TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TEST_FLAG)
				./unit_tests
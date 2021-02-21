##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC_MAIN =	src/main.c				\
			src/my_ls.c	\
			src/my_putstr.c \
			src/my_put_nbr.c\
			src/name.c\
			src/l_flags.c\
			src/my_strcat.c\
			src/t_flag.c\
			src/print.c\
			src/ls_args.c\
			src/flags.c\
			src/t_flag2.c\
			src/l_flags2.c\
			src/ls_folder.c

SRC	=		src/my_ls.c	\
			src/my_putstr.c \
			src/my_put_nbr.c\
			src/l_flags.c\
			src/my_strcat.c\
			src/t_flag.c\
			src/print.c\
			src/ls_args.c\
			src/flags.c\
			src/t_flag2.c\
			src/l_flags2.c\
			src/ls_folder.c

SRC_TEST = 	tests/test_my_ls.c

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		my_ls

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -C

all: $(NAME)

$(NAME): $(OBJ_MAIN)
	gcc $(CFLAGS) $(OBJ_MAIN) -o $(NAME)

clean :
			rm -rf $(OBJ_MAIN)
			rm -rf *.gc*
			rm -rf tests/*.gc*

fclean :	clean
			rm -rf $(NAME)
			rm -rf $(TEST_NAME)

re :		fclean all

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				gcc $(TEST_FLAG) $(SRC) $(SRC_TEST) -o $(TEST_NAME)
				./unit_tests
				gcovr --exclude tests/*.c

#gcovr -r . --html --html-details -o ~/rapport.html

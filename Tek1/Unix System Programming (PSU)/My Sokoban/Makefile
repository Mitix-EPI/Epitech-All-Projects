##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC_MAIN =	src/main.c 			\
			src/main_sokoban.c	\
			src/my_str_to_word_array.c	\
			src/moves.c	\
			src/checks.c	\
			src/finds.c 	\
			src/prints.c

#SRC	=

SRC_TEST =	src/my_str_to_word_array.c	\
			tests/tests_my_sokoban.c

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		my_sokoban

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -C

all: $(NAME)

$(NAME): $(OBJ_MAIN)
	gcc $(OBJ_MAIN) -lncurses -o $(NAME) -g3

clean :
			rm -rf $(OBJ_MAIN)
			rm -rf *.gc*
			rm -rf tests/*.gc*

fclean :	clean
			rm -rf $(NAME)
			rm -rf a.out

re :		fclean all

tests_run:
			gcc $(SRC_TEST) --coverage -lcriterion
			./a.out

#gcovr -r . --html --html-details -o ~/rapport.html

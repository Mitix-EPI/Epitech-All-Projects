##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

CC = gcc

SRC_MAIN =	$(wildcard src/*.c)\

SRC	=		$(filter-out src/main.c, $(wildcard src/*.c))\

SRC_TEST = 	$(wildcard tests/test*.c)\

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		tetris

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -g3  #-pedantic -Wno-unused-variable -Wno-unused-parameter -Wno-newline-eof

all: $(NAME)

$(NAME): $(OBJ_MAIN)
	$(CC) $(OBJ_MAIN) -o $(NAME) -lncurses

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
				gcovr --exclude tests

#gcovr -r . --html --html-details -o ~/rapport.html

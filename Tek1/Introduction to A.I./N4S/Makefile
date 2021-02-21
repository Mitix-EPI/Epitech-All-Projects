##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC_MAIN =	$(shell find . -name "*.c")

SRC	=		$(filter-out src/main.c, $(shell find . -name "*.c"))

SRC_TEST = 	$(wildcard tests/*.c)\

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		ai

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -C -g3 -I./include -lm

all: $(NAME)

$(NAME): $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ_MAIN) $(CFLAGS)

clean :
			rm -rf $(OBJ_MAIN)
			rm -rf *.gc*
			rm -rf tests/*.gc*

fclean :	clean
			rm -rf $(NAME)
			rm -rf $(TEST_NAME)

re :		fclean all

move:	all
	mv ai ../n4s_package/

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				gcc $(TEST_FLAG) $(SRC) $(SRC_TEST) -o $(TEST_NAME)
				./unit_tests
				gcovr --exclude tests

#gcovr -r . --html --html-details -o ~/rapport.html

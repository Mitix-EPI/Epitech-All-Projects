##
## EPITECH PROJECT, 2020
## CPE_corewar_2019
## File description:
## Makefile
##

SRC_MAIN =	$(shell find src -name "*.c")

SRC	=		$(filter-out src/main.c, $(SRC_MAIN))

SRC_TEST = 	$(wildcard tests/*.c)\

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		corewar

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -W -Wall -Wextra -C -g3 -I./include

all: $(NAME)

$(NAME): $(OBJ_MAIN)
	gcc $(CFLAGS) $(OBJ_MAIN) -lncurses -o $(NAME)

clean :
			rm -f $(OBJ_MAIN)
			rm -rf *.gc*
			rm -rf tests/*.gc*

fclean :	clean
			rm -rf $(NAME)
			rm -rf $(TEST_NAME)
			rm -f tests/*.o

re :		fclean	\
			all

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				gcc $(CFLAGS) $(TEST_FLAG) $(SRC) $(SRC_TEST) -o $(TEST_NAME)
				./unit_tests
				gcovr --exclude tests
				gcovr --exclude tests -b

#gcovr -r . --html --html-details -o ~/rapport.html
##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

SRC_MAIN =	$(wildcard *.c)\

SRC	=		$(wildcard *.c)\

SRC_TEST = 	$(wildcard tests/test*/*.c)\

OBJ_MAIN =	$(SRC_MAIN:.c=.o)

NAME =		menger_face

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

CFLAGS = -std=gnu11 -Wall -Wextra

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
				gcovr --exclude tests

#gcovr -r . --html --html-details -o ~/rapport.html

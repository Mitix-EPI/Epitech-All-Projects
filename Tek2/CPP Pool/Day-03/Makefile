##
## EPITECH PROJECT, 2021
## B-CPP-300-MPL-3-1-CPPD03-alexandre.juan
## File description:
## Makefile
##

SRC	=	$(filter-out main_test.c, $(wildcard *.c))\

LIBMY	=	libstring.a

INCLUDE	=	include

MY	=	string.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libstring

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(LIBMY) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean:	clean
	rm -f $(LIBMY)
	rm -f $(TEST_NAME)

re:	fclean all

SRC_TEST = $(filter-out main_test.c, $(wildcard tests/test*.c))\

TEST_NAME =	unit_tests

TEST_FLAG = -lcriterion --coverage

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				gcc -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(TEST_FLAG)
				./unit_tests
				gcovr --exclude tests/
				gcovr -b --exclude tests/
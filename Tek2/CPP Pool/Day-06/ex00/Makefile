##
## EPITECH PROJECT, 2021
## Desktop
## File description:
## Makefile
##

SRC	=	$(wildcard *.cpp)\

SRC_TEST_WITHOUT_MAIN	=	$(filter-out main.cpp, $(wildcard *.cpp))\

NAME	=	my_cat

all:	$(NAME)

$(NAME):
	g++ -o $(NAME) $(SRC) -std=c++14 -Wall -Wextra -Werror

clean:
	rm -f $(NAME)
	rm -f *.gc*
	rm -rf ./rapport *.info

fclean:	clean
	rm -f $(TEST_NAME)

re:	fclean all

SRC_TEST	=	$(filter-out main.c, $(wildcard tests/test*.cpp))\

TEST_NAME	=	unit_tests

TEST_FLAG	=	-lcriterion --coverage

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST_WITHOUT_MAIN) $(SRC_TEST)
			rm -f *.gc*
			g++ -o $(TEST_NAME) $(SRC_TEST_WITHOUT_MAIN) $(SRC_TEST) $(TEST_FLAG)
			./unit_tests
			gcovr --exclude tests/
			gcovr -b --exclude tests/

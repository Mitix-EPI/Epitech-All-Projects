##
## EPITECH PROJECT, 2021
## nanoTekSpice
## File description:
## Makefile
##

SRC = $(wildcard src/*.cpp) \
	$(wildcard src/**/*.cpp)

SRC_TEST_1 = src/Component/C_True.cpp\
			src/Component/Component.cpp\
			src/Exceptions/Exceptions.cpp

SRC_TEST = tests/test_true.cpp\

CC = g++

RM	=	rm -f

CFLAGS = -Wall -Wextra -Werror -I./include/

NAME = nanotekspice

DFLAGS = -Wall -Wextra -I./include/ -g3

UTFLAGS	=	-lcriterion --coverage

all: $(NAME)

$(NAME):
	$(CC) $(SRC) $(CFLAGS) -o $(NAME)

clean:
	rm -rf *.gc*
	rm -rf tests/*.gc*

fclean: clean
	rm -rf $(NAME)
	rm -rf unit_tests

re: fclean all

debug:
	$(CC) $(SRC) $(DFLAGS) -o $(NAME)

tests_run:
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) unit_tests
	g++ $(SRC_TEST_1) $(SRC_TEST) -I./include/ $(UTFLAGS) -o unit_tests
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/

.PHONY: all clean fclean re debug
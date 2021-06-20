##
## EPITECH PROJECT, 2021
## B-CPP-300-MPL-3-1-CPPD14A-alexandre.juan
## File description:
## Makefile
##

SRC		=

SRC_TEST	=	tests/test_errors.cpp\
				Errors.cpp

OBJ	=	$(SRC:.c=.o)

NAME	=	test.a

NAME_TEST	=	unit_tests

CFLAGS	=	-Wall -Wextra

UTFLAGS	=	-lcriterion --coverage

RM	=	rm -rf

all:	tests_run

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

tests_run:
	$(RM) *.gcda *.gcno
	$(RM) unit_test.dSYM
	g++ -o $(NAME_TEST) $(UTFLAGS) $(SRC_TEST) $(CFLAGS) -I./tests/
	./unit_tests
	gcovr --exclude tests/
	gcovr -b --exclude tests/

clean:
	$(RM) $(OBJ)

fclean :	clean
		$(RM) $(NAME)
		$(RM) $(NAME_TEST)
		$(RM) *.gcda *.gcno
		$(RM) unit_test.dSYM

re:		fclean all
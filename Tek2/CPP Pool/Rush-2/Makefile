##
## EPITECH PROJECT, 2021
## cpp_pool
## File description:
## unit tests
##

SRC	=

SRC_TEST =	tests/test_LittlePony.cpp 			\
			tests/test_Teddy.cpp 				\
			tests/test_ObjectOperator.cpp		\
			tests/test_Wrap.cpp					\
			LittlePony.cpp 						\
			Object.cpp 							\
			Teddy.cpp 							\
			Toy.cpp 							\
			GiftPaper.cpp						\
			Box.cpp								\
			Wrap.cpp							\

OBJ	=	$(SRC:.c=.o)

NAME	=	test.a

NAME_TEST	= 	unit_tests

CFLAGS 	= 	-Wall -Wextra

UTFLAGS =       -lcriterion --coverage

RM	=	rm -rf

all:		tests_run

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
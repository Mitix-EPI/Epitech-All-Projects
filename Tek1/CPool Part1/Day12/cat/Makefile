##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC	=	cat.c		\
		my_putstr.c	\
		main.c

OBJ 	=	 $(SRC:.c=.o)

SRC1 	= 	cat.c	\
			my_putstr.c

OBJ1 	= 	$(SRC1:.c=.o)

NAME = 		cat

all: $(NAME)

$(NAME):		$(OBJ)
			gcc -Wextra -Werror -W $(OBJ) -o $(NAME)

clean :
			rm -rf $(OBJ)

fclean :		clean
			rm -rf $(NAME)

re :			fclean all

tests_run:		$(OBJ1)
			gcc -o unit_tests $(OBJ1) tests/test_cat.c --coverage -lcriterion
			./unit_tests

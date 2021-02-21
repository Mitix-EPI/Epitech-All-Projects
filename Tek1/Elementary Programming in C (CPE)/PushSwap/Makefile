##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC	=		src/my_amazing_sorter.c 				\
			src/swap.c		\
			src/my_getnbr.c	\
			src/my_putstr.c \
			src/main.c

OBJ 	=	 $(SRC:.c=.o)

NAME = 		push_swap

all: $(NAME)

$(NAME):		$(OBJ)
			gcc -Ofast -Wextra -Werror -W -g $(OBJ) -o $(NAME)

clean :
			rm -rf $(OBJ)
			rm -rf *.gc*

fclean :		clean
			rm -rf $(NAME)
			rm -rf a.out

re :			fclean all

SRC_TEST =	src/my_amazing_sorter.c 				\
			src/swap.c		\
			src/my_getnbr.c	\
			src/my_putstr.c \
			tests/test_swap_elem.c

tests_run:
			gcc $(SRC_TEST) --coverage -lcriterion
			./a.out

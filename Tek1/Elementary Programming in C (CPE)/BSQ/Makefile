##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC	=		main.c 				\
			main_bsq.c			\
			bsq_reader.c	\
			my_getnbr.c		\
			bsq_find_biggest_square.c	\
			calc.c	\
			my_revstr.c	\
			my_print_map.c

OBJ 	=	 $(SRC:.c=.o)

NAME = 		bsq

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

SRC_TEST =	main_bsq.c \
			calc.c	\
			bsq_find_biggest_square.c \
			bsq_reader.c 	\
			my_getnbr.c 	\
			my_revstr.c		\
			my_print_map.c 	\
			tests/tests_my_bsq.c


tests_run:
			gcc $(SRC_TEST) --coverage -lcriterion
			./a.out
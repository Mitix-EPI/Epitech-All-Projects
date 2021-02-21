##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC	=		main.c			\
			eval_expr.c		\
			my_putchar.c	\
			my_put_nbr.c

OBJ 	=	 $(SRC:.c=.o)

NAME = 		eval_expr

all: $(NAME)

$(NAME):		$(OBJ)
			gcc -Wextra -Werror -W $(OBJ) -o $(NAME)

clean :
			rm -rf $(OBJ)

fclean :		clean
			rm -rf $(NAME)

re :			fclean all

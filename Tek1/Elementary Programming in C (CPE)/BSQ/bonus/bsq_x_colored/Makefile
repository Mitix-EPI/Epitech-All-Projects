##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC	=		main.c			\
			bsq_reader.c	\
			my_putstr.c		\
			my_getnbr.c		\
			bsq_find_biggest_square.c	\
			calc.c	\
			my_revstr.c

OBJ 	=	 $(SRC:.c=.o)

NAME = 		bsq

all: $(NAME)

$(NAME):		$(OBJ)
			gcc -Wextra -Werror -W -g $(OBJ) -o $(NAME)

clean :
			rm -rf $(OBJ)

fclean :		clean
			rm -rf $(NAME)

re :			fclean all
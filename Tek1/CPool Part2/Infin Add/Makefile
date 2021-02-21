##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC	=		main.c				\
			my_putstr_errors.c	\
			my_str_isnum.c		\
			my_strlen.c			\
			my_putstr.c 		\
			my_revstr.c

OBJ 	=	 $(SRC:.c=.o)

NAME = 		infin_add

all: $(NAME)

$(NAME):		$(OBJ)
			gcc -Wextra -Werror -W $(OBJ) -o $(NAME) 

clean :
			rm -rf $(OBJ)

fclean :		clean
			rm -rf $(NAME)

re :			fclean all

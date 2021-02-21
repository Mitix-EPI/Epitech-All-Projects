##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC =	infin_mult.c						\
		../include/my_revstr.c				\
		../include/my_strlen.c				\
		../include/my_putstr.c				\
		../include/my_putchar.c

OBJ = $(SRC:.c=.o)

NAME = infin_mult

all: $(NAME)

$(NAME):$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

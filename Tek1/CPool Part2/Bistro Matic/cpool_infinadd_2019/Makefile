##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC =	main_infinadd.c				\
		error.c				\
		add.c				\
		sub.c 				\
		count_keep.c		\
		my_get_bigger_nb.c	\
		my_putchar.c 		\
		my_putstr.c 		\
		my_revstr.c 		\
		my_strlen.c

OBJ = $(SRC:.c=.o)

NAME = infin_add

all: $(NAME)

$(NAME):$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile that compiles your mibmy
##

SRC	=		main.c		\
			flags_1.c		\
			lib/my/my_put_nbr.c 		\
			lib/my/my_putchar.c 		\
			lib/my/my_putstr.c			\
			lib/my/my_strlen.c			\
			lib/my/my_put_nbr_base.c	\
			flags_2.c					\
			check_if_h.c				\
			flags_3.c					\
			lib/my/my_unsignednbr.c

LIBMY	=	libmy.a

INCLUDE	=	include

MY	=	my.h

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(LIBMY) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(LIBMY)

re:	fclean all


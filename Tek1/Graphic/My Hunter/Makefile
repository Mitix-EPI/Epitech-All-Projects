##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## rules
##

SRC	=	src/main.c	\
		src/my_menu.c	\
		src/my_game.c	\
		src/my_event_game.c	\
		src/my_jul_tmax.c	\
		src/my_pointer.c	\
		src/my_try_again.c	\
		src/my_ufo.c		\
		src/my_life.c		\
		src/my_itoa.c		\
		src/my_sets.c		\
		src/close.c			\
		src/my_sets_menu.c

OBJ 	=	 $(SRC:.c=.o)

NAME = 		my_hunter

all: $(NAME)

$(NAME):		$(OBJ)
			gcc -Wextra -Werror -W $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

clean :
			rm -rf $(OBJ)

fclean :		clean
			rm -rf $(NAME)

re :			fclean all

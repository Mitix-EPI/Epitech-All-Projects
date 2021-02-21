##
## EPITECH PROJECT, 2020
## MUL_my_runner_2019
## File description:
## Makefile
##

SRC	=	src/main.c\
		src/character.c\
		src/display.c\
		src/game.c\
		src/main_my_runner.c\
		src/menu.c\
		src/parallaxe.c\
		src/buttons_menu.c\
		src/options.c\
		src/my_str_to_word_array.c\
		src/open_file.c\
		src/spikes.c\
		src/create.c\
		src/end.c\
		src/my_itoa.c\
		src/options_buttons_functions.c\
		src/hero.c\
		src/score.c\
		src/sets.c\
		src/ending_game.c\
		src/options_buttons.c\
		src/destroy.c\
		src/destroy2.c\
		src/my_strcat.c

OBJ 	=	 $(SRC:.c=.o)

NAME = 		my_runner

all: $(NAME)

$(NAME):		$(OBJ)
			gcc -Wextra -Werror -W $(OBJ) -o $(NAME) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

clean :
			rm -rf $(OBJ)

fclean :		clean
			rm -rf $(NAME)

re :			fclean all

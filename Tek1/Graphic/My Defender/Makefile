##
## EPITECH PROJECT, 2019
## Bistromatic
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/create_delete_windows.c	\
		src/event.c	\
		src/last_destroye.c	\
		src/man.c	\
		src/statue.c	\
		src/set_sprite.c	\
		src/menu.c	\
		src/calc.c	\
		src/mouse_click_s_0.c	\
		src/mouse_click_s_1.c	\
		src/mouse_click_s_3.c	\
		src/mouse_click.c	\
		src/my_strlen.c	\
		src/str_cmp.c	\
		src/my_memset.c	\
		src/cat.c	\
		src/init_value.c	\
		src/clock.c	\
		src/name.c	\
		src/key_pressed.c	\
		src/my_str_to_word_array.c	\
		src/open_file.c	\
		src/itos.c	\
		src/draw_cursor.c	\
		src/display_win_loose.c	\
		src/init_enn.c	\
		src/set_tow.c	\
		src/init_tow.c	\
		src/sprite_create_one.c 	\
		src/shoot_tow.c	\
		src/shoot_tow_two.c	\
		src/draw_enn_tow_upt_wave.c	\
		src/update_enn.c	\
		src/diplay_game.c	\
		src/hud_game.c	\
		src/display_score_one.c	\
		src/display_score_two.c	\
		src/free_tow_enn.c	\
		src/display_scores.c\
		src/set_good_pos_enn.c\
		src/select_type_of_enn.c\
		src/update_map.c\
		src/gold_loose.c\
		src/starting_level.c \
		src/init_bomb.c	\
		src/pause.c	\
		src/atoi.c	\
		src/save.c

NAME	=	my_defender

OBJ	=	libmy.a

all	:
	gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g3 -lm

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	: fclean all
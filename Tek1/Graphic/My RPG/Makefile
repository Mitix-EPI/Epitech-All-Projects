##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g3 -I./include -lm

SRC	=	src/clics_handlings.c						\
		src/clock_event.c							\
		src/draw_statue.c							\
		src/draw_statue_two.c						\
		src/global_event.c							\
		src/global_event_two.c						\
		src/global_event_three.c					\
		src/init_player.c							\
		src/main_rpg.c								\
		src/main.c									\
		src/my_putstr.c								\
		src/my_set_sprites.c						\
		src/my_strlen.c								\
		src/player_rects.c							\
		src/save.c									\
		src/save_to_file.c							\
		src/save_to_file_two.c						\
		src/my_strcat.c								\
		src/my_strcpy.c								\
		src/itos.c									\
		src/menu/click_menu2.c						\
		src/menu/check_mouse.c						\
		src/menu/check_mouse2.c						\
		src/menu/click_menu.c						\
		src/menu/draw_menu.c						\
		src/menu/menu_destroy.c						\
		src/menu/menu_set_sprites.c					\
		src/menu/menu_set_sprites_two.c				\
		src/menu/menu_set2.c						\
		src/menu/menu_set2_two.c					\
		src/menu/particules.c						\
		src/get_next_char.c							\
		src/load_map.c								\
		src/create_perspective.c					\
		src/tuto/draw_tuto.c						\
		src/tuto/tuto.c								\
		src/tuto/tuto_two.c								\
		src/keys_handlings.c						\
		src/handling_items.c						\
		src/handling_items_two.c					\
		src/death/script_death.c					\
		src/init.c									\
		src/init_two.c								\
		src/init_three.c							\
		src/save_two.c								\
		src/fight/draw_fights.c						\
		src/fight/fights.c							\
		src/fight/update_fights.c					\
		src/fight/boss.c							\
		src/fight/attacks.c							\
		src/fight/player_deplacements.c				\
		src/fight/spells.c							\
		src/fight/launch_spell.c					\
		src/fight/player_fight_rects.c				\
		src/generate_random.c						\
		src/fights_spawns.c							\
		src/fight/black_hole.c						\
		src/fight/fireball.c						\
		src/fight/heals.c							\
		src/fight/shield.c							\
		src/fight/speed.c							\
		src/my_ftoa.c								\
		src/destroy.c								\
		src/end_script/draw_end_script.c			\
		src/stof.c									\
		src/end_script/end_script.c					\
		src/end_script/act_end_script.c				\
		src/fight/use_spell.c						\
		src/end_script/acts.c 						\
		src/fight/pos_and_animation_black_hole.c	\
		src/fight/checks_and_display_black_hole.c	\
		src/fight/others_functions_black_hole.c		\
		src/fight/move_and_anim_boss.c				\
		src/fight/display_fights2.c					\
		src/fight/feux_d_artifices.c				\
		src/fight/win_fights.c						\
		src/fight/check_animation_fireball.c		\
		src/fight/cooldown_fireball.c				\
		src/fight/heals_cooldown_animation.c		\
		src/fight/shield_cooldown_animation.c		\
		src/fight/shield_checks.c					\
		src/fight/speed_animation_cooldown.c		\
		src/fight/init_healt_speed_black_hole.c		\
		src/fight/move_fights.c						\
		src/fight/ennemies_fight.c					\
		src/fight/pos_change_move_fight.c			\
		src/musics.c								\
		src/creates_one.c							\
		src/creates_two.c							\
		src/sets.c									\




SRC2 =	tests/test_main.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

NAME2	=	units

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME2)
	rm -f *.gcda *.gcno *.info

re:	fclean all

tests_run:
	$(CC) -o $(NAME2) $(SRC2) --coverage -lcriterion -I./include
	./$(NAME2)

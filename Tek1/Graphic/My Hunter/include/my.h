/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Context.h>
#include <SFML/Window.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Window.h>
#include <SFML/Graphics/Export.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct window
{
    sfSoundBuffer *buffer;
    sfSound *ibiza;

    sfClock *clock;

    sfIntRect rect_tmax;
    sfIntRect rect_scope;
    sfIntRect rect_ufo;
    sfIntRect rect_life;
    sfIntRect button;

    sfTime time;

    sfEvent evt;

    sfSprite *sbg0;
    sfSprite *sbg1;
    sfSprite *sbg2;
    sfSprite *sscope;
    sfSprite *stmax;
    sfSprite *sufo;
    sfSprite *slife;
    sfSprite *splay;
    sfSprite *squit;

    sfTexture *tbg0;
    sfTexture *tbg1;
    sfTexture *tbg2;
    sfTexture *tscope;
    sfTexture *ttmax;
    sfTexture *tufo;
    sfTexture *tlife;
    sfTexture *tplay;
    sfTexture *tquit;

    sfVector2f size;
    sfVector2f size1;
    sfVector2i mouse;
    sfVector2f position_cursor;
    sfVector2f txt_pos;
    sfVector2i mouse_pos;

    float tmax_pos_x;
    float tmax_pos_y;
    float ufo_pos_x;
    float ufo_pos_y;

    sfText *text;
    sfFont *font;
    sfText *text1;
    sfText *text_score;

    sfImage *icon;

    char *str_score;

    int cursor_x;
    int cursor_y;
    int score;
    int life;
    int not_close_t_a;

    float speed_mob;

    int try_again;

    float second;
    float second_ufo;
}window_t;


//main.c
int main(int ac, char **av);
int check_h_and_errors(int ac, char **av);
int print_description(void);
void set_music(window_t *w);

//close.c
int close_window_menu(sfRenderWindow *window, window_t *w);
int exit_menu(sfRenderWindow *window, window_t *w);

//my_event_game.c
int printrandoms(int lower, int upper);
void touch_tmax(sfRenderWindow *window , window_t *w);
void touch_ufo(sfRenderWindow *window , window_t *w);
int game_event(sfRenderWindow *window, window_t *w);

//my_game.c
void create_sprite_game(window_t *w);
void create_texture_and_sprite(window_t *w);
void my_draw_game(sfRenderWindow *window, window_t *w);
void destroy_texture_and_sprite(window_t *w);
int run_window(sfRenderWindow *window, window_t *w);

//my_itoa.c
int number_digits(int nbr);
char *my_itc(int nbr);

//my_jul_tmax.c
void set_rect_life(window_t *w);
void move_rect(sfIntRect *rect, int offset, int max_value);
void my_display_jul(sfRenderWindow *window, window_t *w);

//my_life.c
void set_score_text(sfRenderWindow *window, window_t *w);
void my_display_life(sfRenderWindow *window, window_t *w);

//my_menu.c
void destroy_menu(window_t *w);
int coor_p_q(sfRenderWindow *window, window_t *w, int x, int y);
void display_menu(sfRenderWindow *window, window_t *w);
void interactive_button(window_t *w, int x, int y);
int run_menu(sfRenderWindow *window, window_t *w);

//my_pointer.c
void default_rect(window_t *w2);
void my_pointer(sfRenderWindow *window, window_t *w2);

//my_sets_menu.c
void set_text2(window_t *w);

//my_sets.c
void set_rect_anim(window_t *w);
void set_animations_variables(sfRenderWindow *window, window_t *w);
void set_text_t_a2(window_t *w);
void set_text_t_a(window_t *w);
void set_text(window_t *w);

//my_try_again.c
void destroy_t_a(window_t *w);
int t_a_or_q(sfRenderWindow *window, window_t *w, int x, int y);
void display_t_a(sfRenderWindow *window, window_t *w);
void interactive_button2(window_t *w, int x, int y);
int my_try_again(sfRenderWindow *window, window_t *w);

//my_ufo.c
void move_rect_ufo(sfIntRect *rect, int offset, int max_value);
void my_display_ufo(sfRenderWindow *window, window_t *w);

#endif /* !MY_H_ */

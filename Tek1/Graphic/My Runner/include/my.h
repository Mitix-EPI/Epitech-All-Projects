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
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef enum
{
    UN,
    DEUX,
    TROIS,
    QUATRE,
    ACT,
    NO
}PARALAX;
typedef struct parallax_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfClock *clck;
    sfIntRect rect;
    sfTime time;
    float seconds;
    struct game_s (*func)(struct game_s);
    PARALAX type;
    PARALAX copy;
}parallax_t;

typedef struct character_s
{
    sfSprite *hero;
    sfTexture *t_hero;
    sfClock *clck;
    sfTime time;
    sfIntRect rect;
    sfVector2f pos_hero;
    sfVector2f vel;
    float seconds;
    int jump;
}character_t;

typedef struct win_s
{
    sfRenderWindow *w;
    sfVideoMode mode;
    sfEvent event;
    sfVector2i m_pos;
}win_t;

typedef struct music_s
{
    sfSound *sound;
    sfSoundBuffer *buff;
}music_t;

typedef struct buttons_s
{
    sfSprite *sprt;
    sfTexture *texture;
    sfIntRect rct;
}buttons_t;

typedef struct end_s
{
    int x_origin;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfClock *clck;
    sfTime time;
    sfIntRect rect;
    float seconds;
    int x;
    int y;
}end_t;

typedef struct barriers_s
{
    int x_origin;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfClock *clck;
    sfTime time;
    sfIntRect rect;
    float seconds;
    int x;
    int y;
}barriers_t;

typedef struct txt_s
{
    sfText *text;
    sfVector2f pos;
}txt_t;

typedef struct game_s
{
    win_t win;
    parallax_t parallax[8];
    character_t character;
    music_t music[6];
    buttons_t buts[4];
    buttons_t opts_but[5];
    txt_t txt[9];
    barriers_t *bars;
    end_t end;

    sfText *text;
    sfSprite *scoreboard;
    sfTexture *board_t;
    sfClock *general;
    sfTime time;

    int nav;
    int res;
    int limit_bar;
    char *score;
    float second;

    int pts;
    int real_pts;

    int ips;
    int endless;
    int vol_music;
    int vol_effect;
    int difficulty;
}game_t;

//main.c
int main(int ac, char **av);

//main_my_runner.c
void create_window(game_t *game);
int print_help(void);
void set_music(game_t *game);
int main_my_runner(char *path_map);

//menu.c
int destroy_menu_end(game_t *game);
int destroy_menu(game_t *game);
void update_menu(game_t *game);
int event_menu(game_t *game);
int real_menu(game_t *game);

//parallaxe.c
void sets_parallax(game_t *game);
void update_per_bg(parallax_t *para, sfRenderWindow *win);

//game.c
void destroy(game_t *game);
int update(game_t *game);
int event_game(game_t *game);
int run_game(game_t *game);
void sets_game(game_t *game);
void set_score(game_t *game);

//character.c
void move_rect(game_t *game);
void move_animation(game_t *game);
void sets_hero(game_t *game);
void jump(game_t *game);

//display.c
void display(game_t *game);
void display_menu(game_t *game);
void display_options(game_t *game);

//buttons.c
void sets_menu(game_t *game);
void song_effect_button(game_t *game, int x, int y);
void interactive_button(game_t *game, int x, int y);
int choose_button(int x, int y);

//options.c
int options(game_t *game);
void update_options(game_t *game);
int event_options(game_t *game);
void destroy_options_end(game_t *game);
void sets_options(game_t *game);
int pls_or_mns(int x);

//my_str_to_word_array.c
char **my_str_to_word_array(char const *str);
int set_char_max(char const *str, int length);
int my_nb_str(char const *str);
char *my_get_str_word(char const *str, int *n, int char_max);
int count_malloc(char const *cache);

//open_file.c
char *map_reader(char *map, long size);

//spikes.c
void update_per_bar(barriers_t *bars, sfRenderWindow *win);
void reset_barriers(game_t *game);

//create.c
struct buttons_s crt_buts(const char *path, sfVector2f ps, sfVector2f scale);
struct parallax_s crt_bg(const char *path, sfVector2f ps, int i, int j);
struct barriers_s crt_bar(sfVector2f pos, sfIntRect rect);
struct end_s crt_end(sfVector2f pos);

//end.c
void update_end(end_t *end, sfRenderWindow *win);
int finisher(game_t *game);

//my_itoa.c
char *my_itc(int nbr);

//my_strcat.c
char *my_strcat(char *dest, char const *src);

//create.c
struct music_s crt_sound(char *path);
void crt_txt(txt_t *txt, char *str, sfVector2f pos);
struct buttons_s crt_options_buts(char *path, sfVector2f pos, int i);

//options_buttons_functions.c
void ips_change(game_t *game, int i);
void music_volum(game_t *game, int i);
void effect_volum(game_t *game, int i);
void difficulty_change(game_t *game, int i);
void endless_change(game_t *game);

//hero.c
int update_hero(game_t *game);

//score.c
void update_score(game_t *game);
void set_score(game_t *game);

//ending_game.c
int skip_game_over(game_t *game);
int ending(game_t *game, int first_time);

//sets.c
void sets_game(game_t *game);
void sets_options(game_t *game);
void sets_barriers(game_t *game, char *map);
void set_music(game_t *game);
void basics_sets(game_t *game, char *map);

int calc(int x);

int count_charac(char **mapa, char letter);

//options_buttons.c
void interactive_button_options(game_t *game, int x, int y);
void sound_button_options(game_t *game, int x, int y);
int choose_butt_optns(game_t *game, int x, int y);

//destroy.c
void destroy_parallax(game_t *game);
void destroy_barriers(game_t *game);
void destroy_end_flag(game_t *game);
void destroy_hero(game_t *game);
void destroy_options_butts(game_t *game);

//destroy2.c
void destroy_music(game_t *game);
void destroy_menu_buttons(game_t *game);
int destroy_menu(game_t *game);

#endif /* !MY_H_ */

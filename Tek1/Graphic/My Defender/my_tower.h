/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_hunter.h
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/JoystickIdentification.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

typedef struct ennemies_c
{
    sfSprite *sprite;
    sfTexture *txtre;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float second;
    char direct;
    int status;
    int life;
    int type;
}ennemies_t;

typedef struct towers_c
{
    sfSprite *sprite;
    sfTexture *txtre;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float second;
    char direct;
    int status;
    int nb_tow;
    int tow;
}towers_t;

typedef struct sprite_c
{
    ennemies_t *enn;
    towers_t *tow;
    sfCircleShape* circle;
    sfSprite* menu_btn;
    sfSprite* sound_volume;
    sfSprite* menu;
    sfSprite* back_opt;
    sfSprite* map;
    sfSprite* tower_1;
    sfSprite* tower_2;
    sfSprite* tower_3;
    sfSprite* tower_4;
    sfSprite* little_bomb;
    sfSprite* big_bomb;
    sfSprite* lvl;
    sfSprite *loading;
    sfText* text_menu;
    sfFont* font_menu;
    sfText* text_gold;
    sfText* text_score;
    sfFont* font_gold;
    sfText* text_life;
    sfText* text_win;
    sfText* text_display_score;
    sfText* text_best_score_one;
    sfText* text_best_score_two;
    sfText* text_best_score_tree;
    sfText* text_best_score_four;
    sfText* text_best_score_five;
    sfText* text_best_score_six;
    sfText* text_best_score_seven;
    sfText* text_best_score_height;
    sfText* text_best_score_nine;
    sfText* text_loose;
    sfText* text_wave;
    sfText* text_nb_tow;
    sfFont* font_life;
    sfMusic* music_chill;
    sfMusic* music_hard;
    sfMusic* tow_input;
    sfMusic* tow_shot;
    sfMusic *bomb_sound;
    sfSprite *button_pause_sprt;
    sfSprite *menu_pause_sprt;
    char **map_;
    float hight;
    float weidth;
    float volume;
    int tow_alive;
    int gold;
    int rep;
    int statue;
    int level;
    int hori;
    int vert;
    int cursor;
    int life;
    int vague;
    int score;
    int nb_enn;
    int enn_alive;
    int nb_tow;
    float last_angle;
    char *name;
    char **all_score;
    int pause;
} sprite_t;

typedef struct clock_c
{
    sfClock *clock;
    sfTime time;
    float second;
} clock_s;

void delete_tow(sprite_t *sprite, sfVector2i mouse);
void initialise_level(sprite_t *sprite, sfRenderWindow *window);
void pos_tower(sprite_t *sprite, sfVector2i mouse);
void add_tow(sprite_t *sprite, int nb, sfVector2i mouse);
void gold_loose(sprite_t *sprite, int x, int y, sfVector2i mouse);
void click_menu_pause(sfMouseButtonEvent event, sfRenderWindow *window, \
sprite_t *sprite, sfVector2i mouse);
void click_pause(sfMouseButtonEvent event, sfRenderWindow *window, \
sprite_t *sprite, sfVector2i mouse);
void update_map_(sprite_t *sprite);
void update_map(sprite_t *sprite);
void display_best_scores(sprite_t *sprite, sfRenderWindow *window);
void man(void);
char set_good_direc(float x, float y, sfSprite *sprt, sprite_t *sprite);
sfVector2f set_good_pos(sprite_t *sprite);
void select_type_of_ennemies(sprite_t *sprite);
sfRenderWindow *windows(int h, int l);
void close_windows(sfRenderWindow *window, sprite_t *sprite);
void global_event(sfRenderWindow *window, sfEvent event, sprite_t *sprite);
void analyse_events(sfRenderWindow *window, sfEvent event, sprite_t *sprite);
void draw_statue(sfRenderWindow *window, sprite_t *sprite);
void destroy_sprite(sfRenderWindow *window, sprite_t *sprite);
void my_set_sprites(sprite_t *sprites, sfRenderWindow *window, clock_s *clock);
void display_menu_text(sprite_t *sprite);
void draw_menu(sfRenderWindow *window, sprite_t *sprite);
void draw_option(sfRenderWindow *window, sprite_t *sprite);
sfSprite *back_opt(sfRenderWindow *window);
sfSprite *menu_btn(sfRenderWindow *windows, sprite_t *sprites);
void manage_mouse_click(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite);
void click_statue_zero(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse);
void click_statue_un(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse);
void click_statue_trois(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse);
float croix(int temp, char mode, sprite_t *sprite);
int str_cmp(char *str, char *str2);
int my_strlen(char *str);
void *my_memset(char *s, int c, int n);
char *cat(char *start, char *line);
void init_name(sprite_t *sprite);
void clock_event(sfRenderWindow *window, sprite_t *sprite, clock_s clock);
void int_value(sprite_t *sprite, clock_s *clock);
void key_press(sfRenderWindow *window, sfEvent event, sprite_t *sprite);
void name(sprite_t *sprite, sfEvent event);
char **my_str_to_word_array(char *str);
char *map_reader(char *map, long size);
char *int_to_string(int num);
void set_towers(sprite_t *sprite);
void set_ennemies(sprite_t *sprite);
int generate_random(int l, int r);
int calc_coeff(int temp, char mode, sprite_t *sprite);
void update_type_enn(sprite_t *sprite);
void update_nb_enn(sprite_t *sprite);
void loose(sfRenderWindow *window, sprite_t *sprite);
void update_waves(sprite_t *sprite);
void click_statue_six(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse);
void choose_lvl(sfRenderWindow *window, sprite_t *sprite);
void win(sfRenderWindow *window, sprite_t *sprite);
void draw_cursor_one(sprite_t *sprite, sfRenderWindow *window, \
sfVector2i mouse);
void loose(sfRenderWindow *window, sprite_t *sprite);
void win(sfRenderWindow *window, sprite_t *sprite);
void display_loose(sprite_t *sprite);
void display_win(sprite_t *sprite);
int generate_random(int l, int r);
void update_type_enn(sprite_t *sprite);
struct ennemies_c init_enemy(char *path, sfVector2f pos, sfVector2f scale, \
sprite_t *sprite);
void set_ennemies(sprite_t *sprite);
void select_type_of_ennemies(sprite_t *sprite);
sfSprite *tower_1(sfRenderWindow *windows, sprite_t *sprites);
sfSprite *tower_2(sfRenderWindow *windows, sprite_t *sprites);
sfSprite *tower_3(sfRenderWindow *windows, sprite_t *sprites);
sfSprite *tower_4(sfRenderWindow *windows, sprite_t *sprites);
struct towers_c init_tower(char *path, sfVector2f pos, sfVector2f scale);
void set_towers(sprite_t *sprite);
sfSprite *menu_btn(sfRenderWindow *windows, sprite_t *sprites);
sfSprite *lvl(sfRenderWindow *windows, sprite_t *sprites);
sfSprite *sound_volume(sfRenderWindow *windows, sprite_t *sprites);
sfSprite *back_opt(sfRenderWindow *window);
sfSprite *map(sfRenderWindow *windows, sprite_t *sprites);
float angle(sprite_t *sprite, int i, int a);
void shoot_tow_one(sprite_t *sprite, int i);
void shoot_tow_two(sprite_t *sprite, int i);
void shoot_tow_tree(sprite_t *sprite, int i);
void shoot_tow_four(sprite_t *sprite, int i);
void update_waves(sprite_t *sprite);
void draw_enn(sprite_t *sprite, sfRenderWindow *window);
void draw_tow(sprite_t *sprite, sfRenderWindow *window);
void diff_tow(sprite_t *sprite, int i);
void shot_tow(sprite_t *sprite, sfRenderWindow *window);
void change_rotation_enn(sprite_t *sprite, int i, char charac);
void place_enn(sprite_t *sprite, int x, int y, int i);
void update_enn(sprite_t *sprite);
void move_enn(sprite_t *sprite);
void update_nb_enn(sprite_t *sprite);
void display_nb_tow(sfRenderWindow *window, sprite_t *sprite);
void display_wave(sfRenderWindow *window, sprite_t *sprite);
void display_pause(sfRenderWindow *window, sprite_t *sprite);
void display_menu_pause(sfRenderWindow *window, sprite_t *sprite);
void game(sfRenderWindow *window, sprite_t *sprite);
void draw_cursor(sfRenderWindow *window, sprite_t *sprite);
void display_gold(sprite_t *sprite, sfRenderWindow *window);
void display_life(sfRenderWindow *window, sprite_t *sprite);
void display_score(sprite_t *sprite);
void display_best_score_one(sprite_t *sprite);
void display_best_score_five(sprite_t *sprite);
void display_best_score_six(sprite_t *sprite);
void display_best_score_seven(sprite_t *sprite);
void display_best_score_height(sprite_t *sprite);
void display_best_score_nine(sprite_t *sprite);
void display_best_score_one(sprite_t *sprite);
void display_best_score_two(sprite_t *sprite);
void display_best_score_tree(sprite_t *sprite);
void display_best_score_four(sprite_t *sprite);
void free_tow_enn(sprite_t *sprite);
void click_pause(sfMouseButtonEvent event, sfRenderWindow *window, \
sprite_t *sprite, sfVector2i mouse);
void click_menu_pause(sfMouseButtonEvent event, sfRenderWindow *window, \
sprite_t *sprite, sfVector2i mouse);
sfSprite *little_bomb(sfRenderWindow *windows, sprite_t *sprites);
void draw_cursor_tree(sprite_t *sprite, sfRenderWindow *window, \
sfVector2i mouse);
void click_statue_trois(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse);
void if_click_statue_tree(sfMouseButtonEvent event, \
sfRenderWindow *window, sprite_t *sprite, sfVector2i mouse);
sfSprite *big_bomb(sfRenderWindow *windows, sprite_t *sprites);
void shoot_bomb(sprite_t *sprite, int a, sfVector2i mouse);
int my_atoi(char *str);
void save_score(sprite_t *sprite);
void save_mode_one(sprite_t *sprite);
void save_mode_two(sprite_t *sprite);
void save_mode_tree(sprite_t *sprite);
char *remplace_score(char *temp, char *tempa);

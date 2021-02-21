/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Context.h>
#include <SFML/Window/JoystickIdentification.h>
#include <SFML/Graphics/Export.h>
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
#include "rafik.h"
#include "richard.h"
#include "particule.h"
#include "rafik.h"

typedef struct clock_c
{
    sfClock *clock;
    sfTime time;
    float second;
} clock_s;

#include "fight.h"

typedef struct ennemies
{
    sfSprite *enn;
    sfTexture *enn_texture;
    clock_s clock;
    clock_s enn_clock;
    game_obj_R_t *buttons;
    sfIntRect rect;
    sfVector2f pos;
    int life;
    int in_live;
    float velocity;
    int tmp;
}ennemies_t;


typedef struct player_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    clock_s clock;
    int direct;
    int life;
} player_t;

typedef struct game_obj_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
} game_obj_t;

typedef struct tuto_s
{
    int executed;
    int action;
    int tmp;

    sfClock *clock;

    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;

    sfSprite *friend;
    sfTexture *friend_t;
    sfIntRect rect_friend;
    sfVector2f pos;
}tuto_t;

typedef struct scd_quest_s
{
    int nb_kills;
    int nb_win;

    sfSprite *sprite;
    sfTexture *texture;

    text_R_t *text;

    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
}scd_quest_t;

typedef struct quest_s
{
    scd_quest_t scd_quest;
    sfTexture *items;

    sfSprite *sprite;
    sfSprite *msg;
    sfSprite *arrow;
    sfTexture *arr_t;

    sfTexture *msg_t;
    int act;

    int x;
    int y;
    int message;
    int tmp;
    sfVector2f pos;
    sfIntRect rect;

    sfSprite *invent_s;
    sfTexture *invent_t;
    sfIntRect invent_rect;
}quest_t;

typedef struct end_script_s
{
    int tmp;
    int act;

    sfCircleShape *cinematic;
    sfVector2f cinematic_size;
    size_t cinematic_radius;

    text_R_t *text;

    sfSprite *bg;
    sfTexture *bg_t;

    sfSprite *bg2;
    sfTexture *bg2_t;

    sfSprite *gf;
    sfTexture *gf_t;
    sfIntRect gf_rect;
    sfVector2f pos;

    sfSprite *msg;
    sfTexture *msg_t;
    sfIntRect msg_rect;

    clock_R_t clock;
}end_script_t;

typedef struct rpg_s
{
    sfRenderWindow *win;
    sfEvent evnt;
    screen_t *screen;
    fight_t *fight;
    tuto_t tuto;
    end_script_t end;
    quest_t quest;
    game_obj_R_t *menu;
    text_R_t *text;
    clock_R_t *clock;
    clock_R_t clock_rect;
    clock_R_t *spawn;
    int menu_status;
    int fps;
    int music_volume;
    int sound_volume;
    int **map;
    game_obj_t perspec;
    sfSprite *cop;
    player_t player;
    int status;
    int save;
    sfSound *snd_clic;
    sfSound *snd_menu;
    sfSound *snd_tuto;
    sfSound *snd_main_music;
    sfSound *snd_win;
    sfSound *snd_loose;
    sfSound *snd_main_music_fight;
    sfSound *snd_fireball;
    sfSound *snd_shield;
    sfSound *snd_black_hole;
    sfSound *snd_heal;
    sfSound *snd_speed;
    sfSound *snd_win_fight;
    sfSound *snd_end;
    sfSound *snd_boss;
    int life;
    int tmp;
    int level;
}rpg_t;

//lib
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *src);
char *int_to_string(int num);
int my_strlength(char *str);
char *ftoa(float n, int afterpoint);

//Juan
void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *);
void global_event(rpg_t *rpg, game_obj_t *);
void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *);
int **get_map(void);
char *get_next_char(int fd, char c);
int init_save(rpg_t *rpg, game_obj_t *obj);
void check_plus_minus(rpg_t *rpg, sfVector2i mouse);
void fourth_act(__attribute__((unused)) rpg_t *rpg, end_script_t *end);
void fivth_act(__attribute__((unused)) rpg_t *rpg, end_script_t *end);
int final_act(rpg_t *rpg, end_script_t *end);
void set_end_script(rpg_t *rpg, end_script_t *end);
void end_script(rpg_t *rpg, end_script_t *end);
void first_act(rpg_t *rpg, end_script_t *end);
void second_act(rpg_t *rpg, end_script_t *end);
void third_act(rpg_t *rpg, end_script_t *end);

//graphic
void move_right(player_t *player);
void set_volume(rpg_t *rpg);
void stop_all_music(rpg_t *rpg);
void move_left(player_t *player);
void dont_move(player_t *player);
void move_down(player_t *player);
void move_up(player_t *player);
void init_player(player_t *obj);
void clics_handlings(sfMouseButtonEvent event, rpg_t *rpg, game_obj_t *obj);
void draw_options(rpg_t *rpg, sfRenderWindow *win);
void draw_menu(rpg_t *rpg, sfRenderWindow *win);
int main_rpg(void);
void clock_event(rpg_t *rpg, clock_s *clock);
void create_perspec(game_obj_t *perspec);
void move_rect(game_obj_t *obj, sfVector2f mouvement, rpg_t *rpg);
void keys_handlings(sfEvent event, rpg_t *rpg, game_obj_t *obj);
void handling_items(rpg_t *rpg);
void set_seconds_quests(scd_quest_t *quest);
void reset_ennemies(fight_t *fight);
struct spell_s init_spell(char *path, enum spells_names_s type, sfIntRect rect);
void generic_function_bg_quest(rpg_t *rpg);

//lib
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_getnbr(char *str);
int save_to_file(rpg_t *rpg, game_obj_t *obj);
int generate_random(int l, int r);
char *ftoa(float n, int afterpoint);
float stof(const char *s);
float get_distance(sfVector2f p1, sfVector2f p2);

//menu
void init_variables_for_particules(rpg_t *rpg);
fight_t *init_variables_for_fights(fight_t *fight);
void set_menu_sprites(rpg_t *rpg);
void menu_destroy(rpg_t *rpg);
void click_menu(rpg_t *rpg, sfVector2i mouse, game_obj_t *obj);
char *int_to_char(int nb);
game_obj_R_t create_object(char *filepath, sfVector2f pos, sfIntRect rect, \
enum BACK_R_s type);
void make_text(text_R_t *text, char *str, char *file);
void set2(rpg_t *rpg, char **name);
void initialize_text(rpg_t *rpg, char **name);
void check_mouse_pos_menu(rpg_t *rpg);
void check_mouse_menu_zero(rpg_t *rpg, sfVector2i mouse);
void press_button(rpg_t *rpg, BACK_R_t type);
void release_button(rpg_t *rpg, BACK_R_t type);
void click_menu_zero(rpg_t *rpg, sfVector2i mouse);
void click_start_menu(rpg_t *rpg, sfVector2i mouse, game_obj_t *obj, int nb);
void init_pause_menu(rpg_t *rpg);
void initialise_text(rpg_t *rpg, char **name __attribute__((unused)));
void initialize_text3(rpg_t *rpg, char **name);
void initialize_text2(rpg_t *rpg, char **name);
char *int_to_char(int nb);
game_obj_R_t modify_from_type(game_obj_R_t object, enum BACK_R_s type);
game_obj_R_t create_object(char *filepath, sfVector2f pos, sfIntRect rect, \
enum BACK_R_s type);
void make_text(text_R_t *text, char *str, char *file);
void malloc_everything(rpg_t *rpg);
void press_button(rpg_t *rpg, BACK_R_t type);
void release_button(rpg_t *rpg, BACK_R_t type);
void check_mouse_menu_one(rpg_t *rpg, sfVector2i mouse);
void check_mouse_menu_zero(rpg_t *rpg, sfVector2i mouse);

//tuto
void draw_tuto(sfRenderWindow *win, rpg_t *rpg, game_obj_t *obj);
void tuto(rpg_t *rpg, game_obj_t *obj);

//death
void script_death(rpg_t *rpg, game_obj_t *background);
void set_script_death(rpg_t *rpg, game_obj_t *background);
void draw_death(sfRenderWindow *win, rpg_t *rpg, game_obj_t *obj);
int script1_death(rpg_t *rpg, game_obj_t *background);


//fight
void display_fights(fight_t *fight, sfRenderWindow *win, rpg_t *rpg);
void update_fights(fight_t *fight, rpg_t *rpg);
void draw_fights(fight_t *fight, sfRenderWindow *win, rpg_t *rpg);
void player_deplacements(player_fight_t *player, fight_t *fight);
int dont_move_fight(player_fight_t *player);
int move_down_fight(player_fight_t *player);
int move_up_fight(player_fight_t *player);
int move_left_fight(player_fight_t *player);
int move_right_fight(player_fight_t *player);
void update_spell(fight_t *fight, rpg_t *rpg);
void launch_fireball(fight_t *fight, rpg_t *rpg);
void launch_shield(fight_t *fight, rpg_t *rpg);
void launch_black_hole(fight_t *fight, rpg_t *rpg);
void launch_heals(fight_t *fight, rpg_t *rpg);
void launch_speed(fight_t *fight, rpg_t *rpg);
void launch_spell(fight_t *fight, rpg_t *rpg);
void pos_rotat(sfVector2f *pos, sfVector2f player_pos, int rad,
sfSprite *sprt);
int update_black_holes(spell_t *spell, sfVector2f pos,
fight_t *fight, rpg_t *rpg);
int update_fireballs(spell_t *spell, sfVector2f pos,
fight_t *fight, rpg_t *rpg);
int update_shield(spell_t *spell, sfVector2f pos, fight_t *fight, rpg_t *rpg);
int update_health(spell_t *spell, sfVector2f pos, fight_t *fight,
__attribute__((unused)) rpg_t *rpg);
void init_values_before_fight(fight_t *fight);
int update_speed(spell_t *spell, sfVector2f pos,
__attribute__((unused)) fight_t *fight, __attribute__((unused)) rpg_t *rpg);
ennemies_t *init_boss(void);
void move_boss(fight_t *fight);
void attack_1(fight_t *fight __attribute__((unused)), float *);
void attack_2(fight_t *fight __attribute__((unused)), float *);
void attack_3(fight_t *fight __attribute__((unused)), float *);
spell_t *init_boss_spell(void);
void knock_back(player_fight_t *player, clock_s *clock, sfVector2f truc_1_2,
int tmp);
spell_t use_spell_two(spell_t spell, __attribute__((unused)) fight_t *fight,
__attribute__((unused)) int value, sfVector2f *delta);
spell_t use_spell(spell_t spell, fight_t *fight, int value);
void animation_black_hole_two(spell_t *spell);
void animation_black_hole(spell_t *spell);
void pos_rotat_two(sfVector2f *pos, sfVector2f player_pos, int rad,
sfSprite *sprt);
void pos_rotat_(sfVector2f *pos, sfVector2f player_pos, int rad,
sfSprite *sprt);
void check_touch_ennemie_black_hole_two(fight_t *fight, rpg_t *rpg,
spell_t *spell, int i);
void check_touch_ennemie_black_hole(fight_t *fight, rpg_t *rpg, spell_t *spell);
void display_cooldown_black_holes(float second, spell_t *spell);
int displays_cooldown_black(spell_t *spell, int *tmp);
void launch_first_black_hole(fight_t *fight, sfVector2f player_pos);
void change_position_black_hole(spell_t *spell,
__attribute__((unused)) sfVector2f pos);
void black_hole_damage_player(fight_t *fight, rpg_t *rpg, spell_t *spell);
void boss_anim(fight_t *fight);
void move_boss_two(fight_t *fight, float truc1, float truc2);
void move_boss(fight_t *fight);
void display_rect(fight_t *fight, sfRenderWindow *win,
__attribute__((unused)) rpg_t *rpg);
void display_enns_fight(fight_t *fight, sfRenderWindow *win,
__attribute__((unused)) rpg_t *rpg, int i);
void display_spell(fight_t *fight, sfRenderWindow *win, rpg_t *rpg);
void display_enns(fight_t *fight, sfRenderWindow *win, rpg_t *rpg);
void display_spells(fight_t *fight, sfRenderWindow *win,
__attribute__((unused)) rpg_t *rpg);
void feux_d_artifices(rpg_t *rpg);
void set_particules_for_feux_d_artifices(particle_environment_t *particle);
void set_particules_default(particle_environment_t *particle);
void win_boss_fight(fight_t *fight, rpg_t *rpg);
void win_normal_fight(fight_t *fight, rpg_t *rpg);
void check_touch_ennemie_fireball_two(fight_t *fight, rpg_t *rpg,
spell_t *spell, int i);
void check_touch_ennemie_fireball(fight_t *fight, rpg_t *rpg, spell_t *spell);
void set_cooldown(float res, spell_t *spell);
void display_cooldown_fireball(float second, spell_t *spell);
int cooldown_fireball(spell_t *spell);
void animation_fireball(spell_t *spell);
void change_position_fireball(spell_t *spell, __attribute__((unused))
sfVector2f pos);
void animation_health(spell_t *spell);
void set_cooldown_health(float res, spell_t *spell);
void display_cooldown_health(float second, spell_t *spell);
int cooldown_health(spell_t *spell, __attribute__((unused)) fight_t *fight);
void set_cooldown_shield(float res, spell_t *spell);
void display_cooldown_shield(float second, spell_t *spell);
int cooldown_shield(spell_t *spell);
void animation_shield(spell_t *spell);
void check_touch_ennemie_shield_two(fight_t *fight, rpg_t *rpg, spell_t *spell,
int i);
void check_touch_ennemie_shield(fight_t *fight, rpg_t *rpg, spell_t *spell);
void animation_speed(spell_t *spell);
void set_cooldown_speed(float res, spell_t *spell);
void display_cooldown_speed(float second, spell_t *spell);
int cooldown_speed(spell_t *spell);
void init_health_speeds(spell_t *spell, spells_names_t type,  sfIntRect rect);
void init_black_hole(spell_t *spell, spells_names_t type,  sfIntRect rect);
int dont_move_touch(player_fight_t *player);
int move_down_touch(player_fight_t *player);
int move_up_touch(player_fight_t *player);
int move_left_touch(player_fight_t *player);
int move_right_touch(player_fight_t *player);
sfVector2f calc_movement_enn(fight_t *fight, int i);
sfVector2f enn_live_green(fight_t *fight, int i, int *tmp, sfVector2f truc_1_2);
sfVector2f enn_in_live_calcs(fight_t *fight, int i, int *tmp);
void enn_touchs_player(fight_t *fight, int tmp, sfVector2f truc_1_2);
void ennemies_deplacements(fight_t *fight, __attribute__((unused)) rpg_t *rpg);
int pos_zombie_condition(player_fight_t *player, float truc1, float truc2);
int pos_zombie(player_fight_t *player, float truc1, float truc2, int tmp2);
void change_rect_direction_player(player_fight_t *player, int direct);
void moving_clocked_enn(fight_t *fight, int i, int *tmp);
void where_to_move(ennemies_t *ennemies, float truc1, float truc2);
void animate_enemy(ennemies_t *ennemies);
void shield_damage_enn(fight_t *fight, rpg_t *rpg, spell_t *spell);
void boss_attack(fight_t *fight, float *max);


void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *);
void global_event(rpg_t *rpg, game_obj_t *);
void draw_statue(rpg_t *rpg, sfRenderWindow *win, game_obj_t *);
int **get_map(void);
char *get_next_char(int fd, char c);

//spawn
void fights_spawns(rpg_t *rpg, game_obj_t *obj);

//end_script
void draw_end_script(rpg_t *rpg, sfRenderWindow *win);
void end_script(rpg_t *rpg, end_script_t *end);
int final_act(rpg_t *rpg, end_script_t *end);

//save
char *stock_info2(char *str, int *size_tmp);
float generic_save_stof(char *str, int *size_tmp);
int generic_save(char *str, int *size_tmp);
void get_str3(char *str, int tmp, rpg_t *rpg,
__attribute__((unused)) game_obj_t *obj);
void put_in_file(int nb, int fd);
void put_in_file_with_write(int nb, int fd);
int save_to_file_three(rpg_t *rpg, int fd);

//init
void set_int_seconds_quests(scd_quest_t *quest);
void set_seconds_quests(scd_quest_t *quest);
void set_basics_for_fight(fight_t *fight, char *path, sfIntRect rect,
sfVector2f pos);
void set_enn2(ennemies_t *enn);
ennemies_t set_enn(int i);
void init_variables_for_particules(rpg_t *rpg);
void create_and_set_background(fight_t *fight);
game_obj_R_t create_object_fight(char *filepath, sfVector2f pos, sfIntRect rect,
enum BACK_R_s type);
fight_t *init_three(fight_t *fight);
void init_end_script(end_script_t *end);

//sets
void set_volume(rpg_t *rpg);
void stop_all_music(rpg_t *rpg);
void set_music_loop(rpg_t *rpg);
sfSound *create_sound(char *path);
void set_musics(rpg_t *rpg);
void my_set_ints(rpg_t *rpg, clock_s *clock);
void set_rpg_tuto(tuto_t *tuto);
void set_quest_data(quest_t *quest);
void set_quest(quest_t *quest);

//creates
void create_and_set(sfSprite *sprite, sfTexture *texture, char *path);
void create_backgrounds_end_script(end_script_t *end);
void create_msg_and_txt_end_script(end_script_t *end);
void create_gf_and_circle(end_script_t *end);
void create_arrow(quest_t *quest);
void create_window(rpg_t *rpg);


//handling
float angle(__attribute__((unused)) rpg_t *rpg, sfVector2f pos);
void generic_function_bg_quest_part_two(rpg_t *rpg);
void generic_function_bg_quest(rpg_t *rpg);
void change_item_part_two(rpg_t *rpg);
void change_item(rpg_t *rpg);

//global_event
int player_deplacement(rpg_t *rpg);
void analyse_event(rpg_t *rpg, game_obj_t *obj);
void move_x(sfVector2i pos, game_obj_t *obj, rpg_t *rpg, int offset);
void move_y(sfVector2i pos, game_obj_t *obj, rpg_t *rpg, int offset);
void move_rect(game_obj_t *obj, sfVector2f mouvement, rpg_t *rpg);
float speed(void);
void enns_loop(float speed, ennemies_t *enns);
void upgrade_ennemies(ennemies_t *enns, int act, fight_t *fight);
void global_event_statue_three(rpg_t *rpg, game_obj_t *background);
void display_fps(rpg_t *rpg);

//draw_statue
void display_item(sfRenderWindow *win, rpg_t *rpg,
game_obj_t *obj __attribute__((unused)));
void display_inventory(sfRenderWindow *win, rpg_t *rpg);
void draw_statues(rpg_t *rpg, sfRenderWindow *win, game_obj_t *obj);


void destroy(game_obj_t *obj, rpg_t *rpg);
void my_set_sprites(game_obj_t *obj, rpg_t *rpg);
void fireball_damage_player(fight_t *fight, rpg_t *rpg, spell_t *spell);
void upgrade_player(fight_t *fight, int nb_win);
void set_cooldown_(float res, spell_t *spell);
void begin_action_three_two(rpg_t *rpg,
__attribute__((unused)) game_obj_t *background);
void begin_action_three(rpg_t *rpg, game_obj_t *background);
void action_three(rpg_t *rpg, game_obj_t *background);
void action_two(rpg_t *rpg, game_obj_t *background);

#endif /* !RPG_H_ */

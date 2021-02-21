/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void create_pause(sprite_t *sprite)
{
    sfTexture *pause_txt = sfTexture_createFromFile\
    ("sprite/pause_button_sized.png", NULL);
    sfTexture *pause_menu_txt = sfTexture_createFromFile\
    ("sprite/pause_menu.png", NULL);

    sprite->button_pause_sprt = sfSprite_create();
    sfSprite_setTexture(sprite->button_pause_sprt, pause_txt, sfTrue);
    sprite->menu_pause_sprt = sfSprite_create();
    sfSprite_setTexture(sprite->menu_pause_sprt, pause_menu_txt, sfTrue);
}

void my_set_sprites_tree(sprite_t *sprites, sfRenderWindow *window, \
clock_s *clock)
{
    sprites->text_best_score_one = sfText_create();
    sprites->text_best_score_two = sfText_create();
    sprites->text_best_score_tree = sfText_create();
    sprites->text_best_score_four = sfText_create();
    sprites->text_best_score_five = sfText_create();
    sprites->text_best_score_six = sfText_create();
    sprites->text_best_score_seven = sfText_create();
    sprites->text_best_score_height = sfText_create();
    sprites->text_best_score_nine = sfText_create();
}

void my_set_sprites_two(sprite_t *sprites, sfRenderWindow *window, \
clock_s *clock)
{
    sprites->menu_btn = menu_btn(window, sprites);
    sprites->lvl = lvl(window, sprites);
    sprites->map = map(window, sprites);
    sprites->text_score = sfText_create();
    sprites->tower_1 = tower_1(window, sprites);
    sprites->tower_2 = tower_2(window, sprites);
    sprites->tower_3 = tower_3(window, sprites);
    sprites->tower_4 = tower_4(window, sprites);
    sprites->little_bomb = little_bomb(window, sprites);
    sprites->big_bomb = big_bomb(window, sprites);
    sprites->sound_volume = sound_volume(window, sprites);
    sprites->back_opt = back_opt(window);
    sprites->circle = sfCircleShape_create();
    my_set_sprites_tree(sprites, window, clock);
}

void create_and_set_musics(sprite_t *sprites)
{
    sprites->music_chill = sfMusic_createFromFile("sprite/chill.ogg");
    sprites->music_hard = sfMusic_createFromFile("sprite/hard.ogg");
    sprites->tow_input = sfMusic_createFromFile("sprite/turret_put.ogg");
    sprites->tow_shot = sfMusic_createFromFile("sprite/turret_shot.ogg");
    sprites->bomb_sound = sfMusic_createFromFile("sprite/bomb.ogg");
    sfMusic_setVolume(sprites->tow_input, 6.5);
    sfMusic_setVolume(sprites->tow_shot, 6.5);
    sfMusic_setVolume(sprites->bomb_sound, 80);
}

void my_set_sprites(sprite_t *sprites, sfRenderWindow *window, clock_s *clock)
{
    sprites->enn = malloc(sizeof(ennemies_t) * (10000 + 1));
    sprites->tow = malloc(sizeof(towers_t) * (100 + 1));
    sprites->hight = 1920;
    sprites->weidth = 1080;
    create_and_set_musics(sprites);
    clock->clock = sfClock_create();
    create_pause(sprites);
    sprites->text_menu = sfText_create();
    sprites->text_display_score = sfText_create();
    sprites->text_loose = sfText_create();
    sprites->font_menu = sfFont_createFromFile("sprite/menu.ttf");
    sprites->text_gold = sfText_create();
    sprites->text_nb_tow = sfText_create();
    sprites->text_wave = sfText_create();
    sprites->font_gold = sfFont_createFromFile("sprite/gold.TTF");
    sprites->text_life = sfText_create();
    sprites->font_life = sfFont_createFromFile("sprite/gold.TTF");
    my_set_sprites_two(sprites, window, clock);
}
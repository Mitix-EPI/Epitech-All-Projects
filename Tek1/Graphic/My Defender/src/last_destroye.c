/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void destroy_sprite_two(sfRenderWindow *window, sprite_t *sprite)
{
    sfMusic_destroy(sprite->music_chill);
    sfMusic_destroy(sprite->music_hard);
    sfMusic_destroy(sprite->tow_shot);
    sfMusic_destroy(sprite->tow_input);
    sfMusic_destroy(sprite->bomb_sound);
    sfText_destroy(sprite->text_gold);
    sfText_destroy(sprite->text_menu);
    sfFont_destroy(sprite->font_gold);
    sfFont_destroy(sprite->font_menu);
    sfSprite_destroy(sprite->menu_btn);
    sfSprite_destroy(sprite->sound_volume);
    sfSprite_destroy(sprite->back_opt);
    sfSprite_destroy(sprite->map);
    sfSprite_destroy(sprite->tower_1);
    sfSprite_destroy(sprite->tower_2);
    sfSprite_destroy(sprite->tower_3);
    sfSprite_destroy(sprite->tower_4);
}

void destroy_sprite(sfRenderWindow *window, sprite_t *sprite)
{
    destroy_sprite_two(window, sprite);
    free(sprite->name);
    sfSprite_destroy(sprite->button_pause_sprt);
    sfSprite_destroy(sprite->menu_pause_sprt);
    sfRenderWindow_destroy(window);
}
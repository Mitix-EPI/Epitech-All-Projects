/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void display_nb_tow(sfRenderWindow *window, sprite_t *sprite)
{
    char *text = cat(int_to_string(sprite->tow_alive), "/99");

    sfText_setString(sprite->text_nb_tow, text);
    sfText_setFont(sprite->text_nb_tow, sprite->font_life);
    sfText_setCharacterSize(sprite->text_nb_tow, 35 * sprite->hight / 1920);
    sfText_setColor(sprite->text_nb_tow, sfGreen);
    sfRenderWindow_drawText(window, sprite->text_nb_tow, NULL);
    sfText_setPosition(sprite->text_nb_tow, (sfVector2f){croix\
    (783, 'l', sprite), croix(955, 'h', sprite)});
    free(text);
}

void display_wave(sfRenderWindow *window, sprite_t *sprite)
{
    char *text = cat("wave :", int_to_string(sprite->vague));

    sfText_setString(sprite->text_wave, text);
    sfText_setFont(sprite->text_wave, sprite->font_life);
    sfText_setCharacterSize(sprite->text_wave, 50 * sprite->hight / 1920);
    sfText_setColor(sprite->text_wave, sfBlack);
    sfRenderWindow_drawText(window, sprite->text_wave, NULL);
    sfText_setPosition(sprite->text_wave, (sfVector2f){croix\
    (871, 'l', sprite), croix(1, 'h', sprite)});
    free(text);
}

void display_pause(sfRenderWindow *window, sprite_t *sprite)
{
    sfSprite_setScale(sprite->button_pause_sprt, (sfVector2f) {\
    croix(1, 'l', sprite), croix(1, 'h', sprite)});
    sfSprite_setPosition(sprite->button_pause_sprt, (sfVector2f) {\
    croix(5, 'l', sprite), croix(5, 'h', sprite)});
    sfRenderWindow_drawSprite(window, sprite->button_pause_sprt, NULL);
}

void display_menu_pause(sfRenderWindow *window, sprite_t *sprite)
{
    if (sprite->pause == 1) {
        sfSprite_setScale(sprite->menu_pause_sprt, (sfVector2f) {\
        croix(1, 'l', sprite), croix(1, 'h', sprite)});
        sfRenderWindow_drawSprite(window, sprite->menu_pause_sprt, NULL);
    }
}

void game(sfRenderWindow *window, sprite_t *sprite)
{
    if (sprite->pause == 0) {
        update_type_enn(sprite);
        move_enn(sprite);
        update_enn(sprite);
        shot_tow(sprite, window);
        update_waves(sprite);
    }
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setScale(sprite->map, (sfVector2f){1 * sprite->hight / 1920\
    , 1 * sprite->weidth / 1080});
    sfRenderWindow_drawSprite(window, sprite->map, NULL);
    draw_tow(sprite, window);
    draw_enn(sprite, window);
    display_gold(sprite, window);
    display_pause(window, sprite);
    display_life(window, sprite);
    display_wave(window, sprite);
    display_nb_tow(window, sprite);
    display_menu_pause(window, sprite);
    draw_cursor(window, sprite);
    sfRenderWindow_display(window);
}
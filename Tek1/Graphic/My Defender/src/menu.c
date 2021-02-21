/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_huter.c
*/

#include "../my_tower.h"

void display_menu_text(sprite_t *sprite)
{
    sfVector2f menu_position = {sprite->hight / 6, sprite->weidth / \
    2 - sprite->weidth / 5};
    char *text = "MY TOWER DEFENSE";

    sfText_setString(sprite->text_menu, text);
    sfText_setFont(sprite->text_menu, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_menu, 120 * sprite->hight / 1920);
    sfText_setColor(sprite->text_menu, sfRed);
    sfText_setPosition(sprite->text_menu, menu_position);
}

void display_score(sprite_t *sprite)
{
    char *text = cat("score = ", int_to_string(sprite->score = (sprite->gold \
    - (sprite->tow_alive * 50) + sprite->life * 1.5) * sprite->vague));

    sfText_setString(sprite->text_score, text);
    sfText_setFont(sprite->text_score, sprite->font_menu);
    sfText_setCharacterSize(sprite->text_score, 75 * \
    sprite->hight / 1920);
    sfText_setColor(sprite->text_score, sfRed);
    sfText_setPosition(sprite->text_score, (sfVector2f)\
    {croix(1920 / 2.4, 'l', sprite), croix(1080 / 1.5, 'h', sprite)});
}

void draw_menu(sfRenderWindow *window, sprite_t *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->menu_btn, NULL);
    sfSprite_setScale(sprite->menu_btn, (sfVector2f){1.81 * sprite->hight \
    / 1920, 1.83 * sprite->weidth / 1080});
    sfSprite_setPosition( sprite->menu_btn, (sfVector2f){50 * sprite->hight \
    / 900, 270 * sprite->weidth / 500});
    display_menu_text(sprite);
    sfRenderWindow_drawText(window, sprite->text_menu, NULL);
    sfRenderWindow_display(window);
}

void choose_lvl(sfRenderWindow *window, sprite_t *sprite)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite->lvl, NULL);
    display_best_scores(sprite, window);
    sfSprite_setScale(sprite->lvl, (sfVector2f){1 * sprite->hight / 1920\
    , 1 * sprite->weidth / 1080});
    sfRenderWindow_display(window);
}
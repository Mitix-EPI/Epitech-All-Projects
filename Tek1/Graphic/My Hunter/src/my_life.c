/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_life
*/

#include "../include/my.h"

void set_score_text(sfRenderWindow *window, window_t *w)
{
    sfVector2f txt_score_pos = {813, 20};
    sfColor sfGreen = sfColor_fromRGB(0, 255, 0);
    sfText_setString(w->text, w->str_score);
    sfText_setFont(w->text, w->font);
    sfText_setCharacterSize(w->text, 30);
    sfText_setPosition(w->text, txt_score_pos);
    sfText_setColor(w->text, sfGreen);
    sfRenderWindow_drawText(window, w->text, NULL);
}

void my_display_life(sfRenderWindow *window, window_t *w)
{
    sfVector2f life_pos = {200, 20};
    sfVector2f size = {0.40f, 0.40f};
    sfSprite_setTexture(w->slife, w->tlife, sfTrue);
    sfSprite_setTextureRect(w->slife, w->rect_life);
    sfSprite_setScale(w->slife, size);
    sfSprite_setPosition(w->slife, life_pos);
    set_score_text(window, w);
    sfRenderWindow_drawSprite(window, w->slife, NULL);
}
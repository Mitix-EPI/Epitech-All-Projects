/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_sets_menu
*/

#include "../include/my.h"

void set_text2(window_t *w)
{
    sfVector2f pos_button1 = {1200, 300};
    sfVector2f pos_button2 = {1200, 400};
    sfVector2f txt_pos = {1300.0f, 300.0f};
    sfVector2f txt_pos1 = {1350.0f, 200.0f};
    sfText_setPosition(w->text, txt_pos1);
    sfText_setPosition(w->text1, txt_pos);
    sfText_setColor(w->text, sfGreen);
    sfText_setColor(w->text1, sfRed);
    w->tplay = sfTexture_createFromFile("assets/play.png", NULL);
    w->tquit = sfTexture_createFromFile("assets/quit.png", NULL);
    sfSprite_setTexture(w->splay, w->tplay, sfTrue);
    sfSprite_setTextureRect(w->splay, w->button);
    sfSprite_setPosition(w->splay, pos_button1);
    sfSprite_setTexture(w->squit, w->tquit, sfTrue);
    sfSprite_setTextureRect(w->squit, w->button);
    sfSprite_setPosition(w->squit, pos_button2);
    sfSprite_setTexture(w->sbg0, w->tbg0, sfTrue);
}
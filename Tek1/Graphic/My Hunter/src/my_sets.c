/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** my_sets
*/

#include "../include/my.h"

void set_rect_anim(window_t *w)
{
    w->rect_tmax.top = 0;
    w->rect_tmax.left = 0;
    w->rect_tmax.width = 201;
    w->rect_tmax.height = 151;
    w->rect_scope.top = 0;
    w->rect_scope.left = 0;
    w->rect_scope.width = 930;
    w->rect_scope.height = 615;
    w->rect_ufo.top = 0;
    w->rect_ufo.left = 0;
    w->rect_ufo.width = 512;
    w->rect_ufo.height = 160;
    w->rect_life.top = 480;
    w->rect_life.left = 0;
    w->rect_life.height = 240;
    w->rect_life.width = 720;
}

void set_animations_variables(sfRenderWindow *window, window_t *w)
{
    w->clock = sfClock_create();
    set_rect_anim(w);
    w->ufo_pos_y = printrandoms(-10, 300);
    w->second = 2.0;
    w->speed_mob = 2;
    w->score = 0;
    w->life = 3;
    w->tmax_pos_x = -550;
    w->ufo_pos_x = printrandoms(-1000, -450);
}

void set_text_t_a2(window_t *w)
{
    sfVector2f pos_button1 = {1200, 300};
    sfVector2f pos_button2 = {1200, 400};
    w->text = sfText_create();
    w->text1 = sfText_create();
    w->text_score = sfText_create();
    sfText_setString(w->text, "REJOUER");
    sfText_setString(w->text1, "QUITTER");
    sfText_setFont(w->text, w->font);
    sfText_setFont(w->text1, w->font);
    sfText_setCharacterSize(w->text, 70);
    sfText_setCharacterSize(w->text1, 70);
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

void set_text_t_a(window_t *w)
{
    w->font = sfFont_createFromFile("assets/KeepCalm.ttf");
    w->sbg0 = sfSprite_create();
    w->splay = sfSprite_create();
    w->squit = sfSprite_create();
    sfVector2f txt_score_pos = {780, 400};
    sfVector2f txt_pos = {1300.0f, 300.0f};
    sfVector2f txt_pos1 = {1270.0f, 200.0f};
    sfColor sfRed = sfColor_fromRGB(255, 0, 0);
    sfColor sfGreen = sfColor_fromRGB(0, 255, 0);
    set_text_t_a2(w);
    sfText_setPosition(w->text, txt_pos1);
    sfText_setPosition(w->text1, txt_pos);
    sfText_setColor(w->text, sfGreen);
    sfText_setColor(w->text1, sfRed);
    sfSprite_setTexture(w->sbg0, w->tbg0, sfTrue);
    sfText_setString(w->text_score, w->str_score);
    sfText_setFont(w->text_score, w->font);
    sfText_setCharacterSize(w->text_score, 150);
    sfText_setPosition(w->text_score, txt_score_pos);
    sfText_setColor(w->text_score, sfGreen);
}

void set_text(window_t *w)
{
    w->sbg0 = sfSprite_create();
    w->splay = sfSprite_create();
    w->squit = sfSprite_create();
    w->button.top = 0;
    w->button.left = 0;
    w->button.width = 250;
    w->button.height = 75;
    w->font = sfFont_createFromFile("assets/KeepCalm.ttf");
    w->text = sfText_create();
    w->text1 = sfText_create();
    sfText_setString(w->text, "JOUER");
    sfText_setString(w->text1, "QUITTER");
    sfText_setFont(w->text, w->font);
    sfText_setFont(w->text1, w->font);
    sfText_setCharacterSize(w->text, 70);
    sfText_setCharacterSize(w->text1, 70);
    set_text2(w);
}
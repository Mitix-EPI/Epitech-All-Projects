/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

#include "rpg.h"
#include "my.h"

void while_init(rpg_t *rpg)
{
    for (int i = 0; i < 4; i += 1) {
        rpg->text[i].size = 50;
        rpg->text[i].pos.x = 210;
        rpg->text[i].pos.y = 228 + (i * 200);
        rpg->text[i].type = SIDONIA + i;
    }
    for (int i = 4; i < 7; i += 1) {
        rpg->text[i].size = 50;
        rpg->text[i].pos.x = 803;
        rpg->text[i].pos.y = 278 + ((i - 4) * 225);
        rpg->text[i].type = SIDONIA + i;
    }

}

void initialize_text(rpg_t *rpg, char **name)
{
    while_init(rpg);
    rpg->text[21].size = 100;
    rpg->text[21].pos.x = 730;
    rpg->text[21].pos.y = 50;
    rpg->text[21].type = SIDONIA;
    rpg->text[7].size = 50;
    rpg->text[7].pos.x = 803;
    rpg->text[7].pos.y = 228;
    rpg->text[7].type = FPS;
    initialize_text2(rpg, name);
}

void make_saves(rpg_t *rpg, char **name)
{
    make_text(&rpg->text[14], "First", "assets/fonts/virus2.TTF");
    make_text(&rpg->text[15], "Second", "assets/fonts/virus2.TTF");
    make_text(&rpg->text[16], "Third", "assets/fonts/virus2.TTF");
    for (int i = 22; i < 24; i += 1)
        make_text(&rpg->text[i], name[i - 4], "assets/fonts/virus2.TTF");
}

void set3(rpg_t *rpg, char **name)
{
    rpg->menu[14] = create_object("assets/sprites/menu/button.png",
    (sfVector2f){743, 500}, (sfIntRect){0, 0, 310, 78}, SOUND);
    rpg->menu[15] = create_object("assets/sprites/menu/minus.png",
    (sfVector2f){680, 700}, (sfIntRect){0, 0, 200, 200}, MINUS_MUSIC);
    rpg->menu[16] = create_object("assets/sprites/menu/plus.png",
    (sfVector2f){1160, 700}, (sfIntRect){0, 0, 200, 200}, PLUS_MUSIC);
    rpg->menu[17] = create_object("assets/sprites/menu/background_menu.png",
    (sfVector2f){-10, -10}, (sfIntRect){0, 0, 1026, 642}, BACKGROUND);
    for (int i = 0; i < 14; i += 1)
        make_text(&rpg->text[i], name[i], "assets/fonts/virus2.TTF");
    for (int i = 18; i < 22; i += 1)
        make_text(&rpg->text[i], name[i - 4], "assets/fonts/virus2.TTF");
    make_saves(rpg, name);
    for (int i = 0; i < 3; i += 1)
        rpg->clock[i].clock = sfClock_create();
}

void set2(rpg_t *rpg, char **name)
{
    rpg->menu[0] = create_object("assets/sprites/menu/logo.png",
    (sfVector2f){1550, 50}, (sfIntRect){0, 0, 200, 200}, SIDONIA);
    rpg->menu[18] = create_object("assets/sprites/menu/pause.png",
    (sfVector2f){20, 20}, (sfIntRect){0, 0, 100, 100}, PAUSE);
    rpg->menu[8] = create_object("assets/sprites/menu/button.png",
    (sfVector2f){743, 200}, (sfIntRect){0, 0, 310, 78}, FPS);
    rpg->menu[9] = create_object("assets/sprites/menu/minus.png",
    (sfVector2f){680, 400}, (sfIntRect){0, 0, 200, 200}, MINUS_FPS);
    rpg->menu[10] = create_object("assets/sprites/menu/plus.png",
    (sfVector2f){1160, 400}, (sfIntRect){0, 0, 200, 200}, PLUS_FPS);
    rpg->menu[11] = create_object("assets/sprites/menu/button.png",
    (sfVector2f){743, 100}, (sfIntRect){0, 0, 310, 78}, MUSIC);
    rpg->menu[12] = create_object("assets/sprites/menu/minus.png",
    (sfVector2f){680, 300}, (sfIntRect){0, 0, 200, 200}, MINUS_EFFECT);
    rpg->menu[13] = create_object("assets/sprites/menu/plus.png",
    (sfVector2f){1160, 300}, (sfIntRect){0, 0, 200, 200}, PLUS_EFFECT);
    set3(rpg, name);
}
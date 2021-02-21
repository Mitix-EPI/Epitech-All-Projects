/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu
*/

#include "rpg.h"
#include "my.h"

void init_pause_menu(rpg_t *rpg)
{
    for (int i = 4; i < 7; i += 1) {
        rpg->text[i + 14].size = 50;
        rpg->text[i + 14].pos.x = 803;
        rpg->text[i + 14].pos.y = 278 + ((i - 4) * 225);
        rpg->text[i + 14].type = SIDONIA + i;
    }
    for (int i = 22; i < 24; i += 1) {
        rpg->text[i].size = 100;
        rpg->text[i].pos.x = 1520;
        rpg->text[i].pos.y = 940;
        rpg->text[i].type = LEVEL;
    }

}

void initialise_text(rpg_t *rpg, char **name __attribute__((unused)))
{
    rpg->text[14].size = 50;
    rpg->text[14].pos.x = 803;
    rpg->text[14].pos.y = 278;
    rpg->text[14].type = SAVE;
    rpg->text[15].size = 50;
    rpg->text[15].pos.x = 803;
    rpg->text[15].pos.y = 503;
    rpg->text[15].type = SAVE;
    rpg->text[16].size = 50;
    rpg->text[16].pos.x = 803;
    rpg->text[16].pos.y = 728;
    rpg->text[16].type = SAVE;
    rpg->text[17].size = 50;
    rpg->text[17].pos.x = 803;
    rpg->text[17].pos.y = 728;
    rpg->text[17].type = SAVE;
    init_pause_menu(rpg);
}

void initialize_text3(rpg_t *rpg, char **name)
{
    rpg->text[11].size = 75;
    rpg->text[11].pos.x = 900;
    rpg->text[11].pos.y = 300;
    rpg->text[11].type = MUSIC;
    name[11] = int_to_char(rpg->music_volume);
    rpg->text[12].size = 50;
    rpg->text[12].pos.x = 803;
    rpg->text[12].pos.y = 528;
    rpg->text[12].type = SOUND;
    rpg->text[13].size = 75;
    rpg->text[13].pos.x = 900;
    rpg->text[13].pos.y = 700;
    rpg->text[13].type = SOUND;
    name[13] = int_to_char(rpg->sound_volume);
    initialise_text(rpg, name);
}

void initialize_text2(rpg_t *rpg, char **name)
{
    rpg->text[8].size = 75;
    rpg->text[8].pos.x = 900;
    rpg->text[8].pos.y = 400;
    rpg->text[8].type = FPS;
    name[8] = int_to_char(rpg->fps);
    rpg->text[9].size = 100;
    rpg->text[9].pos.x = 1520;
    rpg->text[9].pos.y = 940;
    rpg->text[9].type = BACK;
    rpg->text[10].size = 50;
    rpg->text[10].pos.x = 803;
    rpg->text[10].pos.y = 128;
    rpg->text[10].type = MUSIC;
    initialize_text3(rpg, name);
}
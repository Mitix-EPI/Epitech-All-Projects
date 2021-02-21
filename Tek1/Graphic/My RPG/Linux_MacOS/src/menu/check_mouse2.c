/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"

void press_button(rpg_t *rpg, BACK_R_t type)
{
    for (int i = 0; i < 19; i += 1)
        if (rpg->menu[i].type == type) {
            rpg->menu[i].rect.left = rpg->menu[i].rect.width;
            sfSound_play(rpg->snd_clic);
        }
}

void release_button(rpg_t *rpg, BACK_R_t type)
{
    for (int i = 0; i < 19; i += 1)
        if (rpg->menu[i].type == type)
            rpg->menu[i].rect.left = 0;
}

void check_mouse_menu_one(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 250 && mouse.y < 359.2)
        press_button(rpg, FPS);
    else
        release_button(rpg, FPS);
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 475 && mouse.y < 584.2)
        press_button(rpg, SOUND);
    else
        release_button(rpg, SOUND);
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 700 && mouse.y < 809.2)
        press_button(rpg, BACK);
    else
        release_button(rpg, BACK);
}

void check_mouse_menu_zero(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 200 && mouse.y < 309.2)
        press_button(rpg, PLAY);
    else
        release_button(rpg, PLAY);
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 400 && mouse.y < 509.2)
        press_button(rpg, CONTINUE);
    else
        release_button(rpg, CONTINUE);
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 600 && mouse.y < 709.2)
        press_button(rpg, OPTIONS);
    else
        release_button(rpg, OPTIONS);
    if (mouse.x > 152 && mouse.x < 584 &&
    mouse.y > 800 && mouse.y < 909.2)
        press_button(rpg, QUIT);
    else
        release_button(rpg, QUIT);
}
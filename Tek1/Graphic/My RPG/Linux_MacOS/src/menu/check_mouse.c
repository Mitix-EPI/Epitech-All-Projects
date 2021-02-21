/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"

void check_mouse_menu_two(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 680 && mouse.x < 760 &&
    mouse.y > 400 && mouse.y < 480)
        press_button(rpg, PLUS_FPS);
    else
        release_button(rpg, PLUS_FPS);
    if (mouse.x > 1160 && mouse.x < 1240 &&
    mouse.y > 400 && mouse.y < 480)
        press_button(rpg, MINUS_FPS);
    else
        release_button(rpg, MINUS_FPS);
}

void check_mouse_menu_three(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 680 && mouse.x < 760 &&
    mouse.y > 700 && mouse.y < 780)
        press_button(rpg, PLUS_MUSIC);
    else
        release_button(rpg, PLUS_MUSIC);
    if (mouse.x > 1160 && mouse.x < 1240 &&
    mouse.y > 700 && mouse.y < 780)
        press_button(rpg, MINUS_MUSIC);
    else
        release_button(rpg, MINUS_MUSIC);
    if (mouse.x > 680 && mouse.x < 760 &&
    mouse.y > 300 && mouse.y < 380)
        press_button(rpg, PLUS_EFFECT);
    else
        release_button(rpg, PLUS_EFFECT);
    if (mouse.x > 1160 && mouse.x < 1240 &&
    mouse.y > 300 && mouse.y < 380)
        press_button(rpg, MINUS_EFFECT);
    else
        release_button(rpg, MINUS_EFFECT);
}

void check_mouse_six(rpg_t *rpg, sfVector2i mouse)
{
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 250 && mouse.y < 359.2)
        rpg->menu[19].rect.left = rpg->menu[19].rect.width;
    else
        rpg->menu[19].rect.left = 0;
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 475 && mouse.y < 584.2)
        rpg->menu[20].rect.left = rpg->menu[20].rect.width;
    else
        rpg->menu[20].rect.left = 0;
    if (mouse.x > 743 && mouse.x < 1177 &&
    mouse.y > 700 && mouse.y < 809.2)
        rpg->menu[21].rect.left = rpg->menu[21].rect.width;
    else
        rpg->menu[21].rect.left = 0;
}

void check_mouse_pos_menu(rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win);

    if (rpg->menu_status == 0)
        check_mouse_menu_zero(rpg, mouse);
    else if (rpg->menu_status == 1)
        check_mouse_menu_one(rpg, mouse);
    else
        if (rpg->menu_status == 2)
            check_mouse_menu_two(rpg, mouse);
        else if (rpg->menu_status == 3)
            check_mouse_menu_three(rpg, mouse);
    if (rpg->menu_status == 6)
        check_mouse_six(rpg, mouse);
    for (int i = 0; i < 22; i += 1)
        sfSprite_setTextureRect(rpg->menu[i].sprite, rpg->menu[i].rect);
}
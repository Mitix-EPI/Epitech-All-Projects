/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** global_event
*/

#include "my.h"
#include "rpg.h"
#include "rafik.h"

float speed(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        return (5);
    return (1);
}

void rect_pause(sfVector2i mouse, rpg_t *rpg)
{
    if (mouse.x > 20 && mouse.x < 20 && mouse.y > 20 && mouse.y < 120) {
        rpg->menu[18].rect.left = rpg->menu[18].rect.width;
        rpg->fight->buttons[5].rect.left = rpg->fight->buttons[5].rect.width;
    } else {
        rpg->menu[18].rect.left = 0;
        rpg->fight->buttons[5].rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->menu[18].sprite, rpg->menu[18].rect);
    sfSprite_setTextureRect(rpg->fight->buttons[5].sprite,
    rpg->fight->buttons[5].rect);
}

void global_event(rpg_t *rpg, game_obj_t *background)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win);

    while (sfRenderWindow_pollEvent(rpg->win, &rpg->evnt)) {
        analyse_event(rpg, background);
    }
    display_fps(rpg);
    if (rpg->status == 0)
        set_volume(rpg);
    rect_pause(mouse, rpg);
    global_event_statue_three(rpg, background);
    if (rpg->status == 8)
        script_death(rpg, background);
    if (rpg->status == 7)
        tuto(rpg, background);
    if (rpg->status == 0)
        check_mouse_pos_menu(rpg);
    if (rpg->status == 10 || rpg->status == 11)
        player_deplacement(rpg);
}
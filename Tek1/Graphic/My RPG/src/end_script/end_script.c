/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** end_script
*/

#include "rpg.h"

void set_end_script(rpg_t *rpg, end_script_t *end)
{
    end->tmp = 0;
    end->act = 1;
    rpg->player.pos = (sfVector2f) {743, 940};
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    sfSprite_setPosition(end->gf, (sfVector2f) {917, 720});
    end->cinematic_size = (sfVector2f) {0, 0};
    end->msg_rect = (sfIntRect) {0, 0, 1920, 1080};
    end->cinematic_radius = 1;
    end->cinematic_size = (sfVector2f) {0, 0};
    sfCircleShape_setScale(end->cinematic, end->cinematic_size);
}

void end_script_two(rpg_t *rpg, end_script_t *end)
{
    if (end->act == 1)
        first_act(rpg, end);
    if (end->act == 2)
        second_act(rpg, end);
    if (end->act == 3)
        third_act(rpg, end);
    if (end->act == 4)
        fourth_act(rpg, end);
    if (end->act == 5)
        fivth_act(rpg, end);

}

void end_script(rpg_t *rpg, end_script_t *end)
{
    static int i = 0;

    if (i == 0) {
        set_end_script(rpg, end);
        i++;
    } else if (i == 1) {
        end_script_two(rpg, end);
        if (end->act == 6)
            if (final_act(rpg, end))
                i = 0;
    }
    return;
}

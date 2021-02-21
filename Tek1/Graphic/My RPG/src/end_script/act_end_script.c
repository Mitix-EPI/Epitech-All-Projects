/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** act_end_script
*/

#include "rpg.h"

void first_act(rpg_t *rpg, end_script_t *end)
{
    end->clock.time = sfClock_getElapsedTime(end->clock.clock);
    end->clock.seconds = end->clock.time.microseconds / 1000000.0;

    if (end->clock.seconds > 0.07) {
        move_up(&rpg->player);
        rpg->player.pos.y -= 2;
        sfClock_restart(end->clock.clock);
    }
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    if (rpg->player.pos.y < 810) {
        end->act = 2;
        sfClock_restart(end->clock.clock);
    }
}

void second_act(rpg_t *rpg, end_script_t *end)
{
    end->clock.time = sfClock_getElapsedTime(end->clock.clock);
    end->clock.seconds = end->clock.time.microseconds / 1000000.0;

    if (end->clock.seconds > 0.07) {
        move_right(&rpg->player);
        rpg->player.pos.x += 3;
        sfClock_restart(end->clock.clock);
    }
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    if (rpg->player.pos.x > 938) {
        end->act = 3;
        sfClock_restart(end->clock.clock);
    }
}

void third_act(rpg_t *rpg, end_script_t *end)
{
    end->clock.time = sfClock_getElapsedTime(end->clock.clock);
    end->clock.seconds = end->clock.time.microseconds / 1000000.0;

    if (end->clock.seconds > 0.07) {
        move_up(&rpg->player);
        rpg->player.pos.y -= 2;
        sfClock_restart(end->clock.clock);
    }
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    if (rpg->player.pos.y < 800) {
        end->act = 4;
        rpg->player.direct = 0;
    }
}
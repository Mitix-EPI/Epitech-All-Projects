/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** acts
*/

#include "rpg.h"

void fourth_act(rpg_t *rpg, __attribute__((unused)) end_script_t *end)
{
    rpg->end.tmp = 1;
}

void fivth_act(__attribute__((unused)) rpg_t *rpg, end_script_t *end)
{
    end->clock.time = sfClock_getElapsedTime(end->clock.clock);
    end->clock.seconds = end->clock.time.microseconds / 1000000.0;

    if (end->clock.seconds > 0.07) {
        end->cinematic_size.x += 22;
        end->cinematic_size.y += 22;
        sfClock_restart(end->clock.clock);
    }
    sfCircleShape_setScale(end->cinematic, end->cinematic_size);
    if (end->cinematic_size.x  > 1200) {
        end->act = 6;
        end->tmp = 2;
        sfClock_restart(end->clock.clock);
    }

}

int final_act(rpg_t *rpg, end_script_t *end)
{
    end->clock.time = sfClock_getElapsedTime(end->clock.clock);
    end->clock.seconds = end->clock.time.microseconds / 1000000.0;

    if (end->clock.seconds > 6) {
        end->tmp = 0;
        rpg->status = 0;
        rpg->menu_status = 0;
        rpg->player.pos.x = (1920 / 2) - (64 / 2);
        rpg->player.pos.y = (1080 / 2) - (64 / 2);
        sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
        stop_all_music(rpg);
        sfSound_play(rpg->snd_menu);
        return (1);
    }
    return (0);
}

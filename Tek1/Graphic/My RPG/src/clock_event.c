/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clock_event
*/

#include "my.h"
#include "rpg.h"

void change_background_menu_rect(rpg_t *rpg)
{
    if (rpg->menu[17].rect.top < 642 * 7 && rpg->menu[17].rect.left < 1026 * 5)
        if (rpg->menu[17].rect.left < 1026 * 4)
            rpg->menu[17].rect.left += 1026;
        else {
            rpg->menu[17].rect.left = 0;
            rpg->menu[17].rect.top += 642;
        }
    else {
        rpg->menu[17].rect.left = 1026 * 5;
        if (rpg->menu[17].rect.top >= 642 * 7)
            rpg->menu[17].rect.top = 0;
        else if (rpg->menu[17].rect.top < 642 * 2)
            rpg->menu[17].rect.top += 642;
        else {
            rpg->menu[17].rect.top = 0;
            rpg->menu[17].rect.left = 0;
        }
    }
    sfSprite_setTextureRect(rpg->menu[17].sprite, rpg->menu[17].rect);
}

void animation_player(player_t *player)
{
    int direct = player->direct;
    if (direct == 1 || direct == 3 || direct == 5 || direct == 7) {
        if (player->rect.left < 64 * 7 + 32) {
            player->rect.left += 64;
        } else
            player->rect.left = 64;
    }
    sfSprite_setTextureRect(player->sprite, player->rect);
}

void update_particles(rpg_t *rpg)
{
    for (size_t index = 0; index < PARICULE_MAX; index++)
        update_particle(&rpg->screen->particle_environment, \
        &rpg->screen->particle[index]);
}

void clock_event(rpg_t *rpg, clock_s *clock)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->second = clock->time.microseconds / 1000000.0;
    rpg->player.clock.time = sfClock_getElapsedTime(rpg->player.clock.clock);
    rpg->player.clock.second = rpg->player.clock.time.microseconds / 1000000.0;

    if (rpg->player.clock.second > 0.06 && rpg->status != 9) {
        if (rpg->player.direct != 0) {
            animation_player(&rpg->player);
        }
        sfClock_restart(rpg->player.clock.clock);
    }
    if (clock->second > 3 && rpg->status == 9) {
        rpg->status = 8;
        sfClock_restart(rpg->player.clock.clock);
    }
    if (clock->second > 0.09 && rpg->status != 9) {
        change_background_menu_rect(rpg);
        sfClock_restart(clock->clock);
        sfClock_restart(clock->clock);
    }
    update_particles(rpg);
}

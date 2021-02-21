/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** launch_spell
*/

#include "rpg.h"

void updates_spells(fight_t *fight, rpg_t *rpg)
{
    if (fight->spell[0].activated > 0 && fight->spell[0].tmp == 1)
        fight->spell[0].tmp = update_fireballs(&fight->spell[0],
        fight->player.pos, fight, rpg);
    if (fight->spell[1].activated > 0 && fight->spell[1].tmp == 1)
        fight->spell[1].tmp = update_shield(&fight->spell[1],
        fight->player.pos, fight, rpg);
    if (fight->spell[2].activated > 0 && fight->spell[2].tmp == 1)
        fight->spell[2].tmp = update_black_holes(&fight->spell[2],
        fight->player.pos, fight, rpg);
    if (fight->spell[3].activated > 0 && fight->spell[3].tmp == 1)
        fight->spell[3].tmp = update_health(&fight->spell[3],
        fight->player.pos, fight, rpg);
    if (fight->spell[4].activated > 0 && fight->spell[4].tmp == 1)
        fight->spell[4].tmp = update_speed(&fight->spell[4],
        fight->player.pos, fight, rpg);
}

void launch_spell(fight_t *fight, rpg_t *rpg)
{
    if (fight->player.weapon == SPELL_ONE)
        launch_fireball(fight, rpg);
    if (fight->player.weapon == SPELL_TWO)
        launch_shield(fight, rpg);
    if (fight->player.weapon == SPELL_THREE &&
    rpg->quest.scd_quest.nb_kills >= 30)
        launch_black_hole(fight, rpg);
    if (fight->player.weapon == SPELL_FOUR && rpg->quest.scd_quest.nb_win >= 3)
        launch_heals(fight, rpg);
    if (fight->player.weapon == SPELL_FIVE &&
    rpg->quest.scd_quest.nb_kills >= 15)
        launch_speed(fight, rpg);
    updates_spells(fight, rpg);
}
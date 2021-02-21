/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** shield_checks
*/

#include "rpg.h"

void check_touch_ennemie_shield_two(fight_t *fight, rpg_t *rpg, spell_t *spell,
int i)
{
    if (fight->enns[i].in_live == 1)
        if (spell->pos.x + 30 > fight->enns[i].pos.x - 25 &&
        spell->pos.x - 30 < fight->enns[i].pos.x + 25 &&
        spell->pos.y + 30  > fight->enns[i].pos.y - 35 &&
        spell->pos.y - 30< fight->enns[i].pos.y + 35) {
            fight->enns[i].life -= spell->damage;
            (fight->enns[i].life <= 0) ? (rpg->quest.scd_quest.nb_kills
            += 1) : (rpg->quest.scd_quest.nb_kills =
            rpg->quest.scd_quest.nb_kills);
        }
    fight->enns[i].buttons[1].rect.width = fight->enns[i].life + 2;
    sfSprite_setTextureRect(fight->enns[i].buttons[1].sprite,
    fight->enns[i].buttons[1].rect);
}

void check_touch_ennemie_shield(fight_t *fight, rpg_t *rpg, spell_t *spell)
{
    for (int i = 0; i < fight->nb_enn; i++) {
        check_touch_ennemie_shield_two(fight, rpg, spell, i);
    }
    shield_damage_enn(fight, rpg, spell);
}

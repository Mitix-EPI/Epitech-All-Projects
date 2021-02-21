/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** checks_and_display_black_hole
*/

#include "rpg.h"

void check_touch_ennemie_black_hole_two(fight_t *fight, rpg_t *rpg,
spell_t *spell, int i)
{
    if (fight->enns[i].in_live == 1)
        if (spell->pos.x > fight->enns[i].pos.x - 25 &&
        spell->pos.x < fight->enns[i].pos.x + 25 &&
        spell->pos.y > fight->enns[i].pos.y - 35 &&
        spell->pos.y < fight->enns[i].pos.y + 35) {
            fight->enns[i].life -= spell->damage;
            (fight->enns[i].life <= 0) ? (rpg->quest.scd_quest.nb_kills += 1) :
            (rpg->quest.scd_quest.nb_kills = rpg->quest.scd_quest.nb_kills);
        }
    fight->enns[i].buttons[1].rect.width = fight->enns[i].life + 2;
    sfSprite_setTextureRect(fight->enns[i].buttons[1].sprite,
    fight->enns[i].buttons[1].rect);
}

void check_touch_ennemie_black_hole(fight_t *fight, rpg_t *rpg, spell_t *spell)
{
    for (int i = 0; i < fight->nb_enn; i++) {
        check_touch_ennemie_black_hole_two(fight, rpg, spell, i);
    }
    if (rpg->status == 11)
        black_hole_damage_player(fight, rpg, spell);
}

void display_cooldown_black_holes(float second, spell_t *spell)
{
    if (second < spell->sec)
        set_cooldown_(spell->sec - second, spell);
    else
        spell->text.str = NULL;
}

int displays_cooldown_black(spell_t *spell, int *tmp)
{
    if (spell->activated == 2)
        display_cooldown_black_holes(spell->clock_cd.seconds, spell);
    if (spell->clock_cd.seconds >= spell->sec && spell->activated == 2) {
        spell->activated = 0;
        *tmp = 0;
        sfClock_restart(spell->clock_cd.clock);
        return (0);
    }
    return (1);
}
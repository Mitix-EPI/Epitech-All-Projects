/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** use_spell
*/

#include "rpg.h"

spell_t use_spell_two(spell_t spell, __attribute__((unused)) fight_t *fight,
__attribute__((unused)) int value, sfVector2f *delta)
{
    if (fabs(spell.pos.x - spell.final_pos.x) < fabs(delta->x * 5)
    || fabs(spell.pos.y - spell.final_pos.y) < fabs(delta->y * 5)) {
        spell.pos = spell.final_pos;
        spell.activated = 0;
    }
    else {
        spell.pos.x -= delta->x;
        spell.pos.y -= delta->y;
    }
    sfSprite_setPosition(spell.sprite, spell.pos);
    return (spell);
}

spell_t use_spell(spell_t spell, fight_t *fight, int value)
{
    static sfVector2f delta = {0, 0};

    if (value == 0) {
        spell.activated = 1;
        spell.pos = fight->boss->pos;
        spell.final_pos = fight->player.pos;
        delta.x = (spell.pos.x - spell.final_pos.x) / 100;
        delta.y = (spell.pos.y - spell.final_pos.y) / 100;
        sfSprite_setPosition(spell.sprite, spell.pos);
        return (spell);
    }
    return (use_spell_two(spell, fight, value, &delta));
}

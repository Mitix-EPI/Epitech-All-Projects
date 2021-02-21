/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** check_animation_fireball
*/

#include "rpg.h"

void check_touch_ennemie_fireball_two(fight_t *fight, rpg_t *rpg,
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

void check_touch_ennemie_fireball(fight_t *fight, rpg_t *rpg, spell_t *spell)
{
    for (int i = 0; i < fight->nb_enn; i++) {
        check_touch_ennemie_fireball_two(fight, rpg, spell, i);
    }
    if (rpg->status == 11)
        fireball_damage_player(fight, rpg, spell);
}

void animation_fireball(spell_t *spell)
{
    sfTime time = sfClock_getElapsedTime(spell->clock);
    float second = time.microseconds / 1000000.0;
    if (second > 0.09) {
        if (spell->rect.left < 48 * 3) {
            spell->rect.left += 48;
        } else {
            spell->rect.left = 0;
        }
        sfClock_restart(spell->clock);
    }
    sfSprite_setTextureRect(spell->sprite, spell->rect);
}

void change_position_fireball(spell_t *spell, __attribute__((unused))
sfVector2f pos)
{
    animation_fireball(spell);
    if (spell->direction == 0 || spell->direction == 5)
        spell->pos.y += 5;
    if (spell->direction == 1)
        spell->pos.y -= 5;
    if (spell->direction == 3)
        spell->pos.x += 5;
    if (spell->direction == 7)
        spell->pos.x -= 5;
    sfSprite_setPosition(spell->sprite, spell->pos);
}

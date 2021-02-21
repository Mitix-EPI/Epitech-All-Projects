/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** pos_and_animation_black_hole
*/

#include "rpg.h"

void animation_black_hole_two(spell_t *spell)
{
    if (spell->rect.left < 1750 && spell->rect.top == 0)
        spell->rect.left += 250;
    else
        if (spell->rect.top == 0) {
            spell->rect.left = 0;
            spell->rect.top = 250;
        } else if (spell->rect.left < 1500)
            spell->rect.left += 250;
        else {
            spell->rect.left = 0;
            spell->rect.top = 0;
        }
    sfClock_restart(spell->clock);
}

void animation_black_hole(spell_t *spell)
{
    sfTime time = sfClock_getElapsedTime(spell->clock);
    float second = time.microseconds / 1000000.0;
    if (second > 0.05) {
        animation_black_hole_two(spell);
    }
    sfSprite_setTextureRect(spell->sprite, spell->rect);
}

void pos_rotat_two(sfVector2f *pos, sfVector2f player_pos,
int rad, sfSprite *sprt)
{
    if (rad == 0) {
        pos->y = player_pos.y;
        pos->x = player_pos.x + 300;
        sfSprite_setRotation(sprt, rad);
    }
    if (rad == 180) {
        pos->y = player_pos.y;
        pos->x = player_pos.x - 300;
        sfSprite_setRotation(sprt, rad);
    }
}

void pos_rotat_(sfVector2f *pos, sfVector2f player_pos, int rad, sfSprite *sprt)
{
    if (rad == 90) {
        pos->y = player_pos.y + 300;
        pos->x = player_pos.x;
        sfSprite_setRotation(sprt, rad);
    }
    if (rad == 270) {
        pos->y = player_pos.y - 300;
        pos->x = player_pos.x;
        sfSprite_setRotation(sprt, rad);
    }
    pos_rotat_two(pos, player_pos, rad, sprt);
}
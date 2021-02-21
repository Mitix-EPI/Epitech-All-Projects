/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** attacks
*/

#include "rpg.h"

void attack_player(spell_t *spell, fight_t *fight)
{
    fight->clock->time = sfClock_getElapsedTime(fight->clock->clock);
    fight->clock->seconds = fight->clock->time.microseconds / 1000000.0;
    if (spell->pos.x > fight->player.pos.x - 25 &&
    spell->pos.x < fight->player.pos.x + 25 &&
    spell->pos.y > fight->player.pos.y - 35 &&
    spell->pos.y < fight->player.pos.y + 35 &&
    fight->spell[1].activated != 1 &&
    fight->clock->seconds > 1) {
        fight->player.life -= 40;
        fight->buttons[3].rect.width = fight->player.life * 2 + 4;
        sfSprite_setTextureRect(fight->buttons[3].sprite,
        fight->buttons[3].rect);
        sfClock_restart(fight->clock->clock);
    }
}

void attack_1(fight_t *fight, float *max)
{
    int value = (*max == 1) ? 1 : 0;
    static int anim = 0;
    sfTime time = sfClock_getElapsedTime(fight->boss_spell[0].clock);
    float seconds = time.microseconds / 1000000;

    if (seconds > 0.01) {
        anim += 1;
        sfClock_restart(fight->boss_spell[0].clock);
    }
    if (anim == 5)
        anim = 0;
    *max = 1;
    fight->boss_spell[0].rect.left = (anim % 5) * 192;
    fight->boss_spell[0] = use_spell(fight->boss_spell[0], fight, value);
    sfSprite_setTextureRect(fight->boss_spell[0].sprite,
    fight->boss_spell[0].rect);
    attack_player(&fight->boss_spell[0], fight);
}

void attack_2(fight_t *fight __attribute__((unused)), float *max)
{
    int value = (*max == 2) ? 1 : 0;
    static int anim = 0;
    sfTime time = sfClock_getElapsedTime(fight->boss_spell[1].clock);
    float seconds = time.microseconds / 1000000;

    if (seconds > 0.01) {
        anim += 1;
        sfClock_restart(fight->boss_spell[1].clock);
    }
    if (anim == 5)
        anim = 0;
    fight->boss_spell[1].rect.left = (anim % 5) * 192;
    *max = 2;
    fight->boss_spell[1] = use_spell(fight->boss_spell[1], fight, value);
    sfSprite_setTextureRect(fight->boss_spell[1].sprite,
    fight->boss_spell[1].rect);
    attack_player(&fight->boss_spell[1], fight);
}

void attack_3(fight_t *fight __attribute__((unused)), float *max)
{
    int value = (*max == 3) ? 1 : 0;
    static int anim = 0;
    sfTime time = sfClock_getElapsedTime(fight->boss_spell[2].clock);
    float seconds = time.microseconds / 1000000;

    if (seconds > 0.01) {
        anim += 1;
        sfClock_restart(fight->boss_spell[2].clock);
    }
    if (anim == 5)
        anim = 0;
    fight->boss_spell[2].rect.left = (anim % 5) * 192;
    *max = 3;
    fight->boss_spell[2] = use_spell(fight->boss_spell[2], fight, value);
    sfSprite_setTextureRect(fight->boss_spell[2].sprite,
    fight->boss_spell[2].rect);
    attack_player(&fight->boss_spell[2], fight);
}
/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** speed
*/

#include "rpg.h"

void launch_first_speed(fight_t *fight, sfVector2f player_pos)
{
    sfVector2f final_pos = {0, 0};

    fight->spell[4].pos.x = player_pos.x + 50;
    fight->spell[4].pos.x = player_pos.y + 50;
    sfSprite_setPosition(fight->spell[4].sprite, fight->spell[4].pos);
    fight->spell[4].final_pos = final_pos;
    fight->spell[4].activated = 1;
    sfClock_restart(fight->spell[4].clock_cd.clock);
}

void change_position_speed(spell_t *spell, sfVector2f pos)
{
    static int test = 0;
    sfTime time;

    if (spell->protection != 0 && spell->activated == 1 && test == 0) {
        test = 1;
        sfClock_restart(spell->clock);
    }
    if (test == 1) {
        time = sfClock_getElapsedTime(spell->clock);
        if (time.microseconds / 1000000 > 1) {
            spell->activated = 2;
            test = 0;
        }
    }
    spell->pos = (sfVector2f) {pos.x - 5, pos.y + 10};
    sfSprite_setPosition(spell->sprite, spell->pos);
}

int update_speed(spell_t *spell, sfVector2f pos,
__attribute__((unused)) fight_t *fight, __attribute__((unused))rpg_t *rpg)
{
    animation_speed(spell);
    change_position_speed(spell, pos);
    return (cooldown_speed(spell));
}

void launch_speed(fight_t *fight, rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && fight->spell[4].activated == 0
    && fight->spell[4].tmp == 0) {
        launch_first_speed(fight, fight->player.pos);
        fight->spell[4].tmp += 1;
        sfSound_play(rpg->snd_speed);
    }
}

/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** update_fights
*/

#include "rpg.h"

float get_distance(sfVector2f p1, sfVector2f p2)
{
    const float dx = (p2.x) - p1.x;
    const float dy = (p2.y) - p1.y;

    return (sqrtf(dx * dx + dy * dy));
}

void animate_enemy(ennemies_t *ennemies)
{
    ennemies->clock.time = sfClock_getElapsedTime(ennemies->clock.clock);
    ennemies->clock.second = ennemies->clock.time.microseconds / 1000000.0;
    if (ennemies->clock.second > 0.2) {
        if (ennemies->tmp == 0 || ennemies->tmp == 1) {
            ennemies->rect.left += 50;
            ennemies->tmp += 1;
        } else {
            ennemies->rect.left -= 100;
            ennemies->tmp = 0;
        }
        sfClock_restart(ennemies->clock.clock);
    }
}

void knock_back(player_fight_t *player,
clock_s *clock, sfVector2f truc_1_2, int tmp)
{
    int direct = player->direct;

    if (pos_zombie(player, truc_1_2.x, truc_1_2.y, tmp) == 0) {
        player->rect.left = 0;
        sfSprite_setTextureRect(player->player, player->rect);
        return;
    }
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->second = clock->time.microseconds / 1000000.0;
    if (clock->second > 0.06) {
        change_rect_direction_player(player, direct);
        sfSprite_setTextureRect(player->player, player->rect);
        sfClock_restart(clock->clock);
    }
    sfSprite_setPosition(player->player, player->pos);
}

void update_weapons(fight_t *fight)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum1))
        fight->player.weapon = SPELL_ONE;
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
        fight->player.weapon = SPELL_TWO;
    if (sfKeyboard_isKeyPressed(sfKeyNum3))
        fight->player.weapon = SPELL_THREE;
    if (sfKeyboard_isKeyPressed(sfKeyNum4))
        fight->player.weapon = SPELL_FOUR;
    if (sfKeyboard_isKeyPressed(sfKeyNum5))
        fight->player.weapon = SPELL_FIVE;
    if (sfKeyboard_isKeyPressed(sfKeyNum6))
        fight->player.weapon = SPELL_SIX;
}

void update_fights(fight_t *fight, rpg_t *rpg)
{
    if (rpg->status != 10 && rpg->status != 11) {
        for (int i = 0; i < fight->nb_enn; i++) {
            if (fight->enns[i].in_live == 1 && fight->enns[i].life <= 0)
                fight->enns[i].in_live = 0;
        }
        ennemies_deplacements(fight, rpg);
    }
    if (rpg->status == 11 && fight->boss->life > 0)
        move_boss(fight);
    update_weapons(fight);
    player_deplacements(&fight->player, fight);
    launch_spell(fight, rpg);
}
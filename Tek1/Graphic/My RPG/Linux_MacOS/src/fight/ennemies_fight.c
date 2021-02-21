/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ennemies_fight
*/

#include "rpg.h"

sfVector2f calc_movement_enn(fight_t *fight, int i)
{
    float distance = get_distance(fight->enns[i].pos, fight->player.pos);
    float x = (fight->enns[i].pos.x  - fight->player.pos.x);
    float y = (fight->enns[i].pos.y  - fight->player.pos.y);
    float truc1 = (x / distance) * fight->enns[i].velocity;
    float truc2 = (y / distance) * fight->enns[i].velocity;

    return ((sfVector2f) {truc1, truc2});
}

sfVector2f enn_live_green(fight_t *fight, int i, int *tmp, sfVector2f truc_1_2)
{
    fight->enns[i].buttons[0].pos.x = fight->enns[i].pos.x - 50;
    fight->enns[i].buttons[0].pos.y = fight->enns[i].pos.y - 51;
    sfSprite_setPosition(fight->enns[i].buttons[0].sprite,
    fight->enns[i].buttons[1].pos);
    if (fight->enns[i].pos.x > fight->player.pos.x - 25 &&
    fight->enns[i].pos.x < fight->player.pos.x + 25 &&
    fight->enns[i].pos.y > fight->player.pos.y - 35 &&
    fight->enns[i].pos.y < fight->player.pos.y + 35)
        *tmp = 1;
    return (truc_1_2);
}

sfVector2f enn_in_live_calcs(fight_t *fight, int i, int *tmp)
{
    sfVector2f truc_1_2 = calc_movement_enn(fight, i);

    fight->enns[i].pos.x -= truc_1_2.x;
    fight->enns[i].pos.y -= truc_1_2.y;
    where_to_move(&fight->enns[i], truc_1_2.x, truc_1_2.y);
    animate_enemy(&fight->enns[i]);
    sfSprite_setTextureRect(fight->enns[i].enn, fight->enns[i].rect);
    sfSprite_setPosition(fight->enns[i].enn, fight->enns[i].pos);
    fight->enns[i].buttons[1].pos.x = fight->enns[i].pos.x - 50;
    fight->enns[i].buttons[1].pos.y = fight->enns[i].pos.y - 51;
    sfSprite_setPosition(fight->enns[i].buttons[1].sprite,
    fight->enns[i].buttons[1].pos);
    return (enn_live_green(fight, i, tmp, truc_1_2));
}

void enn_touchs_player(fight_t *fight, int tmp, sfVector2f truc_1_2)
{
    if (tmp < 2 && (fight->spell[fight->player.weapon - 1].protection == 0
    || fight->spell[fight->player.weapon - 1].activated != 1)) {
        knock_back(&fight->player, &fight->player.clock, truc_1_2, tmp);
        fight->player.life -= 1;
        fight->buttons[3].rect.width = fight->player.life * 2 + 4;
        sfSprite_setTextureRect(fight->buttons[3].sprite,
        fight->buttons[3].rect);
    }
}

void ennemies_deplacements(fight_t *fight, __attribute__((unused)) rpg_t *rpg)
{
    static int tmp = 0;

    for (int i = 0; i < fight->nb_enn; i++) {
        fight->enns[i].enn_clock.time =
        sfClock_getElapsedTime(fight->enns[i].enn_clock.clock);
        fight->enns[i].enn_clock.second =
        fight->enns[i].enn_clock.time.microseconds / 1000000.0;
        if (fight->enns[i].enn_clock.second > 0.01) {
            moving_clocked_enn(fight, i, &tmp);
        }
    }
    tmp = 0;
}

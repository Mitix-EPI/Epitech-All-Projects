/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** pos_change_move_fight
*/

#include "rpg.h"

int pos_zombie_condition(player_fight_t *player, float truc1, float truc2)
{
    if (truc1 >= truc2 && truc1 >= 0 && player->pos.x > 10) {
        player->pos.x -= 5;
        return (move_left_touch(player));
    }
    if (truc1 >= truc2 && truc1 < 0 && player->pos.x < 1910) {
        player->pos.x += 5;
        return (move_right_touch(player));
    }
    if (truc1 < truc2 && truc1 >= 0 && player->pos.y > 10) {
        player->pos.y -= 5;
        return (move_up_touch(player));
    }
    if (truc1 < truc2 && truc1 < 0 && player->pos.y < 1040) {
        player->pos.y += 5;
        return (move_down_touch(player));
    }
    return (-84);
}

int pos_zombie(player_fight_t *player, float truc1, float truc2, int tmp2)
{
    static int tmp = 5;
    int res = 0;

    if (tmp < 30) {
        res = pos_zombie_condition(player, truc1, truc2);
        if (res != -84)
            return (res);
        tmp += 5;
    }
    if (tmp2 == 1) {
        tmp = 0;
    }
    return (0);
}

void change_rect_direction_player(player_fight_t *player, int direct)
{
    if (direct == 1 || direct == 3 || direct == 5 || direct == 7) {
        if (player->rect.left < 64 * 7 + 32) {
            player->rect.left += 64;
        } else
            player->rect.left = 64;
    }
}

void moving_clocked_enn(fight_t *fight, int i, int *tmp)
{
    sfVector2f truc_1_2 = {0};

    if (fight->enns[i].in_live == 1) {
        truc_1_2 = enn_in_live_calcs(fight, i, tmp);
    }
    if (*tmp >= 1) {
        enn_touchs_player(fight, *tmp, truc_1_2);
        *tmp +=  1;
    }
}

void where_to_move(ennemies_t *ennemies, float truc1, float truc2)
{
    if (fabs(truc1) >= fabs(truc2)) {
        if (truc1 >= 0)
            ennemies->rect.top = 76;
        else
            ennemies->rect.top = 146;
    } else {
        if (truc2 >= 0)
            ennemies->rect.top = 216;
        else
            ennemies->rect.top = 6;
    }
}

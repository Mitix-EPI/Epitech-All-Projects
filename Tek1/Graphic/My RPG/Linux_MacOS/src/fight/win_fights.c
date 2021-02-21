/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** win_fights
*/

#include "rpg.h"

void win_boss_fight(fight_t *fight, rpg_t *rpg)
{
    static int tmp = 0;

    if (rpg->status == 11 && fight->player.pos.x < 1880 &&
    fight->boss->life <= 0 && tmp == 0) {
        stop_all_music(rpg);
        sfSound_play(rpg->snd_win);
        set_particules_for_feux_d_artifices(&rpg->screen->particle_environment);
        tmp += 1;
    }
    if (tmp > 0)
        feux_d_artifices(rpg);
    if (rpg->status == 11 && fight->player.pos.x >= 1880 &&
    fight->boss->life <= 0) {
        stop_all_music(rpg);
        sfSound_play(rpg->snd_end);
        set_particules_default(&rpg->screen->particle_environment);
        rpg->status = 5;
        tmp = 0;
    }
}

void win_normal_fight(fight_t *fight, rpg_t *rpg)
{
    int count = 0;

    for (int i = 0; i < fight->nb_enn; i++)
        if (fight->enns[i].in_live == 0)
            count += 1;
    if (count == fight->nb_enn) {
        reset_ennemies(fight);
        sfSound_play(rpg->snd_win_fight);
        rpg->quest.scd_quest.nb_win += 1;
        upgrade_player(fight, rpg->quest.scd_quest.nb_win);
        rpg->status = 10;
    }
    if (rpg->status == 10 && fight->player.pos.x >= 1880) {
        fight->player.pos = (sfVector2f){1920 / 2, 1080 / 2};
        sfSprite_setPosition(fight->player.player, fight->player.pos);
        stop_all_music(rpg);
        sfSound_play(rpg->snd_main_music);
        rpg->status = 3;
    }
}

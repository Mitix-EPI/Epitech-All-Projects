/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_rpg
*/

#include "my.h"
#include "rpg.h"

void init_end_script(end_script_t *end)
{
    end->clock.clock = sfClock_create();

    end->tmp = 0;
    end->act = 0;
    create_backgrounds_end_script(end);
    create_msg_and_txt_end_script(end);
    create_gf_and_circle(end);
}

int main_rpg(void)
{
    rpg_t *rpg = malloc(sizeof(struct rpg_s));
    clock_s clock;
    game_obj_t background;

    create_window(rpg);
    init_player(&rpg->player);
    my_set_ints(rpg, &clock);
    my_set_sprites(&background, rpg);
    for (int i = 0; i < PARICULE_MAX; i += 1)
        rpg->screen->particle[i].living = false;
    rpg->fight->boss = init_boss();
    rpg->fight->boss_spell = init_boss_spell();
    while (sfRenderWindow_isOpen(rpg->win)) {
        global_event(rpg, &background);
        clock_event(rpg, &clock);
        draw_statue(rpg, rpg->win, &background);
    }
    destroy(&background, rpg);
    return (0);
}
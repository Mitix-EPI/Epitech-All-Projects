/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clics_handlings
*/

#include "rpg.h"
#include "my.h"

void clics_handlings(sfMouseButtonEvent event __attribute__((unused)),
rpg_t *rpg, game_obj_t *obj)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win);

    if (rpg->status == 0) {
        click_menu(rpg, mouse, obj);
        add_particle(&rpg->screen->particle_environment, rpg->screen->particle,
        35, (sfVector2f){mouse.x, mouse.y});
    }
    if (rpg->status == 3 || rpg->status == 4 || rpg->status == 7 ||
    rpg->status == 10 || rpg->status == 11 || rpg->status == 5) {
        if (mouse.x > 20 && mouse.x < 220 && mouse.y > 20 && mouse.y < 220) {
            save_to_file(rpg, obj);
            stop_all_music(rpg);
            sfSound_play(rpg->snd_menu);
            rpg->tmp = rpg->status;
            rpg->status = 0;
            rpg->menu_status = 6;
        }
        add_particle(&rpg->screen->particle_environment, rpg->screen->particle,
        35, (sfVector2f){mouse.x, mouse.y});
    }
}
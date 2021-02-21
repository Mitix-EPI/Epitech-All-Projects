/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** scrpt_death
*/

#include "rpg.h"

void draw_death(sfRenderWindow *win, rpg_t *rpg, game_obj_t *obj)
{
    sfRenderWindow_clear(win, sfBlack);

    sfRenderWindow_drawSprite(win, obj->sprite, NULL);
    sfRenderWindow_drawSprite(win, rpg->player.sprite, NULL);
    sfRenderWindow_drawSprite(win, rpg->perspec.sprite, NULL);

    for (size_t index = 0; index < PARICULE_MAX; index++)
        display_particle(win, &rpg->screen->particle[index],
        rpg->screen->particle_environment.circle_shape);

    sfRenderWindow_display(win);
}

int script1_death(rpg_t *rpg, game_obj_t *background)
{
    static int i = 0;

    if (i < 45) {
        background->rect.top += 1;
        rpg->perspec.rect = background->rect;
        sfSprite_setTextureRect(background->sprite, background->rect);
        sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
        move_down(&rpg->player);
        i++;
        return (1);
    } else {
        dont_move(&rpg->player);
        stop_all_music(rpg);
        sfSound_play(rpg->snd_main_music);
        rpg->status = 3;
        i = 0;
        return (0);
    }
}

void set_script_death(rpg_t *rpg, game_obj_t *background)
{
    background->rect.top = 1100;
    background->rect.left = 146;
    rpg->quest.x = background->rect.left;
    rpg->quest.y = background->rect.top;
    rpg->perspec.rect = background->rect;
    sfSprite_setTextureRect(background->sprite, background->rect);
    sfSprite_setTextureRect(rpg->perspec.sprite, rpg->perspec.rect);
}

void script_death(rpg_t *rpg, game_obj_t *background)
{
    static int i = 0;
    sfTime time = sfClock_getElapsedTime(rpg->tuto.clock);
    float second = time.microseconds / 1000000.0;

    if (second > 0.09) {
        if (i == 0) {
            set_script_death(rpg, background);
            i += 1;
        } else if (i == 1) {
            i = script1_death(rpg, background);
        }
        sfClock_restart(rpg->tuto.clock);
    }
    rpg->quest.tmp = 0;
}

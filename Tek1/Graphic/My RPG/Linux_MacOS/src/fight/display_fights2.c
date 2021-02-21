/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** display_fights2
*/

#include "rpg.h"

void display_rect(fight_t *fight, sfRenderWindow *win,
__attribute__((unused)) rpg_t *rpg)
{
    sfRectangleShape_setPosition(fight->inventory.show,
    (sfVector2f) {((fight->player.weapon - 1) * 110) + 603, 935});
    sfRenderWindow_drawRectangleShape(win, fight->inventory.show, NULL);
}

void display_enns_fight(fight_t *fight, sfRenderWindow *win,
__attribute__((unused)) rpg_t *rpg, int i)
{
    if (fight->enns[i].in_live) {
        if (fight->enns[i].life < 100) {
            sfRenderWindow_drawSprite(win,
            fight->enns[i].buttons[0].sprite, NULL);
            sfRenderWindow_drawSprite(win,
            fight->enns[i].buttons[1].sprite, NULL);
        }
        sfRenderWindow_drawSprite(win, fight->enns[i].enn, NULL);
    }
}

void display_spell(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    for (int i = 0; i < 3; i += 1)
        if (fight->boss_spell[i].activated == 1)
            sfRenderWindow_drawSprite(win,
            rpg->fight->boss_spell[i].sprite, NULL);
}

void display_enns(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    if (rpg->status == 10)
        sfRenderWindow_drawSprite(win, fight->buttons[9].sprite, NULL);
    if (rpg->status == 11 && rpg->fight->boss->life <= 0)
        sfRenderWindow_drawSprite(win, fight->buttons[9].sprite, NULL);
    if (rpg->status == 11 && rpg->fight->boss->life > 0) {
        sfRenderWindow_drawSprite(win, rpg->fight->boss->enn, NULL);
        sfRenderWindow_drawSprite(win, fight->buttons[12].sprite, NULL);
        sfRenderWindow_drawSprite(win, fight->buttons[13].sprite, NULL);
        display_spell(fight, win, rpg);
    }
    for (int i = 0; i < fight->nb_enn && rpg->status != 10
    && rpg->status != 11; i++)
        display_enns_fight(fight, win, rpg, i);
}

void display_spells(fight_t *fight, sfRenderWindow *win,
__attribute__((unused)) rpg_t *rpg)
{
    for (int i = 0; i < 5; i++)
        if (fight->spell[i].activated == 1)
            sfRenderWindow_drawSprite(win, fight->spell[i].sprite, NULL);
}

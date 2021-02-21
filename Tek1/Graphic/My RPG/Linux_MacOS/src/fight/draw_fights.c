/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** draw_fights
*/

#include "rpg.h"

void display_cooldown(fight_t *fight, sfRenderWindow *win)
{
    if (fight->spell[0].text.str)
        sfRenderWindow_drawText(win, fight->spell[0].text.text, NULL);
    if (fight->spell[1].text.str)
        sfRenderWindow_drawText(win, fight->spell[1].text.text, NULL);
    if (fight->spell[2].text.str)
        sfRenderWindow_drawText(win, fight->spell[2].text.text, NULL);
    if (fight->spell[3].text.str)
        sfRenderWindow_drawText(win, fight->spell[3].text.text, NULL);
    if (fight->spell[4].text.str)
        sfRenderWindow_drawText(win, fight->spell[4].text.text, NULL);
}

void draw_inventory_item(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    for (int i = 6; i < 8; i += 1)
        sfRenderWindow_drawSprite(win, fight->buttons[i].sprite, NULL);

    if (rpg->quest.scd_quest.nb_kills >= 30)
        sfRenderWindow_drawSprite(win, fight->buttons[8].sprite, NULL);
    if (rpg->quest.scd_quest.nb_kills >= 15)
        sfRenderWindow_drawSprite(win, fight->buttons[11].sprite, NULL);
    if (rpg->quest.scd_quest.nb_win >= 3)
        sfRenderWindow_drawSprite(win, fight->buttons[10].sprite, NULL);
    for (size_t index = 0; index < PARICULE_MAX; index++)
        display_particle(win, &rpg->screen->particle[index],
        rpg->screen->particle_environment.circle_shape);
    sfRenderWindow_display(win);
}

void draw_fights(fight_t *fight, sfRenderWindow *win, rpg_t *rpg)
{
    sfRenderWindow_clear(win, sfBlack);
    sfRenderWindow_drawSprite(win, fight->buttons[4].sprite, NULL);
    if (rpg->status == 10)
        sfRenderWindow_drawSprite(win, fight->buttons[9].sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->buttons[4].sprite, NULL);
    display_enns(fight, win, rpg);
    sfRenderWindow_drawSprite(win, fight->player.player, NULL);
    display_spells(fight, win, rpg);
    sfRenderWindow_drawSprite(win, fight->buttons[2].sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->buttons[3].sprite, NULL);
    sfRenderWindow_drawSprite(win, fight->inventory.sprite, NULL);
    display_rect(fight, win, rpg);
    sfRenderWindow_drawSprite(win, fight->buttons[5].sprite, NULL);
    display_cooldown(fight, win);
    draw_inventory_item(fight, win, rpg);
}

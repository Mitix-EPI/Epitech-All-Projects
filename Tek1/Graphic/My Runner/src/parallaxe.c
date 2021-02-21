/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** parallax
*/

#include "../include/my.h"

struct parallax_s crt_bg(const char *path, sfVector2f ps, int i, int j)
{
    parallax_t para;

    para.sprite = sfSprite_create();
    para.texture = sfTexture_createFromFile(path, NULL);
    para.clck = sfClock_create();
    para.pos.x = ps.x;
    para.pos.y = ps.y;
    para.type = i;
    para.copy = j;
    sfSprite_setTexture(para.sprite, para.texture, sfTrue);
    return (para);
}

void sets_parallax(game_t *game)
{
    sfVector2f pos = {0, 0};
    game->parallax[0] = crt_bg("./assets/bg/back-trees.png", pos, UN, NO);
    game->parallax[1] = crt_bg("./assets/bg/back-trees.png", pos, UN, ACT);
    game->parallax[2] = crt_bg("./assets/bg/lights.png", pos, DEUX, NO);
    game->parallax[3] = crt_bg("./assets/bg/lights.png", pos, DEUX, ACT);
    game->parallax[4] = crt_bg("./assets/bg/middle-trees.png", pos, TROIS, NO);
    game->parallax[5] = crt_bg("./assets/bg/middle-trees.png", pos, TROIS, ACT);
    game->parallax[6] = crt_bg("./assets/bg/front-trees.png", pos, QUATRE, NO);
    game->parallax[7] = crt_bg("./assets/bg/front-trees.png", pos, QUATRE, ACT);
    for (int i = 0; i < 8; i++) {
        if (game->parallax[i].copy == ACT)
            game->parallax[i].pos.x = 1629;
        sfSprite_setScale(game->parallax[i].sprite, (sfVector2f) {6, 5});
    }
}

void update_per_bg(parallax_t *para, sfRenderWindow *win)
{
    if (para->seconds > 0.001) {
        if (para->type == UN)
            para->pos.x -= 4;
        if (para->type == DEUX)
            para->pos.x -= 6;
        if (para->type == TROIS)
            para->pos.x -= 8;
        if (para->type == QUATRE)
            para->pos.x -= 12;
        if (para->pos.x < -1629)
            para->pos.x = 1629;
        sfSprite_setPosition(para->sprite, para->pos);
        sfClock_restart(para->clck);
    }
    para->time = sfClock_getElapsedTime(para->clck);
    para->seconds = para->time.microseconds / 1000000.0;
    sfRenderWindow_drawSprite(win, para->sprite, NULL);
}
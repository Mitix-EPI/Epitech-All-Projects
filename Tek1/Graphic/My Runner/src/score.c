/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** score
*/

#include "../include/my.h"

void update_score(game_t *game)
{
    char *txt = NULL;

    if (game->endless == 0) {
            txt = my_itc(100 - ((100 * (game->end.pos.x - 152)) /
            (game->end.x_origin)));
            sfText_setString(game->text, my_strcat(txt, "%"));
    }
    if (game->endless == 1) {
        txt = my_itc(game->real_pts);
        game->pts += 1;
        if (game->pts > 5) {
            game->real_pts += 1;
            game->pts = 0;
        }
        sfText_setString(game->text, txt);
    }
}

void set_score(game_t *game)
{
    sfFont *font = sfFont_createFromFile("./assets/Games.ttf");
    game->text = sfText_create();
    sfText_setString(game->text, "0%");
    sfText_setFont(game->text, font);
    sfText_setCharacterSize(game->text, 70);
    sfText_setPosition(game->text, (sfVector2f) {50, 50});
    sfText_setColor(game->text, sfRed);
    game->scoreboard = sfSprite_create();
    game->board_t = sfTexture_createFromFile("./assets/board.png", NULL);
    sfSprite_setTexture(game->scoreboard, game->board_t, sfTrue);
    sfVector2f size = {0.5f, 0.5f};
    sfSprite_setScale(game->scoreboard, size);
    sfVector2f pos = {336, 100};
    sfSprite_setPosition(game->scoreboard, pos);
}
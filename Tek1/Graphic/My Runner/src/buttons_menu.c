/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** buttons
*/

#include "../include/my.h"

struct buttons_s crt_buts(const char *path, sfVector2f ps, sfVector2f scale)
{
    buttons_t buts;

    buts.rct.height = 75;
    buts.rct.width = 250;
    buts.rct.top = 0;
    buts.rct.left = 0;
    buts.sprt = sfSprite_create();
    buts.texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(buts.sprt, buts.texture, sfTrue);
    sfSprite_setPosition(buts.sprt, ps);
    sfSprite_setScale(buts.sprt, scale);
    sfSprite_setTextureRect(buts.sprt, buts.rct);
    return (buts);
}

void sets_menu(game_t *game)
{
    sfVector2f scale = {1.f, 1.f};
    sfVector2f pos0 = {325.f, 362.5f};
    sfVector2f pos1 = {650.f, 362.5f};
    sfVector2f pos2 = {975.f, 362.5f};
    sfVector2f pos3 = {50.f, 50.f};
    game->buts[0] = crt_buts("./assets/buttons/play.png", pos0, scale);
    game->buts[1] = crt_buts("./assets/buttons/options.png", pos1, scale);
    game->buts[2] = crt_buts("assets/buttons/quit.png", pos2, scale);
    game->buts[3] = crt_buts("./assets/buttons/back.png", pos3, scale);
}

void song_effect_button(game_t *game, int x, int y)
{
    static int effect = 0;

    if (x >= 338 && x <= 568 && y >= 375 && y <= 426 && effect == 0) {
        sfSound_play(game->music[5].sound);
        effect = 1;
    }
    if (x >= 661 && x <= 890 && y >= 375 && y <= 426 && effect == 0) {
        sfSound_play(game->music[5].sound);
        effect = 1;
    }
    if (x >= 987 && x <= 1218 && y >= 375 && y <= 426 && effect == 0) {
        sfSound_play(game->music[5].sound);
        effect = 1;
    }
    if (x < 338 || (x > 568 && x < 661) || (x > 890 && x < 987)
    || x > 1218)
        if (effect == 1)
            effect = 0;
    if (effect == 1 && (y < 375 || y > 426))
            effect = 0;
}

void interactive_button(game_t *game, int x, int y)
{
    if (x >= 338 && x <= 568 && y >= 375 && y <= 426) {
        game->buts[0].rct.left = 250;
    } else {
        game->buts[0].rct.left = 0;
    }
    if (x >= 661 && x <= 890 && y >= 375 && y <= 426) {
        game->buts[1].rct.left = 250;
    } else {
        game->buts[1].rct.left = 0;
    }
    if (x >= 987 && x <= 1218 && y >= 375 && y <= 426) {
        game->buts[2].rct.left = 250;
    } else {
        game->buts[2].rct.left = 0;
    }
    for (int i = 0; i < 3; i++)
        sfSprite_setTextureRect(game->buts[i].sprt, game->buts[i].rct);
}

int choose_button(int x, int y)
{
    if (x >= 338 && x <= 568 && y >= 375 && y <= 426) {
        return (2);
    }
    if (x >= 661 && x <= 890 && y >= 375 && y <= 426) {
        return (3);
    }
    if (x >= 987 && x <= 1218 && y >= 375 && y <= 426) {
        return (1);
    }
    return (0);
}
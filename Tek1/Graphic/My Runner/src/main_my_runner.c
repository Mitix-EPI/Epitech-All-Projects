/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** main_my_runner
*/

#include "../include/my.h"

void create_window(game_t *game)
{
    sfImage *icon = sfImage_createFromFile("assets/icon.png");
    sfVideoMode mode = {1632, 800, 32};
    game->win.w = sfRenderWindow_create(mode, "My Runner", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->win.w, 60);
    game->ips = 60;
    sfRenderWindow_setVerticalSyncEnabled(game->win.w, sfTrue);
    sfRenderWindow_setIcon(game->win.w, 540, 540, sfImage_getPixelsPtr(icon));
}

int print_help(void)
{
    write(1, "MY RUNNER\n", 11);
    write(1, "USAGE:\n    ./my_runner map.txt -> use custom map\n", 50);
    write(1, "\nSPACE KEY | UP KEY -> jump\n", 29);
    write(1, "ESCAPE KEY -> exit the game\n", 29);
    return (0);
}

int calc(int x)
{
    return (1632 + (x * 150));
}

int count_charac(char **mapa, char letter)
{
    int i = 0;
    for (int v = 0; mapa[v] != NULL; v++)
        for (int w = 0; mapa[v][w] != 'E'; w++)
            if (mapa[v][w] == letter)
                i += 1;
    return (i);
}

int main_my_runner(char *map)
{
    game_t game;
    game.nav = 0;

    basics_sets(&game, map);
    while (1) {
        if (game.nav == 0) {
            if (real_menu(&game)) {
                break;
            }
        }
        if (game.nav == 1)
            if (run_game(&game) == 1) {
                break;
            }
        if (game.nav == 2)
            if (options(&game))
                break;
    }
    return (0);
}
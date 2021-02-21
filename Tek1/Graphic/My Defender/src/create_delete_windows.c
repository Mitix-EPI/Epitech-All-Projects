/*
** EPITECH PROJECT, 2019
** MUL_my_hunter_2019
** File description:
** create_delete_windows.c
*/

#include "../my_tower.h"

sfRenderWindow *windows(int l, int h)
{
    sfRenderWindow* window;
    sfVideoMode mode = {l, h, 32};

    sfImage *icon = sfImage_createFromFile("sprite/tower_defense_icon.png");
    window = sfRenderWindow_create(mode, "SFML window", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 240, 240, sfImage_getPixelsPtr(icon));
    return (window);
}

char *tab_int_str(sprite_t *sprite)
{
    char *save = NULL;

    for (int a = 0; sprite->all_score[a]; a++) {
        save = cat(save, sprite->all_score[a]);
        save = cat(save, "\n");
    }
    return (save);
}

void close_windows(sfRenderWindow *window, sprite_t *sprite)
{
    int fd = open("score.txt", O_WRONLY);
    char *save = tab_int_str(sprite);

    write(fd, save, my_strlen(save));
    close(fd);
    sfRenderWindow_close(window);
}
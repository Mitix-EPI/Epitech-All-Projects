/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** main
*/

#include "../include/my.h"

void set_music(window_t *w)
{
    w->ibiza = sfSound_create();
    w->buffer = sfSoundBuffer_createFromFile("assets/2019.ogg");
    sfSound_setBuffer(w->ibiza, w->buffer);
    sfSound_setVolume(w->ibiza, 35.0f);
    sfSound_setLoop(w->ibiza, sfTrue);
    sfSound_play(w->ibiza);
}

int print_description(void)
{
    write(1, "NAME :\v MY_HUNTER\nHOW TO USE :\v", 32);
    write(1, " Execute the game : ./my_hunter\nTOOLS :\v", 41);
    write(1, " Use mouse : left click\nHISTORY :\v", 35);
    write(1, " JUL had discovered the earth\n", 31);
    write(1, "\t  Protect the planet killing JUL and UFOs\n", 44);
    return (0);
}

int check_h_and_errors(int ac, char **av)
{
    if (ac > 1) {
        if ((av[1][0] == 'h' || av[1][1] == 'h') && ac == 2)
            return (print_description());
        return (84);
    }
    return (1);
}

int main(int ac, char **av)
{
    window_t w;
    char *title = "MY HUNTER";
    int h = check_h_and_errors(ac, av);
    w.icon = sfImage_createFromFile("assets/icon_jul.jpg");

    if (h == 84)
        return (84);
    if (h == 0)
        return (0);
    w.tbg0 = sfTexture_createFromFile("assets/City1.png", NULL);
    set_music(&w);
    sfVideoMode mode = {1646, 938, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, title, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 160);
    sfRenderWindow_setIcon(window, 256, 256, sfImage_getPixelsPtr(w.icon));
    run_menu(window, &w);
    while (w.try_again)
        run_window(window, &w);
    return (0);
}
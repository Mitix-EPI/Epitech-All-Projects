/*
** EPITECH PROJECT, 2019
** PSU_my_popup_2019
** File description:
** main
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

char *map_reader(char *map, long size)
{
    int fd = 0;
    int reader = 0;
    char *buffer = malloc(sizeof(char) * size + 1);

    fd = open(map, O_RDONLY);
    if (fd == -1 || errno == 2 || errno == 21)
        return (NULL);
    reader = read(fd, buffer, size);
    if (reader > 0) {
        close(fd);
        return (buffer);
    }
    free(buffer);
    close(fd);
    return (NULL);
}

int play_sokoban(sokoban_t *s, char *map)
{
    int mv = 0;
    s->s_mod = s->stra;
    find_o(s);
    while (1) {
        if (mv == 1)
            return (0);
        if (mv == 2)
            return (1);
        clear();
        noecho();
        print_map(s);
        check_sh(s, map);
        if (s->ch == 'x')
            return (0);
        find_p(s);
        mv = move_player(s);
        my_disp(s);
    }
    return (0);
}

int end(char *map, sokoban_t *s)
{
    clear();
    print_map(s);
    refresh();
    endwin();
    free(map);
    free(s->stra);
    return (0);
}

int main_sokoban(int argc, char **argv, sokoban_t *s)
{
    char *map = NULL;
    struct stat fileStat;

    if (print_usage(argv, s))
        return (0);
    if (stat(argv[1], &fileStat) < 0)
        return (84);
    map = map_reader(argv[1], fileStat.st_size);
    if (map == NULL || check(argc, map, s))
        return (84);
    initscr();
    curs_set(0);
    if (play_sokoban(s, map) == 1) {
        end(map, s);
        return (1);
    }
    return (end(map, s));
}
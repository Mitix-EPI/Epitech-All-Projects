/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** main
*/

#include "../include/my.h"

int print_help(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid:  only for the 2nd player.");
    my_putstr("  pid of the first player.\n\tnavy_positions:  file ");
    my_putstr("representing the positions of the ships.\n");
    return (0);
}

int check_map(char **map)
{
    int i = 0;
    int count = 2;

    for (; map[i] != NULL && map[i][0]; i++, count++)
        if (map[i][0] != count + '0')
            return (1);
    if (count != 6)
        return (1);
    if (check_file(map) == 1)
        return (1);
    if (check_lenght_boat(map) == 1)
        return (1);
    return (0);
}

int rigor_map(char *path)
{
    struct stat fileStat;
    int fd = 0;
    char *file = malloc(sizeof(char) * (1024 + 1));
    char **map = NULL;
    int rd = 0;

    if (stat(path, &fileStat) < 0) {
        return (1);
    }
    fd = open(path, O_RDONLY);
    rd = read(fd, file, 1024);
    file[rd] = '\0';
    map = open_pos(file);
    if (check_map(map) == 1) {
        return (1);
    }
    close(fd);
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    return (0);
}

int rigor(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return (1);
    if (ac == 2)
        return (rigor_map(av[1]));
    if (ac == 3)
        return (rigor_map(av[2]));
    return (0);
}

int main(int ac, char **av)
{
    if (rigor(ac, av) == 1)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        return (print_help());
    } else if (ac == 2 || ac == 3) {
        return (main_navy(ac, av));
    } else
        return (84);
}
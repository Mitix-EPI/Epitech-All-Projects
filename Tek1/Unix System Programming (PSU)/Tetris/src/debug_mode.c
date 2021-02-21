/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** debug_mode
*/

#include "../include/my.h"
#include <string.h>

int dot_tetrimino(char *str)
{
    char *tetri = my_revstr(".tetrimino");
    char *rev = my_revstr(str);
    char *check = malloc(sizeof(char) * (my_strlen(tetri) + 1));
    int i = 0;

    for (; i != my_strlen(tetri) && rev[i]; i += 1)
        check[i] = rev[i];
    check[i] = 0;
    if (my_strcmp(check, tetri) == 0) {
        free(check);
        return (1);
    } else {
        free(check);
        return (0);
    }
}

int verif_size(char *str, int x)
{
    int i = 0;
    int count = 0;
    char *mod_str = NULL;

    for (; str[i]; i++) {
        if (str[i] != '*' && str[i] != ' ' && str[i] != '\n')
            return (84);
    }

    mod_str = remove_spaces_at_the_end(str);
    if (my_strlen(mod_str) != x) {
        return (0);
    }
    return (1);
}

int print_tetrimino(char **map)
{
    for (int i = 1; map[i] != NULL && map[i][0] && map[i]; i++)
        my_printf("%s\n", map[i]);
    return (1);
}

int check_tetrimino(tetris_t *tetris)
{
    char **name_files = NULL;

    name_files = display_nb_files(tetris);
    if (!name_files)
        return (1);
    name_files = alpha_sort(name_files);
    display_info_files(name_files, tetris);
    return (0);
}

/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** handling_debug
*/

#include "../include/my.h"

int end_handle_size(char **map, tetris_t *tetris, tetrimino_t *tetrimino, \
first_line_t *line)
{
    tetrimino->x = line->x;
    tetrimino->y = line->y;
    tetrimino->origin = map;
    tetrimino->type = copy_arrays(tetrimino->type, tetrimino->origin);
    if (tetris->debug == 1) {
        my_printf("Size %d*%d : Color %d :\n", line->x, line->y, line->z);
        return (print_tetrimino(tetrimino->type));
    }
    return (1);
}

int handle_size(char **map, tetris_t *tetris, tetrimino_t *tetrimino)
{
    first_line_t line;
    int i = 0;
    int yolo = 0;
    int res = 0;

    if (x_y_z_handling(map, &line) == 0)
        return (0);
    i = 1;
    for (int res = 0; map[i] != NULL && map[i][0]; i++) {
        res = verif_size(map[i], line.x);
        if (res == 1)
            yolo += 1;
        if (res == 84)
            return (0);
    }
    if (yolo == 0 || i - 1 != line.y)
        return (0);
    return (end_handle_size(map, tetris, tetrimino, &line));
}

void handling_space_map(char **map)
{
    for (int i = 1; map[i] != NULL && map[i][0] != 0; i++) {
        map[i] = remove_spaces_at_the_end(map[i]);
    }
}

int x_y_z_handling(char **map, first_line_t *line)
{
    line->i = 0;

    if (map[0][line->i] < 48 || map[0][line->i] > 57)
        return (0);
    line->x = my_getnbr(map[0]);
    for (; map[0][line->i] != ' '; line->i++);
    if (map[0][line->i + 1] < 48 || map[0][line->i + 1] > 57)
        return (0);
    line->y = my_getnbr(&map[0][line->i]);
    for (line->i += 1; map[0][line->i] != ' '; line->i++);
    if (map[0][line->i + 1] < 48 || map[0][line->i + 1] > 57)
        return (0);
    line->z = my_getnbr(&map[0][line->i]);
    return (1);
}

int handle_color(char **map, tetrimino_t *tetrimino)
{
    int i = 0;
    int z = 0;

    if (!map[0][0] || !map[0][1] || !map[0][2] || my_strlen(map[0]) < 5)
        return (0);
    for (; map[0][i] != ' '; i++);
    for (i += 1; map[0][i] != ' '; i++);
    if (map[0][i + 1] < 48 || map[0][i + 1] > 57)
        return (0);
    z = my_getnbr(&map[0][i]);
    if (z < 0 || z > 15)
        return (0);
    tetrimino->color = z;
    return (1);
}

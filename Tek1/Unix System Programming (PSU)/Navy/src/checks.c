/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** checks
*/

#include "../include/my.h"

int condition1(char *line, char *char_pos)
{
    if (line[3] - 48 == line[6] - 48 && char_pos[1] - 48 == line[3] - 48)
        return (1);
    return (0);
}

int condition2(char *line, char *char_pos)
{
    if (char_pos[1] - 48 >= line[3] - 48 && char_pos[1] - 48 <= line[6] - 48)
        return (1);
    return (0);
}

int check_if_it_touches_the_player(char *char_pos)
{
    int x = 0;
    int y = 0;

    for (; data.board[0][x] && data.board[0][x] != char_pos[0]; x++);
    for (; data.board[y][0] && data.board[y][0] != char_pos[1]; y++);
    if (data.board[y][x] == 'x')
        return (0);
    for (int i = 0; data.pos_map[i] != NULL; i++) {
        if (char_pos[0] >= data.pos_map[i][2] &&
        char_pos[0] <= data.pos_map[i][5]) {
            if (condition1(data.pos_map[i], char_pos))
                return (1);
            if (condition2(data.pos_map[i], char_pos))
                return (1);
        }
    }
    return (0);
}

int check_lenght_boat(char **map)
{
    for (int i = 0; map[i] != NULL && map[i][0]; i++) {
        if (map[i][2] == map[i][5]) {
            if ((map[i][6] - map[i][3] + 1 != (map[i][0] - 48)))
                return (1);
        }
        else if (map[i][2] != map[i][5])
            if ((map[i][5] - map[i][2] + 1 != (map[i][0] - 48)))
                return (1);
    }
    return (0);
}

int check_file(char **map)
{
    for (int j = 0; map[j] != NULL && map[j][0]; j++) {
        if (my_strlen2(map[j]) != 7)
            return (1);
        if (my_char_isalpha(map[j][2]) == 0 ||
        my_char_isalpha(map[j][5]) == 0)
            return (1);
        if (my_char_isnum(map[j][0]) || my_char_isnum(map[j][3]) ||
        my_char_isnum(map[j][6]))
            return (1);
        if (map[j][1] != ':' || map[j][4] != ':')
            return (1);
    }
    return (0);
}
/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** calc
*/

#include "include/my.h"

int calc_start(char *map)
{
    int start = 0;

    for (start; map[start] >= '0' && map[start] <= '9'; start++);
    start++;
    return (start);
}

int calc_min(int *m_i, int i, int j, int nb_c)
{
    int nb1 = m_i[nb_c * (i - 2) + (j - 1)];
    int nb2 = m_i[nb_c * (i - 1) + (j - 1)];
    int nb3 = m_i[nb_c * (i - 2) + j];

    if (nb1 <= nb2 && nb1 <= nb3)
        return (nb1);
    else if (nb2 <= nb1 && nb2 <= nb3)
        return (nb2);
    else
        return (nb3);
}

void calc_int(int *map_int, square_t *sq_c)
{
    int line = sq_c->nb_lines;
    int column = sq_c->nb_char;
    int pos = 0;
    int min = 0;

    column += 1;
    for (int i = 2; i <= line; i++)
        for (int j = 1; j < column - 1; j++) {
            pos = ((column * (i - 1)) + j);
            if (map_int[pos] == 0)
                map_int[pos] = 0;
            else {
                min = calc_min(map_int, i, j, column);
                map_int[pos] = min + 1;
            }
        }
}

int my_linelen(char *map)
{
    int res = 0;
    int i = 0;

    for (i = 0; map[i] >= '0' && map[i] <= '9'; i++);
    i++;
    for (i; map[i] != '\n'; res++, i++);
    return (res);
}

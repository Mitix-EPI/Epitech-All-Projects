/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load_map
*/

#include "rafik.h"
#include "rpg.h"

int my_getnbr(char *str)
{
    int sum = 0;
    int sign = 1;
    int i = 0;

    while (str[i] && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-')
            sign = sign * -1;
        i += 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            sum = (sum * 10) + (str[i] - '0');
            i += 1;
        } else if (sum == 2147483647)
            return 0;
        else
            return (sum * sign);
    }
    return (sum * sign);
}

int **get_map(void)
{
    int **obj = NULL;
    int fd = open("map/colli_with_spawns.txt", O_RDONLY);

    obj = malloc(sizeof(int *) * 141);
    obj[140] = NULL;
    for (int i = 0; i < 140; i += 1)
        obj[i] = malloc(sizeof(int) * 140);
    for (int i = 0; i < 140; i += 1)
        for (int j = 0; j < 140; j += 1)
            obj[i][j] = my_getnbr(get_next_char(fd, ':'));
    return (obj);
}
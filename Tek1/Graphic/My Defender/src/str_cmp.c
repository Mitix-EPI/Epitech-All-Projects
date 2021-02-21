/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "../my_tower.h"

int str_cmp(char *str, char *str2)
{
    if (my_strlen(str) != my_strlen(str2))
        return (0);
    for (int temp = 0; str[temp]; temp += 1) {
        if (str[temp] != str2[temp])
            return (0);
    }
    return (1);
}
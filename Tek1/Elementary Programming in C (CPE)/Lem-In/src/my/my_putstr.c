/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** function to display a string
*/

#include "lemin.h"

int my_putstr(int ouput, char *str)
{
    for (int i = 0; str[i]; i += 1) {
        write(ouput, &str[i], 1);
    }
    if (ouput == 2)
        return (84);
    return (0);
}
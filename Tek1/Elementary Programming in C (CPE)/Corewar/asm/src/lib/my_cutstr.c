/*
** EPITECH PROJECT, 2020
** my cutstr
** File description:
** fuction to remove end str
*/

#include "asm.h"

void my_cutstr(char *str)
{
    for (int i = 0; str[i]; i += 1) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        if (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == '\n')) {
            str[i] = '\0';
            break;
        }
    }
}
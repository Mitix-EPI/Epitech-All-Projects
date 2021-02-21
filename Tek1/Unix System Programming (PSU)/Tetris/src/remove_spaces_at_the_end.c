/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** remove_spaces_at_the_end
*/

#include "../include/my.h"

int string_length(char *pointer)
{
    int c = 0;

    while (*(pointer + c) != '\0')
        c++;
    return c;
}

void reverse(char *s)
{
    int length = 0;
    int c = 0;
    char *begin = NULL;
    char *end = NULL;
    char temp = 0;

    length = string_length(s);
    begin  = s;
    end    = s;
    for (c = 0; c < length - 1; c++)
        end++;
    for (c = 0; c < length / 2; c++) {
        temp = *end;
        *end = *begin;
        *begin = temp;
        begin++;
        end--;
    }
}

char *remove_spaces_at_the_end(char *str)
{
    int i = 0;
    int count = 0;
    char *good_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    my_revstr(str);
    for (int start = 0; str[i]; i++) {
        if (str[i] == ' ' && start == 0) {
        } else {
            start = 1;
            good_str[count] = str[i];
            count++;
        }
    }
    good_str[count] = 0;
    my_revstr(good_str);
    return (good_str);
}

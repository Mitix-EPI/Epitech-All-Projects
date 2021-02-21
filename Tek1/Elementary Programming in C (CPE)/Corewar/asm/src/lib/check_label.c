/*
** EPITECH PROJECT, 2020
** check label
** File description:
** return 0 if no label, else return difference between start and end index
*/

#include "asm.h"

int char_label_is_correct(char c) {
    char tmp[] = LABEL_CHARS;

    for (int i = 0; tmp[i]; i += 1)
        if (c == tmp[i])
            return (1);
    return (0);
}

int check_label(char *ln)
{
    int i = 0;

    for (; ln[i] && (ln[i] == ' ' || ln[i] == '\t'); i += 1);
    for (; ln[i] && ln[i] != '\t' && ln[i] != ' '; i += 1) {
        if (ln[i] == ':' && ln[i + 1] != ':')
            return (i);
        if (!char_label_is_correct(ln[i]))
            my_exit(INCORRECT_LABEL_NAME);
    }
    return (0);
}

int is_label_without_instruction(char *ln)
{
    int i = 0;
    int tmp = 0;

    for (; ln[i] && (ln[i] == ' ' || ln[i] == '\t'); i += 1);
    for (; ln[i] && ln[i] != '\t' && ln[i] != ' '; i += 1)
        if (ln[i] == ':')
            break;
    tmp = i;
    for (i = i + 1; ln[i] && (ln[i] == ' ' || ln[i] == '\t'); i += 1);
    if (!ln[i])
        return (tmp);
    return (0);
}
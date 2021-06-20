/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** parse_command
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_arg(char *buffer);

int calc_size_word(char *buf, int pos)
{
    int res = 0;
    int quotes_state = 0;

    int j = pos;
    for (; buf && buf[j] && buf[j] == ' ' && buf[j] != '\r' && \
    buf[j] != '\n'; j++);
    for (int i = j; buf && buf[i] && buf[i] != '\r' && buf[i] != '\n'; i++) {
        if (buf[i] == '"') {
            if (quotes_state == 0)
                quotes_state = 1;
            else if (quotes_state == 1)
                quotes_state = 0;
            res++;
        } else if (buf[i] == ' ' && quotes_state == 0) {
            return (res);
        } else
            res++;
    }
    return (res);
}

int set_quotes_state(char *buffer, int i, int *quotes_state)
{
    if (buffer[i] == '"' && *quotes_state == 0) {
        *quotes_state = 1;
        return (1);
    } else if (buffer[i] == '"' && *quotes_state == 1) {
        *quotes_state = 0;
        return (1);
    }
    return (0);
}

char *get_word_in_buffer(char *buf, int *ptr)
{
    int size_word = calc_size_word(buf, *ptr);
    if (size_word < 1)
        return (NULL);
    char *res = malloc(sizeof(char) * (size_word + 1));
    int pos = 0;
    int quotes_state = 0;
    int j = *ptr;

    memset(res, 0, size_word + 1);
    for (; buf && buf[j] && buf[j] == ' ' && buf[j] != '\r' && \
    buf[j] != '\n'; j++, *ptr += 1);
    for (int i = j; buf && buf[i] && buf[i] != '\r' && \
    buf[i] != '\n'; i++, *ptr += 1) {
        if (set_quotes_state(buf, i, &quotes_state)) {
            res[pos++] = buf[i];
        } else if (buf[i] == ' ' && quotes_state == 0)
            return (res);
        else
            res[pos++] = buf[i];
    }
    return (res);
}

char **parse_command(char *buffer)
{
    int size = count_arg(buffer);
    char **res = malloc(sizeof(char *) * (size + 1));

    res[size] = NULL;
    int pos = 0;
    for (int i = 0; i < size; i++)
        res[i] = get_word_in_buffer(buffer, &pos);
    return (res);
}

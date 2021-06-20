/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line
*/

#include "../../include/common/get_next_line.h"

char *my_realloc(char *str, int n)
{
    int len = 0;
    char *tmp = NULL;
    int i = 0;

    for (len = 0; str[len]; len++);
    tmp = malloc(sizeof(tmp) * (len + n + 1));
    if (!tmp)
        return (NULL);
    for (i = 0; str[i] != 0; i += 1)
        tmp[i] = str[i];
    tmp[i] = 0;
    free(str);
    return (tmp);
}

char *ending_choice(char *msg, int i, int rd, int *idx)
{
    if (rd == 0 && i == 0)
        return (NULL);
    else {
        *idx += 1;
        return (msg);
    }
}

char *buff_size_alloc(int *msg_size, char *msg, char *buff, int i)
{
    msg[i] = 0;
    *msg_size += READ_SIZE;
    buff[READ_SIZE] = 0;
    msg = my_realloc(msg, *msg_size);
    if (msg == NULL || !msg)
        return (NULL);
    msg[*msg_size] = 0;
    return (msg);
}

int reader(int *rd, int *idx, int fd, char *buff)
{
    if (*rd <= *idx) {
            *rd = read(fd, buff, READ_SIZE);
            *idx = 0;
    }
    if (*rd == -1)
        return (1);
    return (0);
}

char *get_next_line(int fd)
{
    static char buff[READ_SIZE];
    int msg_size = READ_SIZE + 1;
    char *msg = malloc(sizeof(msg) * (msg_size));
    static int idx = 1;
    static int rd = 1;
    int i = 0;

    if (fd < 0 || READ_SIZE <= 0 || !msg)
        return (NULL);
    while (rd != 0 && buff[idx] != '\n') {
        msg = buff_size_alloc(&msg_size, msg, buff, i);
        if (msg == NULL || !msg)
            return (NULL);
        if (reader(&rd, &idx, fd, buff))
            return (NULL);
        for (; rd > idx && buff[idx] != '\n'; i += 1, idx += 1)
            msg[i] = buff[idx];
    }
    msg[i] = '\0';
    return (ending_choice(msg, i, rd, &idx));
}
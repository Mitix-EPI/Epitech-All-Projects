/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_header
*/

#include "asm.h"

void write_comment(int fd, char *comment)
{
    char *str = my_strdup(comment);
    int len = COMMENT_LENGTH;
    int tmp = 0;

    write(fd, str, my_strlen(str));
    len -= my_strlen(str);
    for (int i = 0; i < len; i++)
        write(fd, "\0", 1);
    write(fd, &tmp, sizeof(tmp));
    free(str);
}

void write_name(int fd, char *name, int size_prog)
{
    char *str = my_strdup(name);
    int len = PROG_NAME_LENGTH;
    int tmp = 0;

    write(fd, str, my_strlen(str));
    len -= my_strlen(str);
    for (int i = 0; i < len; i++)
        write(fd, "\0", 1);
    write(fd, &tmp, sizeof(tmp));
    write(fd, &size_prog, sizeof(size_prog));
    free(str);
}

void write_magic_number(int fd)
{
    int magic = COREWAR_EXEC_MAGIC;

    magic = little_to_big(magic);
    write(fd, &magic, sizeof(magic));
}

int write_header(int fd, char *name, char *comment, int size_prog)
{
    write_magic_number(fd);
    write_name(fd, name, size_prog);
    write_comment(fd, comment);
    return (0);
}
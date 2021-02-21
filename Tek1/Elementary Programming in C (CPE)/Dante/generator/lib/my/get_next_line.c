/*
** EPITECH PROJECT, 2019
** GetNextLine
** File description:
** get_next_line
*/

#include "get_next_line.h"

char *my_realloc(char *src, int nb)
{
    char *dest = NULL;
    int len = 0;
    int i = 0;

    if (src == NULL) {
        dest = malloc(sizeof(char) * 2);
        if (dest)
            dest[0] = 0;
        return dest;
    }
    while (src[len] != '\0')
        len += 1;
    dest = malloc(sizeof(char) * (len + nb));
    for (; src[i] != '\0'; i += 1)
        dest[i] = src[i];
    free(src);
    dest[i] = 0;
    return (dest);
}

void copy_and_flush(char *str, int *index, int *test, int fd)
{
    if (str[*index] == 0) {
        *index = 0;
        for (int j = 0; j < READ_SIZE; j += 1)
            str[j] = 0;
        *test = read(fd, str, READ_SIZE);
    }
}

char *management(char *result, int test)
{
    if (result[0] == '\0' && test == 0) {
        free(result);
        return (NULL);
    }
    return (result);
}

char *read_and_display_read_line(int fd)
{
    static char str[READ_SIZE + 1];
    static int index = 0;
    char *result = my_realloc(NULL, 2);
    int i = 0;
    int test = 15;

    if (!result)
        return (NULL);
    while (str[index] != '\n' && test != 0) {
        copy_and_flush(str, &index, &test, fd);
        if (test < 0)
            return (NULL);
        for (; str[index] != '\n' && str[index] != '\0'; i += 1, index += 1) {
            result[i] = str[index];
            result[i + 1] = 0;
            result = my_realloc(result, 2);
        }
    }
    index += 1;
    return (management(result, test));
}

char *get_next_line(int fd)
{
    static int lines = 0;
    char *result = NULL;

    if (READ_SIZE <= 0)
        return (NULL);
    if (fd < 0)
        return (NULL);
    result = read_and_display_read_line(fd);
    lines += 1;
    return (result);
}
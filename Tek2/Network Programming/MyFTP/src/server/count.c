/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** count
*/

#include "server/my_ftp.h"

unsigned int rand_interval(unsigned int min, unsigned int max)
{
    unsigned int r = 0;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;

    do {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}

int count_arg_command(char **command)
{
    size_t size = 0;

    for (; command && command[size] != NULL; size++);
    return size;
}

int count_char(char *str, char c)
{
    int count = 0;

    for (int i = 0; str && str[i]; i++)
        if (str[i] == c)
            count++;
    return count;
}

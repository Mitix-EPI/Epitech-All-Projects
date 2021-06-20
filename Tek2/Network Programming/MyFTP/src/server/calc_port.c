/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** calc_port
*/

#include "server/my_ftp.h"

char **parse_str(char *buffer, char *delimiters)
{
    char **array = NULL;
    char *pch = NULL;
    size_t size = 0;

    pch = strtok(buffer, delimiters);
    while (pch != NULL) {
        size++;
        array = realloc(array, sizeof(char *) * (size + 1));
        array[size - 1] = pch;
        array[size] = NULL;
        pch = strtok(NULL, " \r\n");
    }
    return array;
}

uint16_t get_port(int fd)
{
    struct sockaddr_in address;
    socklen_t size = sizeof(address);

    if (getsockname(fd, (struct sockaddr *)&address, &size) < 0)
        return 0;
    else
        return ntohs(address.sin_port);
}

uint16_t calc_port(char *str)
{
    char **tmp = parse_str(str, ".");
    for (int i = 0; tmp && tmp[i] != NULL; i++) {
        printf("%s\n", tmp[i]);
    }
    int port1 = atoi(tmp[0]) * 256;
    int port2 = atoi(tmp[1]);
    return port1 + port2;
}

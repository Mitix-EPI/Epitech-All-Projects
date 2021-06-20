/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** send
*/

#include "server/my_ftp.h"

char *my_strcat(char *s1, char *s2)
{
    int len = strlen(s1) + strlen(s2);
    char *ret = malloc(sizeof(s1) * (len + 1));
    int i = 0;

    for (; s1[i]; i += 1)
        ret[i] = s1[i];
    for (int j = 0; s2[j]; j += 1, i += 1)
        ret[i] = s2[j];
    ret[i] = '\0';
    return (ret);
}

void send_response(int fd, int code, char *message)
{
    char buffer[1024] = {0};
    sprintf(buffer, "%d ", code);
    char *msg = strdup(message);
    char *end = strdup("\r\n");
    char *msgEnd = my_strcat(msg, end);
    char *res = my_strcat(buffer, msgEnd);

    write(fd, res, strlen(res));
    free(msg);
    free(end);
    free(msgEnd);
    free(res);
}

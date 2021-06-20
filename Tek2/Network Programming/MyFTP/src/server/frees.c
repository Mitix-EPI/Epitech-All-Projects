/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** frees
*/

#include "server/my_ftp.h"

void free_serv(serv_ftp_t *serv)
{
    free(serv->path);
    for (int i = 0; i < 100; i++) {
        if (serv->servers[i].serverfd != 0) {
            close(serv->servers[i].serverfd);
        }
    }
}

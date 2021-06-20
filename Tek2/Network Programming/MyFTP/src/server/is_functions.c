/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** is_functions
*/

#include "server/my_ftp.h"

int is_client_logged_in(client_ftp_t *client)
{
    if (client->isLogged)
        return 1;
    return 0;
}

int is_mode_activated(client_ftp_t *client)
{
    if (client->state != NONE)
        return 1;
    return 0;
}

int is_valid_ip_address(char *ipAddress)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return result != 0;
}

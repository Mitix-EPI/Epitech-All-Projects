/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** display
*/

#include "server/my_ftp.h"

int display_error(char *errorMessage)
{
    fprintf(stderr, "%s\n", errorMessage);
    exit(84);
}

int display_help(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("port  is the port number on which the server socket listens\n");
    printf("path  is the path to the home directory for the Anonymous user\n");
    exit(0);
}

void show_client(client_ftp_t *client)
{
    printf("\nClient from %s:%d\n", inet_ntoa(client->address.sin_addr),
    ntohs(client->address.sin_port));
    printf("Username: %s\n", !client->username ? "NULL" : client->username);
    printf("Password: %s\n", !client->password ? "NULL" : client->password);
    printf("Socket: %d\n\n", client->socket);
}

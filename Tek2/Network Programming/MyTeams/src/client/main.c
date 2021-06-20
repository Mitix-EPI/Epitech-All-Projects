/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** main
*/

#include "client/myteams.h"

int is_valid_ip_address(char *ipAddress)
{
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ipAddress, &(sa.sin_addr));
    return (result != 0);
}

int display_help(void)
{
    printf("USAGE ./myteams_cli ip port\n");
    printf("\tip\tis the server ip address on which the server socket \
listens\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    return (0);
}

int display_error(char *message)
{
    printf("Error: %s\n", message);
    return (84);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return (display_help());
    if (ac != 3)
        return (display_error("Not valid arguments. \
Please use ./myteams_cli -help"));
    int port = atoi(av[2]);
    if (port <= 2)
        return (display_error("Invalid port."));
    if (!is_valid_ip_address(av[1]))
        return (display_error("Incorrect IP."));
    printf("Client Initialiazing...\n");
    launch_client(av[1], port);
    return (0);
}
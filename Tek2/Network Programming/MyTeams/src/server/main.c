/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** main
*/

#include "server/myteams.h"

int display_help(void)
{
    printf("USAGE ./myteams_server port\n\n");
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
    if (ac != 2)
        return (display_error("Not valid arguments. \
Please use ./myteams_server -help"));
    if (strcmp(av[1], "-help") == 0)
        return (display_help());
    int port = atoi(av[1]);
    if (port <= 2)
        return (display_error("Port is incorrect."));
    printf("Server Initialiazing...\n");
    launch_server(port);
    return (0);
}

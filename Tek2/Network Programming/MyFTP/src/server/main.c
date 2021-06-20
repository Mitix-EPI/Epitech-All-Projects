/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** main
*/

#include "server/my_ftp.h"

void run_server(serv_ftp_t *serv)
{
    client_ftp_t *clients[100];

    init_run(serv, clients);
    while (serv->running) {
        reset_fds(serv, clients);
        if (select(serv->max_sd + 1, &serv->readFdSet, NULL, NULL, NULL) < 0) {
            perror("Select failed");
            exit(EXIT_ERROR);
        }
        check_incoming_servers(serv, clients);
        check_incoming_request(serv, clients);
    }
}

serv_ftp_t *get_serv_struct(void)
{
    static serv_ftp_t res;

    return (&res);
}

static void sig_handler(int code)
{
    (void) code;
    serv_ftp_t *res = get_serv_struct();

    printf("\n");
    free_serv(res);
    exit(EXIT_SUCCESS);
}

void launch_server(int port, char *path)
{
    serv_ftp_t *serv = get_serv_struct();
    init_serv_struct(serv, port, path);
    signal(SIGINT, sig_handler);
    signal(SIGPIPE, sig_handler);
    init_server(serv);
    printf("\nServer Running ...\n");
    run_server(serv);
    free_serv(serv);
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        display_help();
    if (ac != 3)
        display_error("Error: Not good number of arguments. Please use -h.");
    printf("Server Initialiazing ...\n");
    int port = atoi(av[1]);
    if (port <= 0)
        display_error("Error: Port is incorrect.");
    if (!av[2] || strcmp(av[2], " ") == 0) {
        display_error("Error: Path is incorrect.");
    }
    launch_server(port, av[2]);
    return 0;
}

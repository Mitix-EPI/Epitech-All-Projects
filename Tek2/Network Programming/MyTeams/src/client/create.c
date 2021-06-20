/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** create
*/

#include "client/myteams.h"

int create_handle_error(client_t *cli, char **command)
{
    if ((cli->_context != THREAD && len_command(command) != 3) \
    || (cli->_context == THREAD && len_command(command) != 2)) {
        printf("Not good number of args.\n");
        return (1);
    }
    if ((len_command(command) == 3 && check_quote(command[1])
    && check_quote(command[2])) || (len_command(command) == 2
    && check_quote(command[1]))) {
        printf("Arguments must be in quote.\n");
        return (1);
    }
    if (cli->is_logged != 1) {
        client_error_unauthorized();
        return (1);
    }
    return (0);
}

void create_func(client_t *cli, char **command)
{
    char buf[1060] = {0};
    char tmp[512] = {0};

    if (create_handle_error(cli, command))
        return;
    snprintf(buf, sizeof(buf), "%s", "create");
    for (int i = 1; command[i] != NULL; i++) {
        snprintf(tmp, sizeof(tmp), " %s ", command[i]);
        strcat(buf, tmp);
    }
    strcat(buf, "\r\n");
    write(cli->sock, buf, strlen(buf));
}

void create_success_handle(char **command)
{
    create_team(command);
    create_channel(command);
    create_thread(command);
    create_reply(command);
}

void create_res(client_t *cli, char **command)
{
    (void) cli;
    if (strcmp(command[2], "already_exist") == 0)
        client_error_already_exist();
    create_success_handle(command);
}

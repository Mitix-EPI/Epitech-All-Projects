/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** use
*/

#include "client/myteams.h"

int use_handle_error(client_t *cli, char **command)
{
    if (len_command(command) > 4) {
        printf("Not good number of args.\n");
        return (1);
    }
    for (int i = 1; command[i] != NULL; i++)
        if (check_quote(command[i])) {
            printf("Argument must be in quote.\n");
            return (1);
        }
    if (cli->is_logged != 1) {
        client_error_unauthorized();
        return (1);
    }
    return (0);
}

void use_func(client_t *cli, char **command)
{
    char buf[1060] = {0};
    char tmp[512] = {0};

    if (use_handle_error(cli, command))
        return;
    snprintf(buf, sizeof(buf), "%s", "use");
    for (int i = 1; command[i] != NULL; i++) {
        snprintf(tmp, sizeof(tmp), " %s ", command[i]);
        strcat(buf, tmp);
    }
    strcat(buf, "\r\n");
    write(cli->sock, buf, strlen(buf));
}

void use_res(client_t *cli, char **command)
{
    (void) cli;
    for (int i = 0; command[i] != NULL; i++)
        printf("%s ", command[i]);
    printf("\n");
    if (len_command(command) == 3 && strcmp(command[1], "success") == 0)
        cli->_context = atoi(command[2]);
}
/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** handle_response
*/

#include "client/myteams.h"

static command_t func[] =
{
    {"login", &login_res},
    {"logout", &logout_res},
    {"users", &users_res},
    {"user", &user_res},
    {"send", &send_res},
    {"messages", &messages_res},
    {"use", &use_res},
    {"create", &create_res},
    {"subscribed", &subscribed_res},
    {"subscribe", &subscribe_res},
};

void handle_response(client_t *cli, char *buffer)
{
    char **command = parse_command(buffer);
    size_t size = 10;

    if (!command || !command[0]) {
        printf("Server shutdown. Closing...\n");
        free_command(command);
        exit(0);
        return;
    }
    for (size_t i = 0; i < size; i++) {
        if (strcmp(command[0], func[i].command) == 0) {
            func[i].ptr(cli, command);
            free_command(command);
            return;
        }
    }
    printf("Response not recognized\n");
    free_command(command);
}

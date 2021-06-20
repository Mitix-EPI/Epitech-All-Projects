/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** handle_command
*/

#include "client/myteams.h"

static command_t func[] =
{
    {"/help", &help_func},
    {"/login", &login_func},
    {"/logout", &logout_func},
    {"/users", &users_func},
    {"/user", &user_func},
    {"/send", &send_func},
    {"/messages", &messages_func},
    {"/use", &use_func},
    {"/create", &create_func},
    {"/subscribed", &subscribed_func},
    {"/subscribe", &subscribe_func},
};

size_t len_command(char **command)
{
    size_t i = 0;

    for (; command && command[i] != NULL; i++);
    return (i);
}

void free_command(char **command)
{
    if (!command)
        return;
    free(command);
}

void handle_command(client_t *cli, char *buffer)
{
    char **command = parse_command(buffer);
    size_t size = 11;

    if (!command || !command[0]) {
        printf("Error request\n");
        free_command(command);
        return;
    }
    for (size_t i = 0; i < size; i++) {
        if (strcmp(command[0], func[i].command) == 0) {
            func[i].ptr(cli, command);
            free_command(command);
            return;
        }
    }
    printf("Command not recognized\n");
    free_command(command);
}

/*
** EPITECH PROJECT, 2021
** users
** File description:
** file
*/

#include "client/myteams.h"

void wait_users_func(client_t *cli)
{
    FILE *file = fdopen(cli->sock, "r");
    char *tmp = NULL;
    size_t len = 0;
    getline(&tmp, &len, file);
    users_res(cli, parse_command(tmp));
}

void users_func(client_t *cli, char **command)
{
    char buf[1060] = {0};
    if (len_command(command) != 1) {
        printf("Not good number of args.\n");
        return;
    }
    if (cli->is_logged != 1) {
        client_error_unauthorized();
        return;
    }
    snprintf(buf, sizeof(buf), "%s\r\n", "users");
    write(cli->sock, buf, strlen(buf));
    wait_users_func(cli);
}

users_list_t *parse_data(char **command)
{
    users_list_t *usersList = NULL;

    for (size_t i = 1; command && command[i] != NULL; i++) {
        char username[MAX_NAME_LENGTH] = {0};
        char uuid[37] = {0};
        get_uuid(command[i], uuid);
        get_username(command[i], username);
        user_data_t usr;
        strncpy(usr.uuid, uuid, 37);
        strncpy(usr.username, username, MAX_NAME_LENGTH);
        usr.sts = get_status(command[i]);
        usersList = add_user_at_the_end(usr, usersList);
    }
    return (usersList);
}

void free_users_list(users_list_t *usersList)
{
    if (!usersList)
        return;
    if (usersList)
        free_users_list(usersList->next);
    free(usersList);
}

void users_res(client_t *cli, char **command)
{
    (void) cli;
    if (strcmp(command[1], "error") == 0) {
        printf("Users cmd error\n");
    } else {
        users_list_t *usersList = parse_data(command);
        users_list_t *tmp = usersList;
        while (tmp) {
            client_print_users(tmp->usr.uuid, tmp->usr.username, \
            tmp->usr.sts);
            tmp = tmp->next;
        }
        free_users_list(usersList);
    }
}

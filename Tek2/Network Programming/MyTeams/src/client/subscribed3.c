/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** subscribed3
*/

#include "client/myteams.h"

users_list_t *parse_users_data(char **command)
{
    users_list_t *usersList = NULL;

    for (size_t i = 2; command && command[i] != NULL; i++) {
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

void remove_quotes_sub(char *src)
{
    size_t size = strlen(src);
    for (size_t i = 0; i < size; i++) {
        src[i] = src[i + 1];
    }
    src[size - 2] = 0;
}

/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** use
*/

#include "server/myteams.h"

context_e set_context2(server_t *s, client_t *cli, char **command, int ac)
{
    switch (ac) {
        case 3:
            strcpy(s->_actual_context_uuid, remove_quote(command[2]));
            return (is_valid_team(s, remove_quote(command[1])) ? \
            (is_valid_channel(s, remove_quote(command[2])) ? \
            CHANNEL : UNKNOWN_CHANNEL) : UNKNOWN_TEAM);
        case 4:
            strcpy(s->_actual_context_uuid, remove_quote(command[3]));
            return (is_valid_team(s, remove_quote(command[1])) ? \
            (is_valid_channel(s, remove_quote(command[2])) ? \
            (is_valid_thread(s, remove_quote(command[3])) ? \
            THREAD : UNKNOWN_THREAD) : UNKNOWN_CHANNEL) : UNKNOWN_TEAM);
        default:
            return (cli->_context);
    }
}

context_e set_context(server_t *s, client_t *cli, char **command)
{
    int ac = len_command(command);

    switch (ac) {
        case 1:
            strcpy(s->_actual_context_uuid, cli->_uuid);
            return (ROOT);
        case 2:
            strcpy(s->_actual_context_uuid, remove_quote(command[1]));
            return (is_valid_team(s, remove_quote(command[1])) ? \
            TEAM : UNKNOWN_TEAM);
        case 3:
            return (set_context2(s, cli, command, ac));
        case 4:
            return (set_context2(s, cli, command, ac));
        default:
            break;
    }
    return (ROOT);
}

char *choose_context(server_t *s, client_t *cli, char **command)
{
    context_e tmp = ROOT;
    char buf[4096] = {0};
    tmp = set_context(s, cli, command);
    switch (tmp) {
        case UNKNOWN_TEAM:
            snprintf(buf, sizeof(buf), "%s", "use error \"invalid team\"\r\n");
            break;
        case UNKNOWN_CHANNEL:
            snprintf(buf, sizeof(buf), "%s", \
            "use error \"invalid channel\"\r\n");
            break;
        case UNKNOWN_THREAD:
            snprintf(buf, sizeof(buf), "%s", \
            "use error \"invalid thread\"\r\n");
            break;
        default:
            snprintf(buf, sizeof(buf), "%s %d %s", "use success ", tmp, \
            "\r\n");
    }
    cli->_context = tmp;
    return (strdup(buf));
}

void use_func(server_t *s, client_t *cli, char **command)
{
    char buf[4096] = {0};
    char tmp[512] = {0};

    if (len_command(command) > 4) {
        printf("Internal error USE\n");
        snprintf(buf, sizeof(buf), "%s", "use");
        for (int i = 1; command[i] != NULL; i++) {
            snprintf(tmp, sizeof(tmp), " %s ", command[i]);
            strcat(buf, tmp);
        }
    } else
        snprintf(buf, sizeof(buf), "%s", choose_context(s, cli, command));
    write(cli->_socket, buf, strlen(buf));
}
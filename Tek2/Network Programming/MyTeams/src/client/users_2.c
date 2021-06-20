/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** users_2
*/

#include "client/myteams.h"

void get_uuid(char *cmd, char *tmp)
{
    for (int i = 1; i < 37 + 1 && cmd[i] != ','; i++) {
        tmp[i - 1] = cmd[i];
    }
}

void get_username(char *cmd, char *tmp)
{
    size_t pos = 0;
    for (; cmd[pos] != ','; pos++);
    pos++;
    for (int i = 0; cmd[pos] != ','; pos++, i++) {
        tmp[i] = cmd[pos];
    }
}

void get_description(char *cmd, char *tmp)
{
    size_t pos = 0;
    for (; cmd[pos] != ','; pos++);
    pos++;
    for (; cmd[pos] != ','; pos++);
    pos++;
    for (int i = 0; cmd[pos] != '>' && cmd[pos]; pos++, i++) {
        tmp[i] = cmd[pos];
    }
}

int get_status(char *cmd)
{
    return (cmd[strlen(cmd) - 2] - 48);
}

/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myftp-alexandre.juan
** File description:
** handle_command
*/

#include "server/my_ftp.h"

static command_t func[] =
{
    {"USER", &user_func},
    {"PASS", &pass_func},
    {"QUIT", &quit_func},
    {"CWD", &cwd_func},
    {"CDUP", &cdup_func},
    {"DELE", &dele_func},
    {"PWD", &pwd_func},
    {"PASV", &passv_func},
    {"PORT", &port_func},
    {"HELP", &help_func},
    {"NOOP", &noop_func},
    {"RETR", &retr_func},
    {"STOR", &stor_func},
    {"LIST", &list_func},
};

void unknow_command(int fd)
{
    send_response(fd, 500, "Command unknown.");
}

char **parse_command(char *buffer)
{
    char **array = NULL;
    char *pch = NULL;
    size_t size = 0;

    pch = strtok(buffer, " \r\n");
    while (pch != NULL) {
        size++;
        array = realloc(array, sizeof(char *) * (size + 1));
        array[size - 1] = pch;
        array[size] = NULL;
        pch = strtok(NULL, " \r\n");
    }
    return array;
}

void free_command(char **command)
{
    if (!command)
        return;
    free(command);
}

void handle_command(client_ftp_t *client, char *buffer, serv_ftp_t *serv)
{
    int fd = client->socket;
    char **command = parse_command(buffer);
    size_t size = 14;

    if (!command || !command[0]) {
        unknow_command(fd);
        free_command(command);
        printf("Error request\n");
        return;
    }
    for (size_t i = 0; i < size; i++) {
        if (strcmp(command[0], func[i].command) == 0) {
            func[i].ptr(client, command, serv);
            free_command(command);
            return;
        }
    }
    unknow_command(fd);
    printf("Command not recognized\n");
    free_command(command);
}

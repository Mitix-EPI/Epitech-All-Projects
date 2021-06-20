/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** db_messages
*/

#include "server/myteams.h"

void save_messages(server_t *s)
{
    int fd = open("teams_messages.db", O_CREAT | O_WRONLY | O_TRUNC, \
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    list_messages_t *tmp = s->_msgs;

    while (tmp) {
        write(fd, &tmp->msg, sizeof(message_t));
        tmp = tmp->next;
    }
    close(fd);
}

void read_messages(server_t *s)
{
    int fd = open("teams_messages.db", O_RDONLY);

    if (fd < 0) {
        printf("No file teams_messages.db\n");
        return;
    }
    message_t msg;
    for (int bt = 0, i = 0; (bt = read(fd, &msg, sizeof(message_t))) > 0; i++)
        s->_msgs = add_messages_at_the_end(msg, s->_msgs);
    close(fd);
}

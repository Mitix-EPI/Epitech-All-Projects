/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** db_reply
*/

#include "server/myteams.h"

void save_reply(server_t *s)
{
    int fd = open("teams_replies.db", O_CREAT | O_WRONLY | O_TRUNC, \
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    list_replies_t *tmp = s->_replies;

    while (tmp) {
        write(fd, &tmp->_reply, sizeof(reply_t));
        tmp = tmp->next;
    }
    close(fd);
}

void read_reply(server_t *s)
{
    int fd = open("teams_replies.db", O_RDONLY);

    if (fd < 0) {
        printf("No file teams_replies.db\n");
        return;
    }
    reply_t rpl;
    for (int bt = 0, i = 0; (bt = read(fd, &rpl, sizeof(reply_t))) > 0; i++)
        s->_replies = add_reply_at_the_end(rpl, s->_replies);
    close(fd);
}

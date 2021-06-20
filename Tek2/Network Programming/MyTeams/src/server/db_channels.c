/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** db_messages
*/

#include "server/myteams.h"

void save_channels(server_t *s)
{
    int fd = open("teams_channels.db", O_CREAT | O_WRONLY | O_TRUNC, \
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    list_channels_t *tmp = s->_channels;

    while (tmp) {
        write(fd, &tmp->_channel, sizeof(channel_t));
        tmp = tmp->next;
    }
    close(fd);
}

void read_channels(server_t *s)
{
    int fd = open("teams_channels.db", O_RDONLY);

    if (fd < 0) {
        printf("No file teams_channels.db\n");
        return;
    }
    channel_t channel;
    for (int bt = 0, i = 0; (bt = read(fd, &channel, \
    sizeof(channel_t))) > 0; i++)
        s->_channels = add_channel_at_the_end(channel, s->_channels);
    close(fd);
}

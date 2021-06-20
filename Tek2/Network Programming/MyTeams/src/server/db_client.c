/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** save_client
*/

#include "server/myteams.h"

void save_clients(server_t *s)
{
    int fd = open("teams_users.db", O_CREAT | O_WRONLY | O_TRUNC, \
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    list_users_t *tmp = s->_users;

    while (tmp) {
        write(fd, &tmp->usr, sizeof(user_t));
        tmp = tmp->next;
    }
    close(fd);
}

void read_clients(server_t *s)
{
    int fd = open("teams_users.db", O_RDONLY);

    if (fd < 0) {
        printf("No file teams_users.db\n");
        return;
    }
    user_t usr;
    for (int bt = 0, i = 0; (bt = read(fd, &usr, sizeof(user_t))) > 0; i++) {
        server_event_user_loaded(usr._uuid, usr._username);
        s->_users = add_node_at_the_end(usr, s->_users);
    }
    close(fd);
}

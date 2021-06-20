/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** db_subscribe
*/

#include "server/myteams.h"

void save_sub_clients_teams(server_t *s)
{
    int fd = open("teams_subscribe.db", O_CREAT | O_WRONLY | O_TRUNC, \
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    list_subteam_t *tmp = s->_subteam;

    while (tmp) {
        write(fd, &tmp->_usr_team_linked, sizeof(user_team_t));
        tmp = tmp->next;
    }
    close(fd);
}

void read_sub_clients_teams(server_t *s)
{
    int fd = open("teams_subscribe.db", O_RDONLY);

    if (fd < 0) {
        printf("No file teams_users.db\n");
        return;
    }
    user_team_t usr_team;
    for (int bt = 0, i = 0; \
    (bt = read(fd, &usr_team, sizeof(user_team_t))) > 0; i++) {
        s->_subteam = add_subteam_at_the_end(usr_team, s->_subteam);
    }
    close(fd);
}

/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** db_thread
*/

#include "server/myteams.h"

void save_thread(server_t *s)
{
    int fd = open("teams_thread.db", O_CREAT | O_WRONLY | O_TRUNC, \
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    list_threads_t *tmp = s->_threads;

    while (tmp) {
        write(fd, &tmp->_thread, sizeof(thread_t));
        tmp = tmp->next;
    }
    close(fd);
}

void read_thread(server_t *s)
{
    int fd = open("teams_thread.db", O_RDONLY);

    if (fd < 0) {
        printf("No file teams_thread.db\n");
        return;
    }
    thread_t thrd;
    for (int bt = 0, i = 0; (bt = read(fd, &thrd, sizeof(thread_t))) > 0; i++)
        s->_threads = add_thread_at_the_end(thrd, s->_threads);
    close(fd);
}

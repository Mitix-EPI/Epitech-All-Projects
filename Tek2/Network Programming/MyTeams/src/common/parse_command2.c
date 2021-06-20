/*
** EPITECH PROJECT, 2021
** B-NWP-400-MPL-4-1-myteams-alexandre.juan
** File description:
** parse_command2
*/

int loop_space(char *buf, int i)
{
    for (; buf && buf[i] && buf[i] == ' ' && buf[i] != '\r' && \
    buf[i] != '\n'; i++);
    return (i);
}

int count_arg(char *buf)
{
    int res = 0;
    int quotes_state = 0;
    int j = 0;
    for (; buf && buf[j] && buf[j] == ' ' && buf[j] != '\r' && \
    buf[j] != '\n'; j++);
    for (int i = j; buf && buf[i] && buf[i] != '\r' && buf[i] != '\n';) {
        if (buf[i] == '"') {
            if (quotes_state == 0)
                quotes_state = 1;
            else if (quotes_state == 1) {
                quotes_state = 0;
                i++;
            }
        } else if (buf[i] == ' ' && quotes_state == 0) {
            res++;
            i = loop_space(buf, i + 1) + 1;
        } else
            i++;
    }
    res++;
    return (res);
}

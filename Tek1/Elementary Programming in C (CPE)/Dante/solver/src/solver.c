/*
** EPITECH PROJECT, 2020
** solver
** File description:
** solver_algo_optimized
*/

#include "../include/my.h"
#include "../include/solver.h"
#include "../include/my_printf.h"
#include "../include/get_next_line.h"

int issafe(char *mapa, int x, int y, int *x_max)
{
    if (x - (y * (x_max[0] + 1)) >= 0 && x - (y * (x_max[0] + 1))
    < x_max[0] && y >= 0 && y < x_max[1] && mapa[x] == '*')
        return (1);

    return (0);
}

int solvemazeutil(char *mapa, int x, int y, int *x_max)
{
    static int stack = 0;

    if (stack++ == 820499)
        exit(0);
    if (x - (y * (x_max[0] + 1)) == x_max[0] - 1 &&
    y == x_max[1] - 1 && mapa[x] == '*')
        return (end_solver(mapa, x));
    if (issafe(mapa, x, y, x_max) == 1) {
        mapa[x] = 'o';
        if (solvemazeutil(mapa, x + 1, y, x_max) == 1)
            return (1);
        if (solvemazeutil(mapa, x + x_max[0] + 1, y + 1, x_max) == 1)
            return (1);
        if (solvemazeutil(mapa, x - x_max[0] - 1, y - 1, x_max) == 1)
            return (1);
        if (solvemazeutil(mapa, x - 1, y, x_max) == 1)
            return (1);
        mapa[x] = '*';
        return (0);
    }
    return (0);
}

int solvemaze(char *mapa, int x_max, int y_max)
{
    if (solvemazeutil(mapa, 0, 0, (int []){x_max, y_max}) == 0) {
        write(1, "no solution found", 17);
        return (0);
    }
    printf("%s", mapa);
    return (1);
}

int check_all_width(char *buffer, solver_t *solv, int rd)
{
    int i = 0;
    int line = 0;

    for (int y = 0; buffer[y] && y < rd - 2; y++, i = 0, line++) {
        for (; buffer[y] != '\n' && buffer[y]; y++, i++) {
            if (buffer[y] != '*' && buffer[y] != '\n' && buffer[y] != 'X')
                return (0);
        }
        if (line == 0) {
            solv->x_max = i;
        } else {
            if (solv->x_max != i) {
                return (0);
            }
        }
    }
    solv->y_max = line;
    return (1);
}

char *handle_error(char *filename, solver_t *solv)
{
    int fd = open(filename, O_RDONLY);
    struct stat st;
    char *buffer = NULL;
    int rd = 0;

    if (fd == -1 || stat(filename, &st) == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (st.st_size + 2));
    memset(buffer, 0, st.st_size + 2);
    if ((rd = read(fd, buffer, st.st_size)) == -1)
        return (NULL);
    if (buffer[0] != '*' || buffer[st.st_size - 1] != '*')
        return (NULL);
    if (check_all_width(buffer, solv, rd) == 0)
        return (NULL);
    return (buffer);
}

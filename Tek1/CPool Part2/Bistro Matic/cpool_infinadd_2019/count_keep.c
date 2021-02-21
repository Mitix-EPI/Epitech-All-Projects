/*
** EPITECH PROJECT, 2019
** count keep
** File description:
** How much keep the add or sub
*/

char count_keep_pos(char *c, int i)
{
    char keep = 0;

    if (c[i] >= 10) {
        keep = 1;
        c[i] -= 10;
    }
    return (keep);
}

char count_keep_neg(char *c, int i)
{
    char keep = 0;

    if (c[i] < 0) {
        keep = 1;
        c[i] += 10;
    }
    return (keep);
}
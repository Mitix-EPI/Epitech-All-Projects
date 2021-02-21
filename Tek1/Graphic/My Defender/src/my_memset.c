/*
** EPITECH PROJECT, 2019
** my_memset
** File description:
** Memset
*/

void *my_memset(char *s, int c, int n)
{
    for (int i = 0; i != n; i++)
        s[i] = c;
}
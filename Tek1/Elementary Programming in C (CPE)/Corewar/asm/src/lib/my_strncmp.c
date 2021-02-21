/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    char a;
    char b;
    int i = 0;

    while (i < n) {
        a = s1[i];
        b = s2[i];
        if (a < b || a > b)
            return (a-b);
        i++;
    }
    return (0);
}

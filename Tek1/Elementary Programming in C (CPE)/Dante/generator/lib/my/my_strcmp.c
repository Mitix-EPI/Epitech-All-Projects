/*
** EPITECH PROJECT, 2019
** str compare
** File description:
** s1-s2
*/

int my_strcmp(char const *s1, char const *s2)
{
    int result;
    int i = 0;
    while (s1[i] == s2[i] && s1[i])
        i = i + 1;
    result = s1[i] - s2[i];
    return (result);
}

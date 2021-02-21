/*
** EPITECH PROJECT, 2019
** nmatch.c
** File description:
** return value
*/

int nmatch(char *s1, char *s2)
{
    if (*s1 == *s2 && *s1 == '\0')
        return (1);
    if (*s2 == '*' && *s1 != '\0')
        return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
    if (*s2 == '*')
        return (nmatch(s1, s2 + 1));
    if (*s1 == *s2 && *s1 != '\0')
        return (nmatch(s1 + 1, s2 + 1));
    return (0);
}

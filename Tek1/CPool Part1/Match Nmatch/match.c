/*
** EPITECH PROJECT, 2019
** match.c
** File description:
** return value
*/

int match(char *s1, char *s2)
{
    if (*s1 == *s2 && *s1 == '\0')
        return (1);
    if (*s2 == '*' && *s1 != '\0')
        return (match(s1 + 1, s2) || match(s1, s2 + 1));
    if (*s2 == '*')
        return (match(s1, s2 + 1));
    if (*s1 == *s2 && *s1 != '\0')
        return (match(s1 + 1, s2 + 1));
    return (0);
}

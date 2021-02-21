/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** jsp
*/

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0' ; i++) {
        for (int j = 0; str[i] ==  to_find[j]; j++) {
            if (to_find[j + 1] == '\0') {
                return (&str[i - j + 1]);
            }
            i = i + 1;
        }
    }
    return ("\0");
}

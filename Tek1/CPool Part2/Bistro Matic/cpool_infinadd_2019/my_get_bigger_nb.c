/*
** EPITECH PROJECT, 2019
** get bigger nb
** File description:
** Return the biggest number between two str
*/

int my_strlen(char const *str);

int get_bigger_nb_equals(char *str1, char *str2)
{
    int i = 0;
    int j = 0;

    if (str1[0] == '-')
        i += 1;
    else
        j += 1;
    while (str1[i] != '\0') {
        if (str1[i] > str2[j])
            return (0);
        else if (str2[j] > str1[i])
            return (1);
        else
            i += 1;
            j += 1;
    }
    return (2);
}

int get_bigger_nb(char *str1, char *str2)
{
    int a = my_strlen(str1);
    int b = my_strlen(str2);

    if (str1[0] == '-')
        a -= 1;
    else
        b -= 1;
    if (a > b)
        return (0);
    else if (b > a)
        return (1);
    else
        return (get_bigger_nb_equals(str1, str2));
}
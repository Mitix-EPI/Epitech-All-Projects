/*
** EPITECH PROJECT, 2019
** my_evil_str
** File description:
** Swap each of the string's characters
*/

int my_strlen(char *);

void    invert_elements(char *array, int a, int b)
{
    char temp = array[a];

    array[a] = array[b];
    array[b] = temp;
}

char   *my_edit_str(char *str, int size)
{
    int i = 0;
    int x = size;

    while (i < x) {
        invert_elements(str, i, x);
        i++;
        x--;
    }
    return (str);
}

char   *my_evil_str(char *str)
{
    int sizeofstring;

    sizeofstring = my_strlen(str) - 1;
    if (sizeofstring > 1) {
        str = my_edit_str(str, sizeofstring);
    }
    return (str);
}

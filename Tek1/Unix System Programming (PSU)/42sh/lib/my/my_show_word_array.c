/*
** EPITECH PROJECT, 2019
** my_show_word_array
** File description:
** Show word array as string
*/

int my_putstr(char const *);

int my_putchar(char);

int    my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}

/*
** EPITECH PROJECT, 2019
** my_sort_int_array
** File description:
** Sort an integer array in ascending order
*/

void invert_elements(int *, int, int);

int    array_is_sort(int *array, int size)
{
    int i = 0;

    while (i < size) {
        if (array[i] > array[i+1]) {
            return (0);
        }
        i++;
    }
    return (1);
}

void    my_sort_int_array(int *array, int size)
{
    int i = 0;

    while (i < size) {
        if (array[i] > array[i+1]) {
            invert_elements(array, i, i+1);
        }
        i++;
    }
    if (array_is_sort(array, size) == 0)
        my_sort_int_array(array, size);
}

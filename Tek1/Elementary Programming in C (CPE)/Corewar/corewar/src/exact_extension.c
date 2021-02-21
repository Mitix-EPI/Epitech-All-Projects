/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** exact_extension
*/

int exact_extension(char *path, char *ext)
{
    int index_path = 0;
    int index_ext = 0;

    for (; path[index_path]; index_path += 1);
    for (; ext[index_ext]; index_ext += 1);
    for (; index_path >= 0 && index_ext >= 0;) {
        if (path[index_path--] != ext[index_ext--])
            return (0);
    }
    return (1);
}

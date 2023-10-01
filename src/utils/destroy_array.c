/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_array
*/

#include <stdlib.h>

int destroy_array(void **array)
{
    if (array == NULL)
        return 84;
    for (int i = 0; array[i] != NULL; ++i) {
        free(array[i]);
    }
    free(array);
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** free_matrix
*/

#include <stdlib.h>
#include "editor.h"

int free_matrix(float **matrix)
{
    if (matrix == NULL) {
        my_put_error("free_matrix : NULL pointer passed");
    }
    for (int i = 0; i < 4; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

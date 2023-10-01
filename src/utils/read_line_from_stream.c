/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** read_line_from_stream
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *read_line_from_stream(FILE *file)
{
    char *ptr = NULL;
    size_t size = 0;
    int i = 0;

    if (getline(&ptr, &size, file) == -1) {
        free(ptr);
        return NULL;
    }
    if (ptr[my_strlen(ptr) - 1] == '\n')
        ptr[my_strlen(ptr) - 1] = '\0';
    return ptr;
}

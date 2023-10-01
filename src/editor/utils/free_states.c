/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** free_states
*/

#include "editor.h"
#include <stdlib.h>

int free_states(sfRenderStates *states)
{
    if (states == NULL)
        return 84;
    sfShader_destroy((sfShader *)states->shader);
    free(states);
    return 0;
}

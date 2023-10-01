/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_list
*/

#include "my_linked_list.h"
#include <stdlib.h>

int destroy_list(linked_list_t *list)
{
    linked_list_t *buf = NULL;

    while (list != NULL) {
        buf = list;
        list = list->next;
        if (buf == NULL)
            continue;
        if (buf->data != NULL)
            free(buf->data);
        free(buf);
    }
    return 0;
}

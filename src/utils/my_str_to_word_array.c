/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include "my.h"

static int is_sep(char c, char *separators)
{
    for (int i = 0; separators[i] != '\0'; i++) {
        if (separators[i] == c)
            return 1;
    }
    return 0;
}

char **my_str_to_word_array(char *str, char *sep)
{
    int i = 0;
    int size = 0;
    int nb_elements = 1;
    char **dest = NULL;

    for (int j = i; str[j] != '\0'; ++j)
        if (is_sep(str[j], sep))
            nb_elements++;
    dest = my_memset(sizeof(char *) * (nb_elements + 1), NULL);
    for (int k = 0; k < nb_elements; ++k) {
        size = 0;
        while (!is_sep(str[i + ++size], sep) && str[i + size] != '\0');
        dest[k] = my_strndup(&str[i], size);
        i = i + size + 1;
    }
    return dest;
}

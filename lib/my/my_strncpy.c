/*
** EPITECH PROJECT, 2021
** cpoolday06 task01
** File description:
** function that copies a string
*/

#include <stddef.h>

int my_strlen(char *str);

void *my_memset(int size, char *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
        dest[i] = '\0';
    return (dest);
}

char *my_strndup(char *src, int n)
{
    char *dest = my_memset(sizeof(char) * (my_strlen(src) + 1), NULL);
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
        dest[i] = '\0';
    return (dest);
}

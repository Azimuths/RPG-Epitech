/*
** EPITECH PROJECT, 2021
** cpoolday06 task01
** File description:
** function that copies a string
*/

#include <stdbool.h>

int my_strlen(char const *str);

bool my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return false;
    if (my_strlen(s1) != my_strlen(s2))
        return false;
    while (s1[i] != '\0' && s2[2] != '\0') {
        if (s1[i] != s2[i])
            return false;
        (i++);
    }
    return true;
}

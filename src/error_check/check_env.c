/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** env check
*/

#include "my.h"

int check_env(char **env)
{
    int i = 0;

    while (env[i]) {
        if (my_strncmp("DISPLAY=", env[i], 8) == 0)
            return (0);
        i++;
    }
    return (84);
}

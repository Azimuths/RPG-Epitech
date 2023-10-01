/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** config_func
*/

#include "config.h"
#include "my.h"

int conf_update_skin(char **args, config_t *dest)
{
    char *skin[] = {"HERO1", "HERO2", "VILLAGER3", "VILLAGER7", "VILLAGER8",
            "VILLAGER9", NULL};

    if (args == NULL || *args == NULL)
        return my_put_error("SKIN : no args found\n");
    if (args[1] != NULL)
        return my_put_error("SKIN : Too many args\n");
    for (int i = 0; skin[i] != NULL; ++i) {
        if (my_strcmp(skin[i], args[0]) == 0) {
            dest->skin = i;
            return 0;
        }
    }
    return my_put_error("SKIN : skin not found\n");
}

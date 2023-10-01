/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** conf_update_part
*/

#include "config.h"
#include "my.h"

int conf_update_snowtext(char **args, config_t *dest)
{
    if (args == NULL || *args == NULL)
        return my_put_error("SNOW_PART : no args found\n");
    if (args[1] != NULL)
        return my_put_error("SNOW_PART : Too many args\n");
    dest->snow_text_file = args[0];
    return 0;
}

int conf_update_raintext(char **args, config_t *dest)
{
    if (args == NULL || *args == NULL)
        return my_put_error("STAR_PART : no args found\n");
    if (args[1] != NULL)
        return my_put_error("STAR_PART : Too many args\n");
    dest->rain_text_file = args[0];
    return 0;
}

int conf_update_clicktext(char **args, config_t *dest)
{
    if (args == NULL || *args == NULL)
        return my_put_error("CLICK_PART : no args found\n");
    if (args[1] != NULL)
        return my_put_error("CLICK_PART : Too many args\n");
    dest->click_text_file = args[0];
    return 0;
}

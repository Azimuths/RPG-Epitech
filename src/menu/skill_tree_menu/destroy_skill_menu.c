/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_skill_menu
*/

#include "rpg.h"
#include "macro.h"
#include <stdlib.h>

void destroy_skill_menu(every_object_t *obj)
{
    delete_object(obj->background);
    delete_object(obj->ux_bg);
    delete_object(obj->button_left_two);
    delete_object(obj->ux_bg_little);
    delete_object(obj->ux_win_four);
    delete_object(obj->ux_win_three);
    delete_object(obj->ux_win_two);
    delete_object(obj->ux_win_one);
    delete_object(obj->button_dmg_one);
    delete_object(obj->button_dmg_two);
    delete_object(obj->button_dmg_three);
    delete_object(obj->button_health_one);
    delete_object(obj->button_health_two);
    delete_object(obj->button_health_three);
    delete_object(obj->button_speed_one);
    delete_object(obj->button_speed_two);
    delete_object(obj->button_speed_three);
    free(obj);
}

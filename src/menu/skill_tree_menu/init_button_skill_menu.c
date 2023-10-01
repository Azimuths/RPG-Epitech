/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** init_button_skill_menu
*/

#include "rpg.h"
#include "macro.h"

int init_skill_button_damage(every_object_t *obj)
{
    if (!(obj->button_dmg_one = create_object(NO_DMG_ONE, ((sfIntRect)
        {0, 0, 500, 350}), ((sfVector2f){950, 650}), ((sfVector2f){0.4, 0.4}))))
        return 848;
    if (!(obj->button_dmg_two = create_object(NO_DMG_TWO,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){950, 450}),
    ((sfVector2f){0.4, 0.4}))))
        return 84;
    if (!(obj->button_dmg_three = create_object(NO_DMG_THREE,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){950, 250}),
    ((sfVector2f){0.4, 0.4}))))
        return 84;
    sprite_set_center(obj->button_dmg_one->sprite);
    sprite_set_center(obj->button_dmg_two->sprite);
    sprite_set_center(obj->button_dmg_three->sprite);
    return 0;
}

int init_skill_button_health(every_object_t *obj)
{
    if (!(obj->button_health_one = create_object(NO_HEALTH_ONE, ((sfIntRect)
    {0, 0, 500, 350}), ((sfVector2f){700, 650}), ((sfVector2f){0.4, 0.4}))))
        return 84;
    if (!(obj->button_health_two = create_object(NO_HEALTH_TWO,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){700, 450}),
    ((sfVector2f){0.4, 0.4}))))
        return 84;
    if (!(obj->button_health_three = create_object(NO_HEALTH_THREE,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){700, 250}),
    ((sfVector2f){0.4, 0.4}))))
        return 84;
    sprite_set_center(obj->button_health_one->sprite);
    sprite_set_center(obj->button_health_two->sprite);
    sprite_set_center(obj->button_health_three->sprite);
    return 0;
}

int init_skill_button_speed(every_object_t *obj)
{
    if (!(obj->button_speed_one = create_object(NO_SPEED_ONE, ((sfIntRect)
    {0, 0, 500, 350}), ((sfVector2f){1200, 650}), ((sfVector2f){0.4, 0.4}))))
        return 84;
    if (!(obj->button_speed_two = create_object(NO_SPEED_TWO,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){1200, 450}),
    ((sfVector2f){0.4, 0.4}))))
        return 84;
    if (!(obj->button_speed_three = create_object(NO_SPEED_THREE,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){1200, 250}),
    ((sfVector2f){0.4, 0.4}))))
        return 84;
    sprite_set_center(obj->button_speed_one->sprite);
    sprite_set_center(obj->button_speed_two->sprite);
    sprite_set_center(obj->button_speed_three->sprite);
    return 0;
}

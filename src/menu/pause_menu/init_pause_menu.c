/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** init_pause_menu
*/

#include "rpg.h"
#include "macro.h"
#include <stdlib.h>

int init_pause_menu_second(every_object_t *obj)
{
    if (!(obj->background = create_object(MAP,
    ((sfIntRect){0, 0, 2400, 1850}), ((sfVector2f){984, 500}),
    ((sfVector2f){1, 1}))))
        return 84;
    if (!(obj->button_resume = create_object(BUTTON_RESUME,
    ((sfIntRect){0, 0, 236, 100}), ((sfVector2f){960, 540}),
    ((sfVector2f){1, 1}))))
        return 84;
    sprite_set_center(obj->background->sprite);
    sprite_set_center(obj->button_resume->sprite);
    return 0;
}

every_object_t *init_pause_menu(void)
{
    every_object_t *obj = (every_object_t *)malloc(sizeof(every_object_t));

    if (!(obj->button_option = create_object(BUTTON_OPTION,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){1700, 100}),
    ((sfVector2f){0.4, 0.4}))))
        return NULL;
    if (!(obj->button_door = create_object(EXIT_DOOR,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){1825, 100}),
    ((sfVector2f){0.4, 0.4}))))
        return NULL;
    if (!(obj->button_menu = create_object(BUTTON_MENU, ((sfIntRect)
        {0, 0, 500, 350}), ((sfVector2f){100, 100}), ((sfVector2f){0.4, 0.4}))))
        return NULL;
    if (init_pause_menu_second(obj) == 84)
        return NULL;
    init_button_pause_menu(obj);
    sprite_set_center(obj->button_menu->sprite);
    sprite_set_center(obj->button_option->sprite);
    sprite_set_center(obj->button_door->sprite);
    return obj;
}

void draw_pause_menu(game_t *game)
{
    draw_object(game->pause->background, game);
    draw_object(game->pause->button_menu, game);
    draw_object(game->pause->button_option, game);
    draw_object(game->pause->button_resume, game);
    draw_object(game->pause->button_door, game);
}

void destroy_pause_menu(every_object_t *obj)
{
    delete_object(obj->background);
    delete_object(obj->button_option);
    delete_object(obj->button_menu);
    delete_object(obj->button_resume);
    delete_object(obj->button_door);
    free(obj);
}

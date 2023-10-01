/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** init_main_menu
*/

#include "rpg.h"
#include "macro.h"
#include <stdlib.h>

int init_pause_settings_menu(every_object_t *obj)
{
    if (!(obj->button_menu = create_object(BUTTON_LEFT, ((sfIntRect)
        {0, 0, 500, 350}), ((sfVector2f){100, 100}), ((sfVector2f){0.4, 0.4}))))
        return 84;
    if (!(obj->button_plus = create_object(PLUS,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){750, 360}),
    ((sfVector2f){0.25, 0.25}))))
        return 84;
    if (!(obj->ux_bg = create_object(UX_BG,
    ((sfIntRect){0, 0, 965, 623}), ((sfVector2f){950, 570}),
    ((sfVector2f){1.2, 1.2}))))
        return 84;
    if (!(obj->button_less = create_object(LESS,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){500, 360}),
    ((sfVector2f){0.25, 0.25}))))
        return 84;
    sprite_set_center(obj->button_menu->sprite);
    sprite_set_center(obj->button_plus->sprite);
    sprite_set_center(obj->button_less->sprite);
    sprite_set_center(obj->ux_bg->sprite);
    return 0;
}

int init_pause_settings_menu_third(every_object_t *obj)
{
    if (!(obj->button_left = create_object(BUTTON_LEFT,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){700, 750}),
    ((sfVector2f){0.25, 0.25}))))
        return 84;
    if (!(obj->button_right = create_object(BUTTON_RIGHT,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){1180, 750}),
    ((sfVector2f){0.25, 0.25}))))
        return 84;
    if (!(obj->background = create_object(MAP,
    ((sfIntRect){0, 0, 2400, 1850}), ((sfVector2f){984, 500}),
    ((sfVector2f){1, 1}))))
        return 84;
    sprite_set_center(obj->background->sprite);
    sprite_set_center(obj->button_left->sprite);
    sprite_set_center(obj->button_right->sprite);
    return 0;
}

every_object_t *init_pause_settings_menu_second(void)
{
    every_object_t *obj = malloc(sizeof(every_object_t));

    if (!(obj->button_plus_two = create_object(PLUS,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){1380, 360}),
    ((sfVector2f){0.25, 0.25}))))
        return NULL;
    if (!(obj->button_less_two = create_object(LESS,
    ((sfIntRect){0, 0, 500, 350}), ((sfVector2f){1100, 360}),
    ((sfVector2f){0.25, 0.25}))))
        return NULL;
    if (init_pause_settings_menu_third(obj) == 84)
        return NULL;
    if (init_pause_settings_menu(obj) == 84)
        return NULL;
    init_button_pause_settings_menu(obj);
    sprite_set_center(obj->button_plus_two->sprite);
    sprite_set_center(obj->button_less_two->sprite);
    return obj;
}

void draw_pause_settings_menu(game_t *game)
{
    draw_object(game->pause_settings->background, game);
    draw_object(game->pause_settings->ux_bg, game);
    draw_object(game->pause_settings->button_menu, game);
    draw_object(game->pause_settings->button_plus, game);
    draw_object(game->pause_settings->button_plus_two, game);
    draw_object(game->pause_settings->button_less, game);
    draw_object(game->pause_settings->button_less_two, game);
    draw_object(game->pause_settings->button_left, game);
    draw_object(game->pause_settings->button_right, game);
}

void destroy_pause_settings_menu(every_object_t *obj)
{
    delete_object(obj->background);
    delete_object(obj->button_less);
    delete_object(obj->button_less_two);
    delete_object(obj->button_menu);
    delete_object(obj->button_plus);
    delete_object(obj->button_plus_two);
    delete_object(obj->button_right);
    delete_object(obj->button_left);
    delete_object(obj->ux_bg);
    free(obj);
}

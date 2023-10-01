/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** init_main_menu
*/

#include "rpg.h"
#include "macro.h"
#include <stdlib.h>

int init_stats_menu(every_object_t *obj)
{
    if (!(obj->ux_bg = create_object(UX_BG,
    ((sfIntRect){0, 0, 965, 623}), ((sfVector2f){950, 570}),
    ((sfVector2f){1.2, 1.2}))))
        return 84;
    if (!(obj->background = create_object(MAP,
    ((sfIntRect){0, 0, 2400, 1850}), ((sfVector2f){984, 500}),
    ((sfVector2f){1, 1}))))
        return 84;
    if (!(obj->button_left_two = create_object(BUTTON_LEFT, ((sfIntRect)
    {0, 0, 500, 350}), ((sfVector2f){100, 100}), ((sfVector2f){0.4, 0.4}))))
        return 84;
    sprite_set_center(obj->ux_bg->sprite);
    sprite_set_center(obj->background->sprite);
    sprite_set_center(obj->button_left_two->sprite);
    return 0;
}

every_object_t *init_stats_menu_second(void)
{
    every_object_t *obj = (every_object_t *)malloc(sizeof(every_object_t));

    if (!(obj->button_dmg_one = create_object(DMG_ONE, ((sfIntRect)
    {0, 0, 500, 350}), ((sfVector2f){600, 350}), ((sfVector2f){0.4, 0.4}))))
        return NULL;
    if (!(obj->button_health_one = create_object(HEALTH_ONE, ((sfIntRect)
    {0, 0, 500, 350}), ((sfVector2f){600, 550}), ((sfVector2f){0.4, 0.4}))))
        return NULL;
    if (!(obj->button_speed_one = create_object(SPEED_ONE, ((sfIntRect)
    {0, 0, 500, 350}), ((sfVector2f){600, 750}), ((sfVector2f){0.4, 0.4}))))
        return NULL;
    sprite_set_center(obj->button_dmg_one->sprite);
    sprite_set_center(obj->button_health_one->sprite);
    sprite_set_center(obj->button_speed_one->sprite);
    if (init_stats_menu(obj) == 84)
        return NULL;
    init_button_stats_menu(obj);
    return obj;
}

void draw_stats_menu(game_t *game)
{
    draw_object(game->stats->background, game);
    draw_object(game->stats->ux_bg, game);
    draw_object(game->stats->button_left_two, game);
    draw_object(game->stats->button_dmg_one, game);
    draw_object(game->stats->button_health_one, game);
    draw_object(game->stats->button_speed_one, game);
}

void destroy_stats_menu(every_object_t *obj)
{
    delete_object(obj->ux_bg);
    delete_object(obj->background);
    delete_object(obj->button_left_two);
    delete_object(obj->button_dmg_one);
    delete_object(obj->button_health_one);
    delete_object(obj->button_speed_one);
    free(obj);
}

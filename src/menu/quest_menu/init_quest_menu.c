/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** init_main_menu
*/

#include "rpg.h"
#include "macro.h"
#include <stdlib.h>

int init_quest_menu(every_object_t *obj)
{
    if (!(obj->ux_win_four = create_object(UX_LARGE_WIN, ((sfIntRect)
        {0, 0, 438, 130}), ((sfVector2f){950, 810}), ((sfVector2f){1.8, 1}))))
        return 84;
    if (!(obj->ux_bg = create_object(UX_BG,
    ((sfIntRect){0, 0, 965, 623}), ((sfVector2f){950, 570}),
    ((sfVector2f){1.2, 1.2}))))
        return 84;
    if (!(obj->button_left_two = create_object(BUTTON_LEFT, ((sfIntRect)
    {0, 0, 500, 350}), ((sfVector2f){100, 100}), ((sfVector2f){0.4, 0.4}))))
        return 84;
    if (!(obj->background = create_object(MAP,
    ((sfIntRect){0, 0, 2400, 1850}), ((sfVector2f){984, 500}),
    ((sfVector2f){1, 1}))))
        return 84;
    sprite_set_center(obj->background->sprite);
    sprite_set_center(obj->ux_bg->sprite);
    sprite_set_center(obj->button_left_two->sprite);
    sprite_set_center(obj->ux_win_four->sprite);
    return 0;
}

every_object_t *init_quest_menu_second(void)
{
    every_object_t *obj = (every_object_t *)malloc(sizeof(every_object_t));

    if (!(obj->ux_win_one = create_object(UX_LARGE_WIN,
    ((sfIntRect){0, 0, 438, 130}), ((sfVector2f){950, 320}),
    ((sfVector2f){1.8, 1}))))
        return NULL;
    if (!(obj->ux_win_two = create_object(UX_LARGE_WIN,
    ((sfIntRect){0, 0, 438, 130}), ((sfVector2f){950, 490}),
    ((sfVector2f){1.8, 1}))))
        return NULL;
    if (!(obj->ux_win_three = create_object(UX_LARGE_WIN,
    ((sfIntRect){0, 0, 438, 130}), ((sfVector2f){950, 640}),
    ((sfVector2f){1.8, 1}))))
        return NULL;
    if (init_quest_menu(obj) == 84)
        return NULL;
    sprite_set_center(obj->ux_win_one->sprite);
    sprite_set_center(obj->ux_win_two->sprite);
    sprite_set_center(obj->ux_win_three->sprite);
    return obj;
}

void draw_quest_menu(game_t *game)
{
    draw_object(game->quest->background, game);
    draw_object(game->quest->ux_bg, game);
    draw_object(game->quest->button_left_two, game);
    draw_object(game->quest->ux_win_one, game);
    draw_object(game->quest->ux_win_two, game);
    draw_object(game->quest->ux_win_three, game);
    draw_object(game->quest->ux_win_four, game);
}

void destroy_quest_menu(every_object_t *obj)
{
    delete_object(obj->background);
    delete_object(obj->ux_bg);
    delete_object(obj->button_left_two);
    delete_object(obj->ux_win_four);
    delete_object(obj->ux_win_three);
    delete_object(obj->ux_win_two);
    delete_object(obj->ux_win_one);
    free(obj);
}

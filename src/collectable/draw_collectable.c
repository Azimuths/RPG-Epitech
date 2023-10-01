/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_collectable
*/

#include "collectable.h"

int draw_collectable(game_t *game, collectable_t *collectable)
{
    if (collectable->sprite != NULL) {
        sfSprite_setScale(collectable->sprite, collectable->scale);
        sprite_set_center(collectable->sprite);
        sfSprite_setPosition(collectable->sprite, collectable->pos);
        sfRenderWindow_drawSprite(game->window, collectable->sprite, NULL);
    }
    return 0;
}

int draw_collectables(game_t *game)
{
    collectable_t *buf = 0;
    linked_list_t *list = game->collectables;

    while (list != NULL) {
        buf = ((collectable_t *)(list->data));
        list = list->next;
        draw_collectable(game, buf);
    }
    return 0;
}

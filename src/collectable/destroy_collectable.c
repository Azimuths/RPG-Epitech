/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** destroy_collectable
*/

#include "collectable.h"

void destroy_collectable(collectable_t *coll)
{
    sfSprite_destroy(coll->sprite);
}

void destroy_collectables(game_t *game)
{
    while (game->collectables != NULL) {
        destroy_collectable(game->collectables->data);
        del_first_node(&(game->collectables));
    }
}

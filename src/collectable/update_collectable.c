/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_collectable
*/

#include "rpg.h"
#include "collectable.h"

int update_collectable(game_t *game)
{
    collectable_t *buf = 0;
    linked_list_t *list = NULL;

    list = (game->collectables);
    while (list != NULL) {
        buf = ((collectable_t *)(list->data));
        list = list->next;
        buf->pos.y += buf->spd.y;
        buf->pos.x += buf->spd.x;
        if (buf->update != NULL)
            buf->update(game, buf);
    }
    return 0;
}

int check_collision_collectable(game_t *game)
{
    linked_list_t *prev = NULL;
    linked_list_t *list = NULL;

    while (game->collectables != NULL &&
            check_collectable(game, game->collectables->data) == 1)
        del_first_node(&(game->collectables));
    list = game->collectables;
    while (list != NULL) {
        if (check_collectable(game, list->data) == 1) {
            destroy_collectable(list->data);
            delete_node(&prev);
            list = prev;
        }
        prev = list;
        list = list->next;
    }
    return 0;
}

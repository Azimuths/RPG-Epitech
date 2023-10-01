/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_projectile
*/

#include "rpg.h"
#include "projectile.h"
#include "my_linked_list.h"

int update_projectiles(game_t *game, linked_list_t **list_proj)
{
    projectile_t *buf = 0;
    linked_list_t *list = NULL;

    list = *list_proj;
    while (list != NULL) {
        buf = ((projectile_t *)(list->data));
        list = list->next;
        buf->lifetime--;
        buf->pos.y += buf->spd.y;
        buf->pos.x += buf->spd.x;
        if (buf->update != NULL)
            buf->update(game, buf);
    }
    clear_projectiles(game, list_proj);
    return 0;
}

int clear_projectiles(game_t *game, linked_list_t **list_proj)
{
    linked_list_t *prev = NULL;
    linked_list_t *list = NULL;

    while (*list_proj != NULL &&
            ((projectile_t *)((*list_proj)->data))->lifetime <= 0) {
        destroy_projectile(((projectile_t *)((*list_proj)->data)));
        del_first_node(&(*list_proj));
    }
    list = *list_proj;
    while (list != NULL) {
        if (((projectile_t *) (list->data))->lifetime <= 0) {
            destroy_projectile(list->data);
            delete_node(&prev);
            list = prev;
        }
        prev = list;
        list = list->next;
    }
    return 0;
}

int destroy_projectiles(game_t *game, linked_list_t **list_proj)
{
    while (*list_proj != NULL) {
        destroy_projectile(((projectile_t *)((*list_proj)->data)));
        del_first_node(&(*list_proj));
    }
    return 0;
}

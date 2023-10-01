/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_particles
*/

#include "rpg.h"
#include "particle.h"
#include "stdlib.h"
#include "my_linked_list.h"

int update_particles(game_t *game)
{
    particle_t *buf = 0;
    linked_list_t *list = NULL;
    list = game->particles;
    while (list != NULL) {
        buf = ((particle_t *)(list->data));
        list = list->next;
        buf->lifetime--;
        buf->pos.y += buf->spd.y;
        buf->pos.x += buf->spd.x;
        if (buf->update != NULL)
            buf->update(game, buf);
    }
    clear_particles(game);
    return 0;
}

int clear_particles(game_t *game)
{
    linked_list_t *prev = NULL;
    linked_list_t *list = NULL;

    while (game->particles != NULL &&
    ((particle_t *)(game->particles->data))->lifetime <= 0)
        del_first_node(&(game->particles));
    list = game->particles;
    while (list != NULL) {
        if (((particle_t *) (list->data))->lifetime <= 0) {
            delete_node(&prev);
            list = prev;
        }
        prev = list;
        list = list->next;
    }
    return 0;
}

int destroy_particles(game_t *game)
{
    while (game->particles != NULL)
        del_first_node(&(game->particles));
}

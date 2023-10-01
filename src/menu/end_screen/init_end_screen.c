/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** init_end_screen
*/

#include "rpg.h"
#include "macro.h"
#include <stdlib.h>

every_object_t *init_end_screen(void)
{
    every_object_t *obj = (every_object_t *)malloc(sizeof(every_object_t));

    if (!(obj->good_job = create_object(GG, ((sfIntRect){0, 0, 549, 148}),
    ((sfVector2f){1000, 500}), ((sfVector2f){1.3, 1.3}))))
        return NULL;
    sprite_set_center(obj->good_job->sprite);
    return obj;
}

void draw_end_menu(game_t *game)
{
    draw_object(game->end_screen->good_job, game);
}

void destroy_end_menu(every_object_t *obj)
{
    delete_object(obj->good_job);
    free(obj);
}

/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_end_screen_star_particle
*/

#include "particle.h"
#include "my.h"
#include <stdlib.h>

particle_t *create_end_screen_star_particle(game_t *game, sfVector2f pos,
        sfColor color)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->color = sfWhite;
    dest->lifetime = 40;
    dest->type = STAR_PART;
    dest->spd = ((sfVector2f){.x = ((float)(rand() % 400) / 100) - 2,
            .y = ((float)(rand() % 400) / 100) - 2});
    dest->update = update_star_particle_on_duck;
    dest->rot = 0;
    dest->pos = pos;
    dest->color = color;
    dest->scale = ((sfVector2f){.x = 4, .y = 4});
    return dest;
}

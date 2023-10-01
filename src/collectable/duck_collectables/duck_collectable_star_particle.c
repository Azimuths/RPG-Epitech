/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** duck_collectable_star_particle
*/

#include "particle.h"
#include "my.h"
#include "stdlib.h"

int update_star_particle_on_duck(game_t *game, particle_t *particle)
{
    particle->spd.y = (float)(particle->spd.y / 1.05);
    particle->spd.x = (float)(particle->spd.x / 1.05);
    if (particle->color.a > 10) {
        particle->color.a -= 5;
    }
    return 0;
}

particle_t *create_star_particle_on_duck(game_t *game, sfVector2f pos,
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
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    return dest;
}

/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rain_particle
*/

#include <math.h>
#include "particle.h"
#include "my.h"
#include <stdlib.h>

int update_snowparticle(game_t *game __attribute__((unused)),
        particle_t *particle)
{
    particle->spd.x = (float)(cos(particle->lifetime / 10.0)) * 2;
    return 0;
}

particle_t *create_snow_particle(void)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->pos.x = (rand() % (1920 + 500)) - 500;
    dest->pos.y = (rand() % (1080 + 500)) - 500;
    dest->color = NO_COLOR;
    dest->lifetime = 250;
    dest->type = SNOW_PART;
    dest->spd = ((sfVector2f){.x = 0,
            .y = 2});
    dest->update = update_snowparticle;
    dest->rot = 0;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    return dest;
}

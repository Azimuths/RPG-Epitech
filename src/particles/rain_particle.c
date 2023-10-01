/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rain_particle
*/

#include "particle.h"
#include "my.h"
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>

int update_rainparticle(game_t *game __attribute__((unused)),
        particle_t *particle)
{
    if (particle->spd.y < 15)
        particle->spd.y++;
    return 0;
}

particle_t *create_rain_particle(void)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->pos.x = (rand() % (1920 + 500)) - 500;
    dest->pos.y = (rand() % (1080 + 500)) - 500;
    dest->color = sfWhite;
    dest->lifetime = 20;
    dest->type = RAIN_PART;
    dest->spd = ((sfVector2f){.x = (rand() % 5) + 3,
            .y = 10 + (rand() % 10)});
    dest->update = update_rainparticle;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    return dest;
}

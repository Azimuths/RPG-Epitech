/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** click_particle
*/

#include "stdlib.h"
#include "my.h"
#include "particle.h"
#include "macro.h"
#include "player.h"

particle_t *create_star_particle_on_player(game_t *game)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->pos = game->player->pos;
    dest->color = sfWhite;
    dest->lifetime = 40;
    dest->type = STAR_PART;
    dest->spd = ((sfVector2f){.x = ((float)(rand() % 400) / 100) - 2,
            .y = ((float)(rand() % 400) / 100) - 2});
    dest->update = NULL;
    dest->rot = 0;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    return dest;
}

particle_t *create_star_particle(game_t *game)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->pos.x = MOUSE_X;
    dest->pos.y = MOUSE_Y;
    dest->color = sfWhite;
    dest->lifetime = 40;
    dest->type = STAR_PART;
    dest->spd = ((sfVector2f){.x = ((float)(rand() % 400) / 100) - 2,
            .y = ((float)(rand() % 400) / 100) - 2});
    dest->update = update_starparticle;
    dest->rot = 0;
    dest->scale = ((sfVector2f){.x = 2, .y = 2});
    return dest;
}

int update_starparticle(game_t *game, particle_t *particle)
{
    particle->spd.y = (float)(particle->spd.y / 1.05);
    particle->spd.x = (float)(particle->spd.x / 1.05);
    if (particle->color.a > 10)
        particle->color.a -= 10;
    return 0;
}

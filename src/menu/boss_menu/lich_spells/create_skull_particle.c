/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_skull_particle
*/

#include "particle.h"
#include "my.h"
#include "enemy.h"
#include "macro.h"

particle_t *create_skull_particle_water_spell(game_t *game)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->pos.x = game->player->pos.x;
    dest->pos.y = game->player->pos.y - 20;
    dest->color = sfWhite;
    dest->lifetime = 40;
    dest->type = XP_PART;
    dest->spd = ((sfVector2f){.x = 0, .y = -3});
    dest->update = update_skullparticle;
    dest->rot = 0;
    dest->scale = ((sfVector2f){.x = 1.5, .y = 1.5});
    return dest;
}

int update_skullparticle(game_t *game, particle_t *particle)
{
    if (particle->color.a > 10)
        particle->color.a -= 10;
    return 0;
}

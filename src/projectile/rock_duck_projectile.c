/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rock_duck_projectile
*/

#include "projectile.h"
#include "particle.h"
#include "player.h"
#include "my.h"
#include <stdlib.h>

int update_rockparticle(game_t *game, particle_t *particle)
{
    particle->rot += 20;
    particle->color.a -= 30;
    return 0;
}

particle_t *create_rock_particle(game_t *game, projectile_t *proj)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->pos.x = proj->pos.x + (rand() % 40 - 20) * proj->scale.x;
    dest->pos.y = proj->pos.y + (rand() % 40 - 20) * proj->scale.x;
    dest->color = ROCK_COLOR;
    dest->lifetime = 10;
    dest->type = SNOW_PART;
    dest->spd = proj->spd;
    dest->update = update_rockparticle;
    if (proj->dir == DOWN)
        dest->rot = 195;
    else if (proj->dir == LEFT)
        dest->rot = 105;
    if (proj->dir == RIGHT)
        dest->rot = 285;
    else if (proj->dir == UP)
        dest->rot = 15;
    dest->scale = proj->scale;
    return dest;
}

int update_rock_duck_projectile(game_t *game __attribute__((unused)),
        projectile_t *proj)
{
    proj->rot += 30 - (proj->lifetime / 5);
    proj->spd.x *= (float)1.01;
    proj->spd.y *= (float)1.01;
    proj->scale.x *= 1.01;
    proj->scale.y *= 1.01;
    proj->hitbox_size.width *= 1.01;
    proj->hitbox_size.height *= 1.01;
    add_node(create_rock_particle(game, proj),
            &(game->particles));
    proj->dmg = proj->spd.x + proj->spd.y;
    return 0;
}

static sfVector2f update_spd_ice_duck(dir_t dir)
{
    if (dir == DOWN)
        return ((sfVector2f){.x = 0, .y = 3});
    else if (dir == LEFT)
        return ((sfVector2f){.x = -3, .y = 0});
    if (dir == RIGHT)
        return ((sfVector2f){.x = 3, .y = 0});
    else if (dir == UP)
        return ((sfVector2f){.x = 0, .y = -3});
}

projectile_t *create_rock_duck_projectile(player_t *player)
{
    projectile_t *dest = my_memset(sizeof(projectile_t), NULL);

    dest->sprite = sfSprite_create();
    dest->pos = player->pos;
    dest->color = sfWhite;
    dest->lifetime = 150;
    dest->type = ROCK_DUCK;
    dest->spd = update_spd_ice_duck(player->dir);
    dest->update = update_rock_duck_projectile;
    dest->dir = player->dir;
    dest->scale = ((sfVector2f){.x = 0.5, .y = 0.5});
    dest->dmg = 5 + player->dmg;
    dest->hitbox_size = ((sfFloatRect){0, 0, 20, 20});
    dest->element = ROCK;
    sprite_set_center(dest->sprite);
    return dest;
}

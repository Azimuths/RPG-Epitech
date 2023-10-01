/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** water_duck_projectile
*/

#include "projectile.h"
#include "particle.h"
#include "player.h"
#include "my.h"
#include <stdlib.h>

int update_waterparticle(game_t *game, particle_t *particle)
{
    particle->color.a -= 50;
    return 0;
}

particle_t *create_water_particle(game_t *game, sfVector2f pos, sfVector2f spd,
        dir_t dir)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->pos.x = pos.x + (rand() % 40 - 20);
    dest->pos.y = pos.y + (rand() % 40 - 20);
    dest->color = sfWhite;
    dest->lifetime = 5;
    dest->type = RAIN_PART;
    dest->spd = spd;
    dest->update = update_waterparticle;
    if (dir == DOWN)
        dest->rot = 195;
    else if (dir == LEFT)
        dest->rot = 105;
    if (dir == RIGHT)
        dest->rot = 285;
    else if (dir == UP)
        dest->rot = 15;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    return dest;
}

int update_water_duck_projectile(game_t *game __attribute__((unused)),
        projectile_t *proj)
{
    sfVector2f spd = ((sfVector2f){proj->spd.x * -1, proj->spd.y * -1});

    if (proj->dir == DOWN)
        proj->spd.y -= (float)0.5;
    if (proj->dir == UP)
        proj->spd.y += (float)0.5;
    if (proj->dir == LEFT)
        proj->spd.x += (float)0.5;
    if (proj->dir == RIGHT)
        proj->spd.x -= (float)0.5;
    if (proj->dir == LEFT || proj->dir == DOWN)
        proj->rot += 5;
    else
        proj->rot -= 5;
    add_node(create_water_particle(game, proj->pos, spd, proj->dir),
            &(game->particles));
    return 0;
}

static sfVector2f update_spd_ice_duck(dir_t dir)
{
    if (dir == DOWN)
        return ((sfVector2f){.x = 0, .y = 15});
    else if (dir == LEFT)
        return ((sfVector2f){.x = -15, .y = 0});
    if (dir == RIGHT)
        return ((sfVector2f){.x = 15, .y = 0});
    else if (dir == UP)
        return ((sfVector2f){.x = 0, .y = -15});
}

projectile_t *create_water_duck_projectile(player_t *player)
{
    projectile_t *dest = my_memset(sizeof(projectile_t), NULL);

    dest->sprite = sfSprite_create();
    dest->pos = player->pos;
    dest->color = sfWhite;
    dest->lifetime = 75;
    dest->type = WATER_DUCK;
    dest->spd = update_spd_ice_duck(player->dir);
    dest->update = update_water_duck_projectile;
    dest->dmg = 5 + player->dmg;
    dest->dir = player->dir;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    dest->hitbox_size = ((sfFloatRect){0, 0, 40, 40});
    dest->element = WATER;
    sprite_set_center(dest->sprite);
    return dest;
}

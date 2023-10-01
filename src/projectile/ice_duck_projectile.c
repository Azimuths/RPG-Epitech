/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** wind_duck_projectile
*/

#include "projectile.h"
#include "particle.h"
#include "player.h"
#include "my.h"
#include "math.h"
#include <stdlib.h>

int update_iceparticle(game_t *game, particle_t *particle)
{
    particle->spd.x = (float)(cos(particle->lifetime / 10)) * 2;
    return 0;
}

particle_t *create_ice_particle(game_t *game, sfVector2f pos, sfVector2f speed,
        dir_t dir)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->pos.x = pos.x + (rand() % 40 - 20);
    dest->pos.y = pos.y + (rand() % 40 - 20);
    dest->color = ICE_COLOR;
    dest->lifetime = 5;
    dest->type = SNOW_PART;
    dest->spd = speed;
    dest->update = update_iceparticle;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    return dest;
}

int update_ice_duck_projectile(game_t *game __attribute__((unused)),
        projectile_t *proj)
{
    sfVector2f spd = ((sfVector2f){proj->spd.x * -1, proj->spd.y * -1});

    if (proj->dir == UP || proj->dir == DOWN) {
        proj->spd.x = (float)(cos((proj->lifetime / 30.0))) * 5;
        proj->rot += (float)(cos((proj->lifetime / 30.0))) * 10;
    }
    if (proj->dir == LEFT || proj->dir == RIGHT) {
        proj->spd.y = (float)(cos((proj->lifetime / 30.0))) * 5;
        proj->rot += (float)(cos((proj->lifetime / 30.0))) * 10;
    }
    add_node(create_ice_particle(game, proj->pos, spd, proj->dir),
            &(game->particles));
    return 0;
}

static sfVector2f update_spd_ice_duck(dir_t dir)
{
    if (dir == DOWN)
        return ((sfVector2f){.x = 0, .y = 2});
    else if (dir == LEFT)
        return ((sfVector2f){.x = -2, .y = 0});
    if (dir == RIGHT)
        return ((sfVector2f){.x = 2, .y = 0});
    else if (dir == UP)
        return ((sfVector2f){.x = 0, .y = -2});
}

projectile_t *create_ice_duck_projectile(player_t *player)
{
    projectile_t *dest = my_memset(sizeof(projectile_t), NULL);

    dest->sprite = sfSprite_create();
    dest->pos = player->pos;
    dest->color = sfWhite;
    dest->lifetime = 380;
    dest->type = ICE_DUCK;
    dest->spd = update_spd_ice_duck(player->dir);
    dest->update = update_ice_duck_projectile;
    dest->dir = player->dir;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    dest->dmg = 5 + player->dmg;
    dest->hitbox_size = ((sfFloatRect){0, 0, 40, 40});
    sprite_set_center(dest->sprite);
    dest->element = ICE;
    return dest;
}

/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** other_ice_duck_projectile
*/

#include "projectile.h"
#include "particle.h"
#include "player.h"
#include "my.h"
#include "math.h"
#include <stdlib.h>

int update_iceparticle(game_t *game, particle_t *particle);
particle_t *create_ice_particle(game_t *game, sfVector2f pos, sfVector2f speed,
        dir_t dir);

int update_other_ice_duck_projectile(game_t *game __attribute__((unused)),
        projectile_t *proj)
{
    sfVector2f spd = ((sfVector2f){proj->spd.x * -1, proj->spd.y * -1});

    if (proj->dir == UP || proj->dir == DOWN) {
        proj->spd.x = (float)(cos((proj->lifetime / 30.0))) * -5;
        proj->rot += (float)(cos((proj->lifetime / 30.0))) * -10;
    }
    if (proj->dir == LEFT || proj->dir == RIGHT) {
        proj->spd.y = (float) (cos((proj->lifetime / 30.0))) * -5;
        proj->rot += (float) (cos((proj->lifetime / 30.0))) * -10;
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

projectile_t *create_other_ice_duck_projectile(player_t *player)
{
    projectile_t *dest = my_memset(sizeof(projectile_t), NULL);

    dest->sprite = sfSprite_create();
    dest->pos = player->pos;
    dest->color = sfWhite;
    dest->lifetime = 380;
    dest->type = ICE_DUCK;
    dest->spd = update_spd_ice_duck(player->dir);
    dest->update = update_other_ice_duck_projectile;
    dest->dir = player->dir;
    dest->dmg = 5 + player->dmg;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    dest->hitbox_size = ((sfFloatRect){0, 0, 40, 40});
    dest->element = ICE;
    sprite_set_center(dest->sprite);
    return dest;
}

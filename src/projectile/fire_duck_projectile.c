/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fire_duck_projectile
*/

#include "projectile.h"
#include "particle.h"
#include "player.h"
#include "my.h"
#include <stdlib.h>

int update_fireparticle(game_t *game, particle_t *particle)
{
    particle->spd.y = (float)(particle->spd.y / 1.05);
    particle->spd.x = (float)(particle->spd.x / 1.05);
    if (particle->color.g < 235)
        particle->color.g += 30;
    return 0;
}

particle_t *create_fire_particle(game_t *game, projectile_t *proj)
{
    particle_t *dest = my_memset(sizeof(particle_t), NULL);

    dest->pos.x = proj->pos.x - proj->spd.x + (rand() % 40 - 20);
    dest->pos.y = proj->pos.y - proj->spd.y + (rand() % 40 - 20);
    dest->color = sfWhite;
    dest->lifetime = 5;
    dest->type = FIRE_PART;
    dest->spd.x = proj->spd.x * -1;
    dest->spd.y = -1;
    if (proj->spd.y > 0)
        dest->spd.y = proj->spd.y * -1;
    dest->update = update_fireparticle;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    return dest;
}

int update_fire_duck_projectile(game_t *game __attribute__((unused)),
        projectile_t *proj)
{
    if (proj->lifetime > 60) {
        proj->spd.y += (float)1;
        proj->spd.x *= 0.99;
    } else
        proj->spd = ((sfVector2f){0});
    if (proj->lifetime == 97)
        proj->spd.y = -10;
    if (proj->lifetime == 75)
        proj->spd.y = -5;
    if (proj->lifetime == 69)
        proj->spd.y = -4;
    add_node(create_fire_particle(game, proj), &(game->particles));
    if (proj->lifetime <= 0)
        fire_duck_explode(game, proj);
    return 0;
}

static sfVector2f update_spd_fire_duck(dir_t dir)
{
    if (dir == DOWN)
        return ((sfVector2f) {.x = 0, .y = -5});
    if (dir == LEFT)
        return ((sfVector2f) {.x = -6, .y = -13});
    if (dir == RIGHT)
        return ((sfVector2f) {.x = 6, .y = -13});
    if (dir == UP)
        return ((sfVector2f) {.x = 0, .y = -22});
}

projectile_t *create_fire_duck_projectile(player_t *player)
{
    projectile_t *dest = my_memset(sizeof(projectile_t), NULL);

    dest->sprite = sfSprite_create();
    dest->pos = player->pos;
    dest->color = sfWhite;
    dest->lifetime = 125;
    dest->type = FIRE_DUCK;
    dest->spd = update_spd_fire_duck(player->dir);
    dest->update = update_fire_duck_projectile;
    dest->dir = player->dir;
    dest->rot = 0;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    dest->dmg = player->dmg;
    dest->hitbox_size = ((sfFloatRect){0, 0, 20, 20});
    sprite_set_center(dest->sprite);
    dest->element = FIRE;
    return dest;
}

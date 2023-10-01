/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_rock_duck_collectable
*/

#include "collectable.h"
#include "particle.h"
#include "projectile.h"
#include "inventory.h"
#include "my.h"
#include "quest.h"
#include "math.h"

int on_collision_rock_duck_collectable(game_t *game, collectable_t *coll)
{
    add_inventory(game, WEAPON_ROCK_DUCK);
    game->list_quest->denis_quest = sfFalse;
    return 0;
}

int update_rock_duck_collectable(game_t *game __attribute__((unused)),
        collectable_t *coll)
{
    coll->pos.x -= coll->spd.x;
    coll->pos.y -= coll->spd.y + (cosf(coll->lifetime++ / 50.0) * 0.5);
    add_node(create_star_particle_on_duck(game, coll->pos, ROCK_COLOR),
            &(game->particles));
    return 0;
}

collectable_t *create_rock_duck_collectable(game_t *game, sfVector2f pos)
{
    collectable_t *dest = my_memset(sizeof(collectable_t), NULL);

    dest->sprite = sfSprite_create();
    sfSprite_setTexture(dest->sprite, game->textures->projectile[ROCK_DUCK],
            sfTrue);
    dest->pos = pos;
    dest->spd = pos;
    dest->color = sfWhite;
    dest->update = update_rock_duck_collectable;
    dest->on_collision = on_collision_rock_duck_collectable;
    dest->rot = 0;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    dest->hitbox_size = ((sfFloatRect){0, 0, 20, 20});
    sprite_set_center(dest->sprite);
    return dest;
}

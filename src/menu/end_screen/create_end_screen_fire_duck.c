/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_end_screen_fire_duck
*/

#include "particle.h"
#include "projectile.h"
#include "my.h"
#include "math.h"

int update_end_screen_fire_duck(game_t *game, projectile_t *coll)
{
    coll->pos.x -= coll->spd.x + (cosf(coll->lifetime++ / 50.0) * 10);
    coll->pos.y -= coll->spd.y + (sinf(coll->lifetime++ / 50.0) * 10);
    add_node(create_end_screen_star_particle(game, coll->pos, sfRed),
            &(game->particles));
    return 0;
}

projectile_t *create_end_screen_fire_duck(game_t *game)
{
    projectile_t *dest = my_memset(sizeof(projectile_t), NULL);

    dest->sprite = sfSprite_create();
    sfSprite_setTexture(dest->sprite, game->textures->projectile[FIRE_DUCK],
            sfTrue);
    dest->pos = ((sfVector2f){.x = 1000, .y = 1000});
    dest->spd = ((sfVector2f){0, 0});
    dest->color = sfWhite;
    dest->type = FIRE_DUCK;
    dest->update = update_end_screen_fire_duck;
    dest->rot = 0;
    dest->scale = ((sfVector2f){.x = 4, .y = 4});
    dest->hitbox_size = ((sfFloatRect){0, 0, 20, 20});
    sprite_set_center(dest->sprite);
    return dest;
}

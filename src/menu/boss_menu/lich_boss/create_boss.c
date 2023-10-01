/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create_boss
*/

#include "enemy.h"
#include "my.h"

enemy_t *create_lich_boss(game_t *game)
{
    enemy_t *dest = my_memset(sizeof(enemy_t), NULL);

    dest->sprite = sfSprite_create();
    dest->texture = game->textures->enemies[LICH];
    sfSprite_setTexture(dest->sprite, dest->texture, sfFalse);
    dest->type = LICH;
    dest->status = ENEMY_IDLE;
    dest->rect = ((sfIntRect){.top = 0, .left = 0, .width = 32, .height = 32});
    dest->scale = ((sfVector2f){.x = -10, .y = 10});
    dest->clock = sfClock_create();
    dest->pos = ((sfVector2f){.x = 1800, .y = 500});
    dest->exp = 1000;
    dest->hitbox_size = ((sfFloatRect){30, 30, 120, 180});
    dest->dir = RIGHT;
    sprite_set_center(dest->sprite);
    init_enemy_element_and_hp(game, dest);
    dest->hp = 100;
    return dest;
}

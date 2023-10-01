/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** pnj_quest
*/

#include "enemy.h"
#include "my.h"
#include "stdlib.h"
#include "particle.h"

enemy_t *create_pnj_quest(game_t *game, sfVector2f pos)
{
    enemy_t *dest = my_memset(sizeof(enemy_t), NULL);

    dest->sprite = sfSprite_create();
    sfSprite_setTexture(dest->sprite,
            game->player->textures[VILLAGER7], sfFalse);
    dest->rect = ((sfIntRect){0, 0, 48, 48});
    sfSprite_setTextureRect(dest->sprite, dest->rect);
    dest->type = PNJ_QUEST;
    dest->hp = 1000000;
    dest->scale = ((sfVector2f){.x = 1, .y = 1});
    dest->pos = pos;
    dest->exp = 1000000;
    dest->hitbox_size = ((sfFloatRect){0, 0, 20, 20});
    sprite_set_center(dest->sprite);
    return dest;
}

/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** check_collectible
*/

#include "collectable.h"
#include "player.h"

int check_collectable(game_t *game, collectable_t *coll)
{
    sfFloatRect en = {0};
    sfFloatRect coll_rect = {0};
    player_t *player = game->player;

    en = get_hitbox(player->pos, player->hitbox_size);
    coll_rect = get_hitbox(coll->pos, coll->hitbox_size);
    if (sfFloatRect_intersects(&en, &coll_rect, NULL) == sfTrue) {
        if (coll->on_collision != NULL)
            coll->on_collision(game, coll);
        return 1;
    }
    return 0;
}

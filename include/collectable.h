/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** collectible
*/

#include "SFML/Graphics.h"
#include "rpg.h"

#ifndef COLLECTIBLE_H
    #define COLLECTIBLE_H

typedef struct collectable_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfColor color;
    sfVector2f spd;
    int (*update)(game_t *, struct collectable_s *);
    int (*on_collision)(game_t *, struct collectable_s *);
    float rot;
    sfVector2f scale;
    sfFloatRect hitbox_size;
    int lifetime;
} collectable_t;

int check_collectable(game_t *game, collectable_t *coll);
void destroy_collectable(collectable_t *coll);
int draw_collectables(game_t *game);
int check_collectable(game_t *game, collectable_t *coll);
int update_collectable(game_t *game);
int check_collision_collectable(game_t *game);
collectable_t *create_fire_duck_collectable(game_t *game, sfVector2f pos);
collectable_t *create_ice_duck_collectable(game_t *game, sfVector2f pos);
collectable_t *create_rock_duck_collectable(game_t *game, sfVector2f pos);
collectable_t *create_water_duck_collectable(game_t *game, sfVector2f pos);
void destroy_collectables(game_t *game);

#endif

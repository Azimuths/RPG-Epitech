/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** projectile
*/

#include "rpg.h"
#include "player.h"

#ifndef PROJECTILE_H
    #define PROJECTILE_H

typedef enum projectile_type_e {
    NO_PARTICLE = -1,
    FIRE_DUCK,
    ICE_DUCK,
    WATER_DUCK,
    ROCK_DUCK,
    VANILLA_DUCK,
    NB_PROJECTILES
} projectile_type_t;

typedef struct projectile_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfColor color;
    int lifetime;
    sfVector2f spd;
    projectile_type_t type;
    int (*update)(game_t *, struct projectile_s *);
    dir_t dir;
    float rot;
    sfVector2f scale;
    int dmg;
    sfFloatRect hitbox_size;
    element_t element;
} projectile_t;

int update_projectiles(game_t *game, linked_list_t **list);
int draw_projectiles(game_t *game, linked_list_t **list);
int clear_projectiles(game_t *game, linked_list_t **list);
projectile_t *create_fire_duck_projectile(player_t *player);
projectile_t *create_ice_duck_projectile(player_t *player);
projectile_t *create_other_ice_duck_projectile(player_t *player);
projectile_t *create_rock_duck_projectile(player_t *player);
projectile_t *create_water_duck_projectile(player_t *player);
int check_collisions_projectile(game_t *game);
int destroy_projectile(projectile_t *projectile);
int check_collisions_enemy_projectile(game_t *game);
int destroy_projectiles(game_t *game, linked_list_t **list_proj);
projectile_t *create_ice_skull_spell_projectile(sfVector2f sp, sfVector2f pos);
int fire_duck_explode(game_t *game, projectile_t *proj);
projectile_t *create_end_screen_fire_duck(game_t *game);
projectile_t *create_end_screen_rock_duck(game_t *game);
projectile_t *create_end_screen_ice_duck(game_t *game);
projectile_t *create_end_screen_water_duck(game_t *game);
projectile_t *create_fire_skull_spell_projectile(game_t *game, sfVector2f spd);
void fire_spell_second_spell(game_t *game, projectile_t *proj);

#endif

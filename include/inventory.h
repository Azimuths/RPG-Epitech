/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** inventory
*/

#include "SFML/Graphics.h"
#include "rpg.h"

#ifndef INVENTORY_H
    #define INVENTORY_H

typedef enum weapon_e {
    WEAPON_NONE = 0,
    WEAPON_SWORD,
    WEAPON_FIRE_DUCK,
    WEAPON_WATER_DUCK,
    WEAPON_ICE_DUCK,
    WEAPON_ROCK_DUCK,
    NB_WEAPON
} weapon_t;

typedef struct inventory_s {
    object_t **slots;
    weapon_t *contents;
    sfSprite **sprites;
    int curr;
    object_t *indicator;
} inventory_t;

    #define NB_INVENTORY_SLOTS 6

inventory_t *init_inventory(void);
void draw_inventory(game_t *game);
void destroy_inventory(inventory_t *inventory);
int update_inventory(inventory_t *inventory, sfEvent event);
int add_inventory(game_t *game, weapon_t weapon);
void update_inventory_object(inventory_t *inv, game_t *game);

#endif

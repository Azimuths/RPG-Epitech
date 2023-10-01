/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_inventory
*/

#include "rpg.h"
#include "projectile.h"
#include "inventory.h"

void update_sprite_weapon(inventory_t *inv, game_t *game, int i)
{
    if (inv->contents[i] == WEAPON_SWORD) {
        sfSprite_setTexture(inv->sprites[i], game->player->sword_text,
                sfFalse);
        sfSprite_setTextureRect(inv->sprites[i],
                ((sfIntRect){34, 144, 64, 64}));
    }
    if (inv->contents[i] == WEAPON_FIRE_DUCK)
        sfSprite_setTexture(inv->sprites[i],
                game->textures->projectile[FIRE_DUCK], sfTrue);
    if (inv->contents[i] == WEAPON_ROCK_DUCK)
        sfSprite_setTexture(inv->sprites[i],
                game->textures->projectile[ROCK_DUCK], sfTrue);
    if (inv->contents[i] == WEAPON_ICE_DUCK)
        sfSprite_setTexture(inv->sprites[i],
                game->textures->projectile[ICE_DUCK], sfTrue);
    if (inv->contents[i] == WEAPON_WATER_DUCK)
        sfSprite_setTexture(inv->sprites[i],
                game->textures->projectile[WATER_DUCK], sfTrue);
    sprite_set_center(inv->sprites[i]);
}

void update_inventory_object(inventory_t *inv, game_t *game)
{
    for (int i = 0; i < NB_WEAPON; ++i) {
        update_sprite_weapon(inv, game, i);
    }
}

int update_inventory(inventory_t *inv, sfEvent evt)
{
    if (evt.type == sfEvtKeyPressed || evt.type == sfEvtMouseWheelScrolled) {
        if ((evt.key.code == sfKeyLeft || evt.mouseWheelScroll.delta < 0) &&
                inv->curr)
            inv->curr -= 1;
        if ((evt.key.code == sfKeyRight || evt.mouseWheelScroll.delta > 0) &&
                inv->curr < NB_WEAPON - 1)
            inv->curr += 1;
    }
    sfSprite_setPosition(inv->indicator->sprite, inv->slots[inv->curr]->pos);
    return 0;
}

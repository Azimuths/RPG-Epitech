/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** game_object
*/

#include "rpg.h"
#include "macro.h"
#include "projectile.h"
#include <stdlib.h>
#include "inventory.h"
#include "my.h"

int init_inventory_sprites(inventory_t *obj)
{
    int offset = NB_INVENTORY_SLOTS / -2 * 120;

    obj->slots = my_memset(sizeof(object_t *) * NB_INVENTORY_SLOTS, NULL);
    obj->sprites = my_memset(sizeof(sfSprite *) * NB_INVENTORY_SLOTS, NULL);
    for (int i = 0; i < NB_INVENTORY_SLOTS; ++i) {
        obj->sprites[i] = sfSprite_create();
        obj->slots[i] = create_object(INVENTORY_SLOT,
                ((sfIntRect){0, 0, 80, 80}), ((sfVector2f){960 + offset, 1000}),
                ((sfVector2f){1.3, 1.3}));
        offset += 120;
        if (obj->slots[i] == NULL || obj->sprites[i] == NULL)
            return 84;
        sfSprite_setPosition(obj->sprites[i], obj->slots[i]->pos);
        sprite_set_center(obj->slots[i]->sprite);
        sprite_set_center(obj->sprites[i]);
    }
    return 0;
}

inventory_t *init_inventory(void)
{
    inventory_t *obj = my_memset(sizeof(inventory_t), NULL);

    if (init_inventory_sprites(obj) == 84)
        return my_null_error("Failed to init inventory");
    obj->indicator = create_object(INVENTORY_BOX,
((sfIntRect){0, 0, 128, 128}), obj->slots[0]->pos, ((sfVector2f){1.3, 1.3}));
    obj->contents = my_memset(sizeof(weapon_t) * NB_INVENTORY_SLOTS, NULL);
    if (obj->indicator == NULL || obj->contents == NULL)
        return my_null_error("Failed to init inventory");
    sprite_set_center(obj->indicator->sprite);
    return obj;
}

void draw_inventory(game_t *game)
{
    update_inventory_object(game->inventory, game);
    for (int i = 0; i < NB_INVENTORY_SLOTS; ++i) {
        draw_object(game->inventory->slots[i], game);
        sfRenderWindow_drawSprite(game->window, game->inventory->sprites[i],
                NULL);
    }
    draw_object(game->inventory->indicator, game);
}

void destroy_inventory(inventory_t *inventory)
{
    for (int i = 0; i < NB_INVENTORY_SLOTS; ++i) {
        sfSprite_destroy(inventory->slots[i]->sprite);
        sfTexture_destroy(inventory->slots[i]->texture);
    }
    free(inventory->slots);
    free(inventory->contents);
    free(inventory);
}

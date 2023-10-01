/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_player
*/

#include "rpg.h"
#include "my.h"
#include "player.h"
#include <stdlib.h>

sfTexture **all_texture_player(void)
{
    sfTexture **texture = my_memset(sizeof(sfTexture *)
            * NB_PLAYER_TEXTURES, NULL);
    const char *filepath[] = {HERO1_SPRITE, HERO2_SPRITE,
                                VILLAGER3_SPRITE, VILLAGER7_SPRITE,
                                VILLAGER8_SPRITE, VILLAGER9_SPRITE};

    for (int i = 0; i < NB_PLAYER_TEXTURES; ++i) {
        texture[i] = sfTexture_createFromFile(filepath[i], NULL);
        if (texture[i] == NULL) {
            return my_null_error("Failed to load player skins");
        }
    }
    return texture;
}

int init_sword(player_t *out)
{
    sfVector2f origin = {0};

    out->pos = ((sfVector2f){1, 1});
    out->scale = ((sfVector2f){0, 0});
    out->sword = sfSprite_create();
    out->sword_text = sfTexture_createFromFile(SWORD_SPRITE, NULL);
    if (out->sword == NULL || out->sword_text == NULL)
        return 84;
    sfSprite_setTexture(out->sword, out->sword_text, sfFalse);
    out->sword_rect = ((sfIntRect){.top = 0, .left = 0,
                                .width = 144, .height = 144});
    sfSprite_setTextureRect(out->sword, out->sword_rect);
    origin = ((sfVector2f){(out->sword_rect.width / 2),
            (out->sword_rect.height / 2)});
    sfSprite_setOrigin(out->sword, origin);
    return 0;
}

player_t *init_player(player_textures_t skin)
{
    player_t *out = my_memset(sizeof(player_t), NULL);
    sfVector2f origin = {0};

    out->sprite = sfSprite_create();
    out->textures = all_texture_player();
    out->clock = sfClock_create();
    if (out->sprite == NULL || out->textures == NULL || out->clock == NULL)
        return NULL;
    out->rect = ((sfIntRect){.top = 0, .left = 0, .width = 48, .height = 48});
    out->dir = LEFT;
    out->velocity = ((sfVector2f){0, 0});
    out->status = PLAYER_IDLE;
    sfSprite_setTexture(out->sprite, out->textures[skin], sfFalse);
    sfSprite_setTextureRect(out->sprite, out->rect);
    out->hp = 20;
    out->hitbox_size = ((sfFloatRect){0, 0, 20, 20});
    sprite_set_center(out->sprite);
    if (init_sword(out) == 84)
        return NULL;
    return out;
}

int destroy_player(player_t *player)
{
    sfSprite_destroy(player->sprite);
    sfSprite_destroy(player->sword);
    sfTexture_destroy(player->sword_text);
    sfClock_destroy(player->clock);
    for (int i = 0; i < NB_PLAYER_TEXTURES; ++i) {
        sfTexture_destroy(player->textures[i]);
    }
    free(player->textures);
    free(player);
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** draw_home_map
*/

#include "SFML/Graphics.h"
#include "rpg.h"
#include "editor.h"

void draw_tile(game_t *game, sfSprite *sprite, int x, int y)
{
    sfVector2f pos = {.x = x * 96, .y = y * 96};

    sfSprite_setTexture(sprite,
game->editor->textures[game->editor->map->map_text[x][y]], sfFalse);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
}

void draw_home_map(game_t *game)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, ((sfVector2f){6, 6}));
    sfSprite_setTextureRect(sprite, ((sfIntRect){0, 0, 16, 16}));
    for (int i = 0; i < game->editor->map->width - 1; ++i) {
        for (int j = 0; j < game->editor->map->height - 1; ++j) {
            draw_tile(game, sprite, i, j);
        }
    }
    sfSprite_destroy(sprite);
}

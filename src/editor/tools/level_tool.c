/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** level_tool
*/

#include "editor.h"

void level_tool(wd_game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);

    mouse.x = mouse.x * 1920 / game->mode.width;
    mouse.y = mouse.y * 1080 / game->mode.height;
    if (game->map->selected.x != -1) {
        if (pos_3d_to_2d(game->map->selected.x, game->map->selected.y,
            SELECTED_TILE + 1, game).y > (float)mouse.y)
            SELECTED_TILE += 1;
        if (pos_3d_to_2d(game->map->selected.x, game->map->selected.y,
            SELECTED_TILE - 1, game).y < (float)mouse.y)
            SELECTED_TILE -= 1;
    }
}

void union_tool(wd_game_t *game)
{
    sfVector2f dot = {-1, -1};
    sfCircleShape *circle = init_circle(500 / (game->map->fov / 10));
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);
    int tmpx = 0;
    int tmpy = 0;

    for (int i = 0; i < 4; i++) {
        tmpx = (game->map->selected.x) + (i - 1) * (i % 2 == 0);
        tmpy = (game->map->selected.y) + (i - 2) * (i % 2 == 1);
        if (game->map->selected.x != -1)
            dot = pos_3d_to_2d(tmpx, tmpy, SELECTED_TILE, game);
        if (dot.x == -1)
            continue;
        sfCircleShape_setPosition(circle, dot);
        if (circleshape_contains(circle, mouse)) {
            game->map->map[tmpx][tmpy] = SELECTED_TILE;
            game->map->selected = (sfVector2i){.x = tmpx, .y = tmpy};
        }
    }
}

void skin_tool(wd_game_t *game)
{
    sfVector2i tile;
    sfVector2i tmp = sfMouse_getPositionRenderWindow(game->win);
    sfVector2f mouse = {.x = (float)tmp.x, .y = (float)tmp.y};

    mouse.x = mouse.x * 1920 / game->mode.width;
    mouse.y = mouse.y * 1080 / game->mode.height;
    for (int i = 0; i < (game->map->width - 1) * (game->map->height - 1); ++i) {
        tile.y = update_x(i, game, game->map->width - 1, game->map->height -
        1);
        tile.x = update_y(i, game, game->map->width - 1, game->map->height -
        1);
        if (tile_contains(game, tile, mouse)) {
            game->map->map_text[tile.x][tile.y] = game->map->spritetype;
            return;
        }
    }
}

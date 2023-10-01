/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** print_map
*/

#include "editor.h"

int draw_map(wd_game_t *game)
{
    sfVertexArray *vertexarr = sfVertexArray_create();
    sfCircleShape *circle = init_circle(50 / (game->map->fov / 10));
    int x = 0;
    int y = 0;

    sfVertexArray_setPrimitiveType(vertexarr, sfQuads);
    for (int i = 0; i < (game->map->width) * (game->map->height); ++i) {
        y = update_x(i, game, game->map->width, game->map->height);
        x = update_y(i, game, game->map->width, game->map->height);
        draw_line(game, game->map->points, x, y);
        if (x != game->map->width - 1 && y != game->map->height - 1)
            draw_spritetile(game, x, y, vertexarr);
        circleshape_draw(game, circle, x, y);
        if (sfKeyboard_isKeyPressed(sfKeyH))
        sfRenderWindow_display(game->win);
    }
    sfVertexArray_destroy(vertexarr);
    sfCircleShape_destroy(circle);
    return 0;
}

int render_map(wd_game_t *game)
{
    for (int y = 0; y < game->map->width; ++y)
        for (int x = 0; x < game->map->height; ++x) {
            game->map->points[y][x] = pos_3d_to_2d(y, x,
                    game->map->map[y][x], game);
        }
    draw_map(game);
    return 0;
}

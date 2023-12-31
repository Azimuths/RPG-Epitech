/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** points
*/

#include "editor.h"
#include "my.h"

sfVector2f *get_point(int x, int y, int z, wd_game_t *game)
{
    sfVector2f *point = my_memset(sizeof(sfVector2f), NULL);

    x *= 64;
    y *= 64;
    z *= 64;
    point->x = cos(to_radiant(game->angle.x)) * x
            - cos(to_radiant(game->angle.x)) * y;
    point->y = sin(to_radiant(game->angle.y)) * y
            + sin(to_radiant(game->angle.y)) * x - z;
    point->x += WIDTH / 2;
    point->y += HEIGHT / 4;
    if (point->x > 0 && point->x < game->fb->width && point->y > 0 &&
            point->y < game->fb->height) {
        return point;
    }
    point->x = -1;
    point->y = -1;
    return point;
}

sfVector2f **get_points(wd_game_t *game)
{
    sfVector2f **points = my_memset(sizeof(sfVector2f *) * (
    game->map->height + 1), NULL);

    for (int x = 0; x < game->map->width; ++x)
        points[x] = my_memset(sizeof(sfVector2f) * (
        game->map->height + 1), NULL);
    for (int y = 0; y < game->map->height; ++y)
        for (int x = 0; x < game->map->width; ++x)
            points[x][y] = pos_3d_to_2d(x, y, game->map->map[x][y], game);
    return points;
}

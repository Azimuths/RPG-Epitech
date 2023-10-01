/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** draw_line
*/

#include "editor.h"

sfVertexArray *create_line(sfVector2f point1, sfVector2f point2)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = point1, .color = sfWhite};
    sfVertex vertex2 = {.position = point2, .color = sfWhite};

    if (point1.x == -1 || point1.y == -1 ||
        point2.x == -1 || point2.y == -1)
        return NULL;
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
    return (vertex_array);
}

int draw_line(wd_game_t *game, sfVector2f **points, int x, int y)
{
    sfVertexArray *line = NULL;

    if (x > 0) {
        line = create_line(points[x - 1][y], points[x][y]);
        if (line == NULL)
            return 1;
        sfRenderWindow_drawVertexArray(game->win, line, NULL);
        sfVertexArray_destroy(line);
    }
    if (y > 0) {
        line = create_line(points[x][y - 1], points[x][y]);
        if (line == NULL)
            return 2;
        sfRenderWindow_drawVertexArray(game->win, line, NULL);
        sfVertexArray_destroy(line);
    }
    return 0;
}

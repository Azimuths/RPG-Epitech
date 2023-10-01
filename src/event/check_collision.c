/*
** EPITECH PROJECT, 2022
** my rp
** File description:
** collision checking using colision map
*/

#include "rpg.h"
#include "player.h"
#include "macro.h"

void enter_home(game_t *game)
{
    game->screen = HOME_GAME;
    game->player->pos = (sfVector2f){1548, 1032};
    game->player->velocity = (sfVector2f){0, 0};
    sfView_move(game->map->view, (sfVector2f){-1920, -1056});
}

int check_collision(game_t *game, sfVector2f pos)
{
    int test = get_map_pos(game, pos);

    if (pos.x < 0 || pos.y < 0)
        return 0;
    if (game->map->collision_map[test] == '1')
        return 1;
    if (game->map->collision_map[test] == 'H')
        enter_home(game);
    return 0;
}

int show_map_coll(game_t *game)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfBlack);
    sfRectangleShape_setSize(rect, ((sfVector2f){SIZE_X, SIZE_Y}));
    for (int x = 0; x < 60; ++x) {
        for (int y = 0; y < 46; ++y) {
            if (game->map->collision_map[y * 60 + x] == '1') {
                sfRectangleShape_setPosition(rect,
                        ((sfVector2f) {(SIZE_X) * x, (SIZE_Y) * y}));
                sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
            }
        }
    }
}

int show_screen_coll(game_t *game)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, sfWhite);
    sfRectangleShape_setSize(rect, ((sfVector2f){SIZE_X, SIZE_Y}));
    for (int x = 0; x < 20; ++x) {
        for (int y = 0; y < 11; ++y) {
            if (game->map->collision_map[
            get_map_pos(game, ((sfVector2f){x * 96, y * 96}))] == '1') {
                sfRectangleShape_setPosition(rect,
                        ((sfVector2f) {(SIZE_X) * x, (SIZE_Y) * y}));
                sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
            }
        }
    }
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** check_home_exit
*/

#include "SFML/Graphics.h"
#include "rpg.h"
#include "player.h"

int check_home_exit(game_t *game)
{
    sfFloatRect rect = {.left = 1500, .top = 984,
                        .width = 96, .height = 96};
    sfRectangleShape *rect2 = sfRectangleShape_create();

    if (sfFloatRect_contains(&rect, game->player->pos.x,
            game->player->pos.y)) {
        reset_game(game);
        game->player->pos = ((sfVector2f){1900, 1050});
        game->screen = GAME;
    }
    sfRectangleShape_setSize(rect2, ((sfVector2f){rect.width, rect.height}));
    sfRectangleShape_setPosition(rect2, ((sfVector2f){rect.left, rect.top}));
    sfRectangleShape_setFillColor(rect2, sfWhite);
    sfRenderWindow_drawRectangleShape(game->window, rect2, NULL);
    return 0;
}

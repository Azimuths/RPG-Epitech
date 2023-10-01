/*
** EPITECH PROJECT, 2022
** my rpg
** File description:
** map init file
*/

#include "rpg.h"
#include "macro.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *load_collision(game_t *game)
{
    char *col_buffer = NULL;
    int fd = 0;

    if ((fd = open("./map.txt", O_RDONLY)) < 0) {
        return NULL;
    }
    col_buffer = malloc(sizeof(char) * (2640 + 1));
    if (read(fd, col_buffer, 2640) < 0) {
        return NULL;
    }
    col_buffer[2640] = '\0';
    close(fd);
    return col_buffer;
}

static void init_vectors(game_t *game)
{
    game->map->pos = (sfVector2f){0, 0};
    game->map->offset = (sfVector2f){10, 5};
    game->map->col_pos = 0;
    game->map->scale = ((sfVector2f){2, 2});
    game->map->screen_pos = (sfVector2u){0, 0};
}

int map_init(game_t *game)
{
    game->map = malloc(sizeof(map_t));

    if (!game->map)
        return 84;
    init_vectors(game);
    game->map->sprite = sfSprite_create();
    game->map->texture = sfTexture_createFromFile(MAP, NULL);
    if (game->map->texture == NULL || game->map->sprite == NULL)
        return 84;
    sfSprite_setTexture(game->map->sprite, game->map->texture, sfTrue);
    sfSprite_setPosition(game->map->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(game->map->sprite, game->map->scale);
    if (!(game->map->collision_map = load_collision(game)))
        return 84;
    game->map->view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfRenderWindow_setView(game->window, game->map->view);
    return 0;
}

int map_destroy(game_t *game)
{
    sfSprite_destroy(game->map->sprite);
    sfTexture_destroy(game->map->texture);
    sfView_destroy(game->map->view);
    sfView_destroy(game->game_view);
    free(game->map->collision_map);
    free(game->map);
    return 0;
}

/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_game
*/

#include "editor.h"
#include "rpg.h"
#include "my.h"
#include <stdlib.h>

sfTexture **init_all_textures_editor(void)
{
    sfTexture **dest = my_memset(sizeof(sfTexture *) * NB_SPRITES, NULL);

    dest[FIRE_SPRITE] = sfTexture_createFromFile(FIRE_TILE_TEXT, NULL);
    dest[ICE_SPRITE] = sfTexture_createFromFile(ICE_TILE_TEXT, NULL);
    dest[SWAMP_SPRITE] = sfTexture_createFromFile(SWAMP_TILE_TEXT, NULL);
    dest[GRASS_SPRITE] = sfTexture_createFromFile(GRASS_TILE_TEXT, NULL);
    for (int i = 0; i < NB_SPRITES; ++i) {
        if (dest[i] == NULL)
            return my_null_error("Failed to load sprite tiles for editor");
    }
    return dest;
}

void init_default_map(wd_game_t *game)
{
    game->map->map = my_memset(sizeof(int *) * (MAP_SIZE_X + 1), NULL);
    for (int i = 0; i < MAP_SIZE_X; i++) {
        game->map->map[i] = my_memset(sizeof(int) * (MAP_SIZE_Y + 1), NULL);
        for (int j = 0; j < MAP_SIZE_Y; j++)
            game->map->map[i][j] = 0;
    }
    game->map->map_text = my_memset(sizeof(int *) * (MAP_SIZE_X), NULL);
    for (int i = 0; i < MAP_SIZE_X - 1; i++) {
        game->map->map_text[i] = my_memset(sizeof(int) * (MAP_SIZE_Y), NULL);
        for (int j = 0; j < MAP_SIZE_Y - 1; j++)
            game->map->map_text[i][j] = 3;
    }
    game->map->width = MAP_SIZE_X;
    game->map->height = MAP_SIZE_Y;
}

wd_game_t *init_map(wd_game_t *game)
{
    game->map = my_memset(sizeof(wd_map_t), NULL);

    init_default_map(game);
    if (game->map == NULL || game->map->map == NULL)
        return NULL;
    game->map->fov = 30;
    game->dir = NO;
    game->map->type = SKIN;
    game->map->spritetype = FIRE_SPRITE;
    game->map->points = my_memset(sizeof(sfVector2f *) *
            (game->map->width + 1), NULL);
    for (int i = 0; i < game->map->width; ++i)
        game->map->points[i] = my_memset(sizeof(sfVector2f) *
                (game->map->height + 1), NULL);
    game->map->selected = (sfVector2i){.x = -1, .y = -1};
    return game;
}

wd_game_t *init_editor_game(sfRenderWindow *win, sfVideoMode mode)
{
    wd_game_t *game = my_memset(sizeof(wd_game_t), NULL);

    if ((game = init_map(game)) == NULL)
        return NULL;
    game->win = win;
    game->angle = (wd_vector2d_t){.x = 250, .y = 100};
    game->matrix.base_matrix = init_matrix(0);
    game->matrix.rotx_matrix = init_matrix(1);
    game->matrix.roty_matrix = init_matrix(1);
    rotate_matrix_x(game, game->angle.x);
    rotate_matrix_y(game, game->angle.y);
    game->matrix.proj_matrix = init_matrix(1);
    update_proj_matrix(game);
    game->matrix.end_matrix = init_matrix(1);
    calc_end_matrix(game);
    game->textures = init_all_textures_editor();
    if (game->textures == NULL)
        return NULL;
    game->mode = mode;
    return game;
}

int free_game(wd_game_t *game)
{
    free_matrix(game->matrix.base_matrix);
    free_matrix(game->matrix.rotx_matrix);
    free_matrix(game->matrix.roty_matrix);
    free_matrix(game->matrix.proj_matrix);
    free_matrix(game->matrix.end_matrix);
    for (int i = 0; i < NB_SPRITES; ++i) {
        sfTexture_destroy(game->textures[i]);
    }
    free(game->textures);
    free(game);
    return 0;
}

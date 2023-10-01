/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** settings_text
*/

#include "rpg.h"
#include <stdlib.h>

every_text_t *init_text_settings(void)
{
    every_text_t *text = malloc(sizeof(every_text_t));

    text->fps_text = create_text("0", 70, (sfVector2f){1825, 5}, sfRed);
    text->set_fps = create_text("30", 80, (sfVector2f){600, 300}, sfWhite);
    text->fps = create_text("FPS", 100, (sfVector2f){575, 200}, sfWhite);
    text->volume = create_text("VOLUME", 100, (sfVector2f){1110, 200},
    sfWhite);
    text->volume_nb = create_text("100", 80, (sfVector2f){1200, 300}, sfWhite);
    text->resolution = create_text("RESOLUTION", 100, (sfVector2f){750, 520},
    sfWhite);
    text->res_val = create_text("1920x1080", 80, (sfVector2f){842, 690},
    sfWhite);
    return text;
}

void draw_text_settings(game_t *game)
{
    draw_text(game->text->set_fps, game);
    draw_text(game->text->fps, game);
    draw_text(game->text->volume, game);
    draw_text(game->text->volume_nb, game);
    draw_text(game->text->resolution, game);
    draw_text(game->text->res_val, game);
}

void destroy_text_settings_menu(every_text_t *text)
{
    delete_text(text->set_fps);
    delete_text(text->fps);
    delete_text(text->volume);
    delete_text(text->volume_nb);
    delete_text(text->resolution);
    delete_text(text->res_val);
    free(text);
}

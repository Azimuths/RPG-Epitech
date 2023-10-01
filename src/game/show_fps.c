/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** show_fps
*/

#include "rpg.h"

void draw_fps(game_t *game)
{
    draw_text(game->text->fps_text, game);
}

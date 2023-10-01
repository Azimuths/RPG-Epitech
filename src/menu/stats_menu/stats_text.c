/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** quest_text
*/

#include "macro.h"
#include "rpg.h"
#include <stdlib.h>

every_text_t *init_text_stats(void)
{
    every_text_t *text = malloc(sizeof(every_text_t));

    text->stats_health = create_text("Carlos' life :", 50,
    (sfVector2f){700, 440}, sfWhite);
    text->stats_speed = create_text("Carlos' speed :",
    50, (sfVector2f){700, 660}, sfWhite);
    text->stats_dmg = create_text("Carlos' attack :",
    50, (sfVector2f){700, 250}, sfWhite);
    text->atk_point = create_text("",
    50, (sfVector2f){700, 300}, sfWhite);
    text->health_point = create_text("",
    50, (sfVector2f){700, 490}, sfWhite);
    text->speed_point = create_text("",
    50, (sfVector2f){700, 710}, sfWhite);
    return text;
}

void draw_text_stats(game_t *game)
{
    draw_text(game->stats_text->stats_dmg, game);
    draw_text(game->stats_text->stats_health, game);
    draw_text(game->stats_text->stats_speed, game);
    draw_text(game->stats_text->atk_point, game);
    draw_text(game->stats_text->health_point, game);
    draw_text(game->stats_text->speed_point, game);
}

void destroy_text_stats_menu(every_text_t *text)
{
    delete_text(text->stats_dmg);
    delete_text(text->stats_health);
    delete_text(text->stats_speed);
    delete_text(text->atk_point);
    delete_text(text->health_point);
    delete_text(text->speed_point);
    free(text);
}

/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** update_stats_points
*/

#include "rpg.h"
#include "player.h"
#include <stdlib.h>

int update_speed_point(game_t *game)
{
    char *str = int_to_str(game->player->spd);

    sfText_setString(game->stats_text->speed_point->text, str);
    free(str);
    return 0;
}

int update_health_point(game_t *game)
{
    char *str = int_to_str(game->player->max_hp);

    sfText_setString(game->stats_text->health_point->text, str);
    free(str);
    return 0;
}

int update_attack_point(game_t *game)
{
    char *str = int_to_str(game->player->dmg);

    sfText_setString(game->stats_text->atk_point->text, str);
    free(str);
    return 0;
}

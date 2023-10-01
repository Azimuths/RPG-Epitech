/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** update_skill_point
*/

#include "rpg.h"
#include <stdlib.h>

int update_skill_point(game_t *game)
{
    char *str = int_to_str(game->skill_points);

    sfText_setString(game->skill_text->skill_nb->text, str);
    free(str);
    return 0;
}

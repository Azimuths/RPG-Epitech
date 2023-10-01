/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** my_rpg
*/

#include "rpg.h"
#include <stdlib.h>

int my_rpg(void)
{
    game_t *game = init_game();

    if (game == NULL)
        return 84;
    srand((size_t)game);
    if (select_menu(game))
        return 84;
    destroy_game(game);
    return 0;
}

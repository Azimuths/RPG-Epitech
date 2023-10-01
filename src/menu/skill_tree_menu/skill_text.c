/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** skill_text
*/

#include "rpg.h"
#include <stdlib.h>

every_text_t *init_text_skill(void)
{
    every_text_t *text = malloc(sizeof(every_text_t));

    text->skill = create_text("", 35, (sfVector2f){830, 850}, sfWhite);
    text->skill_points = create_text("YOU HAVE :",
    35, (sfVector2f){1650, 320}, sfWhite);
    text->skill_nb = create_text("",
    35, (sfVector2f){1690, 385}, sfWhite);
    return text;
}

void update_skill_text(game_t *game)
{
    char *skill_points = NULL;

    sfText_setString(game->skill_text->skill_nb->text, skill_points);
}

void draw_text_skill(game_t *game)
{
    draw_text(game->skill_text->skill, game);
    draw_text(game->skill_text->skill_points, game);
    draw_text(game->skill_text->skill_nb, game);
}

void destroy_text_skill_menu(every_text_t *text)
{
    delete_text(text->skill_points);
    delete_text(text->skill_nb);
    delete_text(text->skill);
    free(text);
}

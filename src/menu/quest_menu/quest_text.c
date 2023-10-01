/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** quest_text
*/

#include "macro.h"
#include "rpg.h"
#include "quest.h"
#include <stdlib.h>

every_text_t *init_text_quest(void)
{
    every_text_t *text = malloc(sizeof(every_text_t));

    text->quest_one = create_text(QUEST_ONE, 35, (sfVector2f){600, 270},
            sfWhite);
    text->quest_two = create_text(QUEST_TWO,
    35, (sfVector2f){600, 760}, sfWhite);
    text->quest_three = create_text(QUEST_THREE,
    35, (sfVector2f){600, 440}, sfWhite);
    text->quest_four = create_text(QUEST_FOUR,
    35, (sfVector2f){600, 580}, sfWhite);
    return text;
}

void draw_text_quest(game_t *game)
{
    if (game->list_quest->patrick_quest)
        draw_text(game->quest_text->quest_one, game);
    if (game->list_quest->tyler_quest)
        draw_text(game->quest_text->quest_two, game);
    if (game->list_quest->valerie_quest)
        draw_text(game->quest_text->quest_three, game);
    if (game->list_quest->denis_quest)
        draw_text(game->quest_text->quest_four, game);
}

void destroy_text_quest_menu(every_text_t *text)
{
    delete_text(text->quest_one);
    delete_text(text->quest_two);
    delete_text(text->quest_three);
    delete_text(text->quest_four);
    free(text);
}

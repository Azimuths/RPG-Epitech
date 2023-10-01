/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** pnj_quest_update
*/

#include "rpg.h"
#include "enemy.h"
#include "quest.h"
#include "macro.h"

int pnj_talks(game_t *game)
{
    sfBool out = sfFalse;
    while (!out) {
        sfRenderWindow_pollEvent(game->window, &game->event);
        if (sfKeyboard_isKeyPressed(sfKeyBackspace))
            out = sfTrue;
        animate_main_game(game);
        sfRenderWindow_drawSprite(game->window,
                game->all_obj->obj_pnj_talks->sprite, NULL);
        sfRenderWindow_drawText(game->window,
                game->text->text_pnj_talks->text, NULL);
        sfRenderWindow_display(game->window);
    }
    return 0;
}

int pnj_quest_update(game_t *game, enemy_t *enemy)
{
    static int prev_hp = 1000000;
    static sfBool first_time = sfTrue;

    if (prev_hp != enemy->hp && first_time == sfTrue) {
        first_time = sfFalse;
        game->list_quest->valerie_quest = sfTrue;
        game->list_quest->tyler_quest = sfTrue;
        game->list_quest->denis_quest = sfTrue;
        game->list_quest->patrick_quest = sfTrue;
        pnj_talks(game);
        prev_hp = enemy->hp;
    }
    return 0;
}

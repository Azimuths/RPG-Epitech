/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_pnj_talks_obj
*/

#include "macro.h"
#include "rpg.h"
#include "SFML/Graphics.h"

int init_pnj_talks_onj(game_t *game)
{
    game->all_obj->obj_pnj_talks = create_object(UX_LARGE_WIN,
((sfIntRect){0, 0, 438, 130}), ((sfVector2f){999, 500}), ((sfVector2f){3, 3}));
    game->text->text_pnj_talks = create_text("It's dangerous to go alone!\n"
"That's why you should reunite the 4 primordials ducks,"
"\nyour life has less "
"worth than me!\n"
        "Now we get out aventuring!",
            30, ((sfVector2f){1000, 470}), sfWhite);
    if (game->all_obj->obj_pnj_talks == NULL || game->text->text_pnj_talks
    == NULL)
        return 84;
    sfText_setScale(game->text->text_pnj_talks->text,
            ((sfVector2f){1.5, 1.5}));
    sprite_set_center(game->all_obj->obj_pnj_talks->sprite);
    text_set_center(game->text->text_pnj_talks->text);
    return 0;
}

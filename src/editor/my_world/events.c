/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-maxime.senard
** File description:
** events
*/

#include "editor.h"
#include "rpg.h"

void on_input(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyQ || event.key.code == sfKeyD ||
        event.key.code == sfKeyZ || event.key.code == sfKeyS)
        change_angle(game->editor, event);
    if (event.key.code == sfKeyA || event.key.code == sfKeyE)
        change_zoom(game->editor, event);
    if (event.type == sfEvtClosed)
        game->screen = MAIN_MENU;
    if (sfKeyboard_isKeyPressed(sfKeyW))
        game->editor->map->spritetype = FIRE_SPRITE;
    if (sfKeyboard_isKeyPressed(sfKeyX))
        game->editor->map->spritetype = SWAMP_SPRITE;
    if (sfKeyboard_isKeyPressed(sfKeyC))
        game->editor->map->spritetype = ICE_SPRITE;
    if (sfKeyboard_isKeyPressed(sfKeyV))
        game->editor->map->spritetype = GRASS_SPRITE;
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        game->screen = MAIN_MENU;
}

void analyse_win_events(game_t *game, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        game->screen = EXIT;
    }
    if (event.type == sfEvtKeyPressed)
        on_input(game, event);
}

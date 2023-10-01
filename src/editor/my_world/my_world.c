/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** my_world
*/

#include "editor.h"
#include "rpg.h"

void update_status(wd_game_t *game)
{
    if (!sfMouse_isButtonPressed(sfMouseLeft)) {
        game->map->selected = get_selected_circle(game, 50 - \
        (game->map->fov / 10));
    } else {
        if (game->map->type == LEVEL)
            level_tool(game);
        if (game->map->type == UNIFORM)
            union_tool(game);
        if (game->map->type == SKIN)
            skin_tool(game);
    }
    update_dir(game);
}

int editor(game_t *game)
{
    sfEvent event;

    if (game->editor == NULL)
        return 84;
    while (game->screen == EDITOR) {
        update_status(game->editor);
        sfRenderWindow_clear(game->editor->win, sfBlack);
        while (sfRenderWindow_pollEvent(game->editor->win, &(game->event))) {
            analyse_win_events(game, game->event);
        }
        render_map(game->editor);
        sfRenderWindow_display(game->editor->win);
    }
    return 0;
}

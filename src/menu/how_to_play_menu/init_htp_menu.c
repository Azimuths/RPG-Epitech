/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** menu_htp
*/

#include "rpg.h"

#include "macro.h"
#include <stdlib.h>

every_object_t *init_htp_menu(void)
{
    every_object_t *obj = (every_object_t *)malloc(sizeof(every_object_t));

    if (!(obj->htp_bg = create_object(HTP_BG, ((sfIntRect){0, 0, 965, 623}),
((sfVector2f){950, 570}), ((sfVector2f){1.2, 1.2}))))
        return NULL;
    if (!(obj->button_menu = create_object(BUTTON_MENU, ((sfIntRect)
        {0, 0, 500, 350}), ((sfVector2f){100, 100}),
        ((sfVector2f){0.4, 0.4}))))
        return NULL;
    sprite_set_center(obj->htp_bg->sprite);
    sprite_set_center(obj->button_menu->sprite);
    if (init_button_htp_menu(obj))
        return NULL;
    return obj;
}

void draw_htp_menu(game_t *game)
{
    draw_object(game->htp->htp_bg, game);
    draw_object(game->htp->button_menu, game);
}

void destroy_htp_menu(every_object_t *obj)
{
    delete_object(obj->htp_bg);
    delete_object(obj->button_menu);
    free(obj);
}

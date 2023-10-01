/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** init_main_menu
*/

#include "rpg.h"
#include "macro.h"
#include <stdlib.h>

int init_main_menu_second(every_object_t *obj)
{
    if (!(obj->button_editor = create_object(BUTTON_EDITOR, ((sfIntRect)
        {0, 0, 500, 350}), ((sfVector2f){250, 100}),
        ((sfVector2f){0.4, 0.4}))))
        return 84;
    if (!(obj->button_play = create_object(BUTTON_PLAY,
    ((sfIntRect){0, 0, 236, 100}), ((sfVector2f){960, 560}),
    ((sfVector2f){1, 1}))))
        return 84;
    if (!(obj->title = create_object(TITLE, ((sfIntRect){0, 0, 549, 148}),
    ((sfVector2f){940, 260}), ((sfVector2f){1.3, 1.3}))))
        return 84;
    sprite_set_center(obj->button_editor->sprite);
    sprite_set_center(obj->button_play->sprite);
    sprite_set_center(obj->title->sprite);
    return 0;
}

int init_main_menu_third(every_object_t *obj)
{
    if (!(obj->button_exit = create_object(BUTTON_EXIT,
            ((sfIntRect) {0, 0, 236, 100}), ((sfVector2f) {960, 740}),
            ((sfVector2f) {1, 1}))))
        return 84;
    if (!(obj->button_option = create_object(BUTTON_OPTION,
            ((sfIntRect) {0, 0, 500, 350}), ((sfVector2f) {100, 100}),
            ((sfVector2f) {0.4, 0.4}))))
        return 84;
    if (!(obj->button_htp = create_object(BUTTON_HTP,
            ((sfIntRect) {0, 0, 500, 350}), ((sfVector2f) {1825, 100}),
            ((sfVector2f) {0.4, 0.4}))))
        return 84;
    if (!(obj->title = create_object(TITLE, ((sfIntRect) {0, 0, 549, 148}),
            ((sfVector2f) {940, 260}), ((sfVector2f) {1.3, 1.3}))))
        return 84;
    return 0;
}

every_object_t *init_main_menu(void)
{
    every_object_t *obj = (every_object_t *)malloc(sizeof(every_object_t));

    if (init_main_menu_third(obj) == 84)
        return NULL;
    if (init_main_menu_second(obj) == 84)
        return NULL;
    init_button_main_menu(obj);
    sprite_set_center(obj->button_htp->sprite);
    sprite_set_center(obj->button_option->sprite);
    sprite_set_center(obj->button_exit->sprite);
    return obj;
}

void draw_main_menu(game_t *game)
{
    draw_object(game->all_obj->button_htp, game);
    draw_object(game->all_obj->button_editor, game);
    draw_object(game->all_obj->button_option, game);
    draw_object(game->all_obj->button_play, game);
    draw_object(game->all_obj->button_exit, game);
    draw_object(game->all_obj->title, game);
}

void destroy_main_menu(every_object_t *obj)
{
    delete_object(obj->button_exit);
    delete_object(obj->button_editor);
    delete_object(obj->button_play);
    delete_object(obj->button_option);
    delete_object(obj->button_htp);
    delete_object(obj->title);
    free(obj);
}

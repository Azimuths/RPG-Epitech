/*
** EPITECH PROJECT, 2022
** my_world
** File description:
** init_text_state
*/

#include "editor.h"

sfRenderStates *init_text_state(wd_game_t *game, wd_spritetype_t type)
{
    sfRenderStates *states = my_memset(sizeof(sfRenderStates), NULL);

    if (states == NULL) {
        return NULL;
    }
    states->shader = sfShader_createFromMemory(NULL, NULL, NULL);
    states->blendMode = sfBlendAlpha;
    states->transform = sfTransform_Identity;
    states->texture = game->textures[type];
    return states;
}

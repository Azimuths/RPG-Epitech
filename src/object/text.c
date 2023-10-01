/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-diego1.marliere-calvo
** File description:
** text
*/

#include "rpg.h"
#include "macro.h"
#include "stdio.h"
#include "stdlib.h"

text_t *create_text(char *txt, int size, sfVector2f pos, sfColor color)
{
    text_t *text = malloc(sizeof(text_t));

    text->color = color;
    text->size = size;
    text->font = sfFont_createFromFile(FONT_1);
    text->text = sfText_create();
    text->pos = pos;
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, text->size);
    sfText_setPosition(text->text, text->pos);
    sfText_setString(text->text, txt);
    sfText_setColor(text->text, text->color);
    return text;
}

void draw_text(text_t *text, game_t *game)
{
    sfRenderWindow_drawText(game->window, text->text, NULL);
}

void delete_text(text_t *text)
{
    if (text->text)
        sfText_destroy(text->text);
    if (text->font)
        sfFont_destroy(text->font);
    free(text);
}

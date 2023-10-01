/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_game
*/

#include "particle.h"
#include "skill_tree.h"
#include "projectile.h"
#include "enemy.h"
#include "player.h"
#include "my.h"
#include "my_linked_list.h"
#include "sounds.h"
#include "config.h"
#include "inventory.h"
#include "editor.h"
#include <SFML/Graphics/View.h>
#include "quest.h"

static void init_game_second(game_t *game)
{
    game->quest_text = init_text_quest();
    game->stats = init_stats_menu_second();
    game->quest = init_quest_menu_second();
    game->skill_text = init_text_skill();
    game->skill = init_skill_menu_second();
    game->pause_settings = init_pause_settings_menu_second();
    game->htp = init_htp_menu();
    game->text = init_text_settings();
    game->all_obj = init_main_menu();
    game->pause = init_pause_menu();
    game->settings = init_settings_menu_second();
    game->inventory = init_inventory();
    game->clock_game = sfClock_create();
    game->clock_anim = sfClock_create();
    game->textures = init_all_texture(game);
    game->end_screen = init_end_screen();
    game->player = init_player(game->config->skin);
    game->game_view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    game->editor = init_editor_game(game->window, game->mode);
    game->stats_text = init_text_stats();
}

static void init_game_third(game_t *game)
{
    game->volume = 100;
    game->win_size = 1;
    game->screen = MAIN_MENU;
    game->inventory->contents[0] = WEAPON_SWORD;
    game->player->pos = ((sfVector2f){500, 500});
    if (map_init(game))
        game->map = NULL;
}

static int init_game_if(game_t *game)
{
    if (game->all_obj == NULL || game->pause == NULL ||
game->settings == NULL || game->inventory == NULL ||
game->clock_game == NULL || game->clock_anim == NULL ||
game->textures == NULL || game->player == NULL || game->game_view == NULL
|| game->skill == NULL || game->stats == NULL || game->htp == NULL ||
game->quest == NULL || game->settings == NULL || game->editor == NULL ||
game->pause_settings == NULL || game->end_screen == NULL)
        return 84;
    return 0;
}

game_t *init_game(void)
{
    game_t *game = my_memset(sizeof(game_t) * 1, NULL);

    game->config = load_config();
    if (game->config == NULL)
        return NULL;
    if (open_window(game) == 84)
        return NULL;
    init_game_second(game);
    game->list_quest = my_memset(sizeof(quest_t), NULL);
    game->skill_tree = my_memset(sizeof(skill_tree_t), NULL);
    if (init_game_if(game) == 84)
        return NULL;
    init_game_third(game);
    if (init_sounds(game) == 84)
        return NULL;
    if (game->map == NULL || init_pnj_talks_onj(game) == 84)
        return NULL;
    return game;
}

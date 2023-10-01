/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** fire_spell_second_wave
*/

#include "SFML/Graphics.h"
#include "projectile.h"
#include "particle.h"
#include "enemy.h"
#include "my.h"
#include "projectile.h"
#include "my_linked_list.h"
#include <stdlib.h>

void fire_spell_second_spell(game_t *game, projectile_t *proj)
{
    sfVector2f spd = ((sfVector2f){-30, -15});

    if (proj->lifetime != 50)
        return;
    spd = ((sfVector2f) {-35, -15});
    for (int i = 0; i < 10; ++i) {
        spd.y += 3;
        spd.x = -30 + (fabsolute(spd.y) / 3);
        for (int j = 0; j < 6; ++j)
            add_node(create_fire_skull_spell_projectile(game, spd),
                    &(game->enemy_proj));
    }
}
